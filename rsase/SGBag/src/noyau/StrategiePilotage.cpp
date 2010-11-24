#include <assert.h>

#include "StrategiePilotage.h"
#include "Chariot.h"
#include "Troncon.h"
#include "Toboggan.h"
#include "Tapis.h"
#include "Noeud.h"

const double StrategiePilotage::RAYON_ACTION_NOEUD = 1.0;
const double StrategiePilotage::RAYON_ACTION_TAPIS = 1.0;
const double StrategiePilotage::RAYON_ACTION_TOBOGGAN = 1.0;

StrategiePilotage::StrategiePilotage(Chariot& chariot, Troncon* tronconActuel,
                                     Tapis* tapisAssocie) :
        QObject(),
        _chariot(chariot),
        _bagage(0),
        _tronconActuel(tronconActuel),
        _tronconReserveSuivant(0),
        _tapisAssocie(tapisAssocie)
{
    _tronconActuel->occuper(&_chariot);
}

StrategiePilotage::StrategiePilotage(const StrategiePilotage& modele) :
        QObject(),
        _chariot(modele._chariot),
        _bagage(modele._bagage),
        _tronconActuel(modele._tronconActuel),
        _tronconReserveSuivant(modele._tronconReserveSuivant),
        _chemin(modele._chemin),
        _tapisAssocie(modele._tapisAssocie)
{
}

void StrategiePilotage::mettreAJourChemin()
{
    foreach (Troncon* troncon, _chemin)
    {
        troncon->disconnect(this,SLOT(mettreAJourChemin()));
    }

    calculerNouveauChemin();

    foreach (Troncon* troncon, _chemin)
    {
        connect(troncon,SIGNAL(etatModifie()),
                SLOT(mettreAJourChemin()));
    }
#ifdef DEBUG_ACHEMINEMENT
    QDebug debug(qDebug());
    debug << "Chemin de :" << _chariot << ":";
    foreach(Troncon* troncon, _chemin)
    {
        debug << *troncon;
    }
#endif
}

QPointF StrategiePilotage::piloter(Bagage* bagage)
{
    switch (situation(bagage))
    {
        case EN_CHEMIN :
            break;
        case BAGAGE_RECU :
            pilotageBagageRecu(bagage); break;
        case NOEUD_PROCHE :
            pilotageNoeudProche(); break;
        case NOEUD_ATTEINT :
            pilotageNoeudAtteint(); break;
        case TOBOGGAN_PROCHE :
            pilotageTobogganProche(); break;
        case TOBOGGAN_ATTEINT :
            pilotageTobogganAtteint(); break;
        case TAPIS_PROCHE :
            pilotageTapisProche(); break;
        case TAPIS_ATTEINT :
            pilotageTapisAtteint(); break;
    }

    return _tronconActuel->noeudFin()->position();
}

StrategiePilotage::Situation StrategiePilotage::situation(Bagage* bagageTransporte) const
{
    double distanceArret = _chariot.distanceArret();
    double distanceNoeud = QVector2D(_chariot.position() -
                     _tronconActuel->noeudFin()->position()).length();

    if (bagageTransporte != 0 && _bagage == 0)
    {
        return BAGAGE_RECU;
    }
    else if (distanceNoeud < RAYON_ACTION_NOEUD)
    {
        return NOEUD_ATTEINT;
    }
    else if ((distanceNoeud - distanceArret) < 0)
    {
        return NOEUD_PROCHE;
    }
    else if (_bagage != 0)
    {
        // Livraison de bagage en cours
        if (_bagage->objectifFinal()->estSupport(_tronconActuel))
        {
            double distance = QVector2D(_chariot.position() -
                             _tronconActuel->position()).length();
            if (distance < RAYON_ACTION_TOBOGGAN)
            {
                return TOBOGGAN_ATTEINT;
            }
            else if ((distance - distanceArret) < 0)
            {
                return TOBOGGAN_PROCHE;
            }
            else
            {
                return EN_CHEMIN;
            }
        }
        else
        {
            return EN_CHEMIN;
        }
    }
    else
    {
        // Retour au tapis en cours
        if (_tapisAssocie->estSupport(_tronconActuel))
        {
            double distance = QVector2D(_chariot.position() -
                              _tronconActuel->position()).length();
            if (distance < RAYON_ACTION_TAPIS)
            {
                return TAPIS_ATTEINT;
            }
            else if ((distance - distanceArret) < 0)
            {
                return TAPIS_PROCHE;
            }
            else
            {
                return EN_CHEMIN;
            }
        }
        else
        {
            return EN_CHEMIN;
        }
    }

}

void StrategiePilotage::pilotageBagageRecu(Bagage* bagageRecu)
{
#ifdef DEBUG_ACHEMINEMENT
//    qDebug() << _chariot << "avance";
#endif
    _bagage = bagageRecu;
    mettreAJourChemin();
    _chariot.accelerer();
}

void StrategiePilotage::pilotageNoeudProche()
{
    Troncon* nouveauTroncon = (_chemin.empty() ? 0 : _chemin.top());

    if (_tronconReserveSuivant != 0 && nouveauTroncon != _tronconReserveSuivant)
    {
        // On libère l'ancien "tronçon suivant", car on a
        // changé de destination
        _tronconReserveSuivant->liberer();
        _tronconReserveSuivant = 0;
    }

    if(nouveauTroncon != 0)
    {
        if (nouveauTroncon->occuper(&_chariot))
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "va bientôt passer sur" << *nouveauTroncon;
#endif
            _tronconReserveSuivant = nouveauTroncon;
            _chariot.accelerer();
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            _chariot.freiner();
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        _chariot.freiner();
    }
}

void StrategiePilotage::pilotageNoeudAtteint()
{
    Troncon* nouveauTroncon = (_chemin.empty() ? 0 : _chemin.top());

#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << _chariot << "sur" << *_tronconActuel << ", arrive sur" << *(_tronconActuel->noeudFin());
#endif

    if (_tronconReserveSuivant != 0 && nouveauTroncon != _tronconReserveSuivant)
    {
        // On libère l'ancien "tronçon suivant réservé", car on a
        // changé de destination au dernier moment
        _tronconReserveSuivant->liberer();
        _tronconReserveSuivant = 0;
    }

    if(nouveauTroncon != 0)
    {
        if (nouveauTroncon->occuper(&_chariot))
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "passe sur" << *nouveauTroncon;
#endif
            _tronconActuel->disconnect(this,SLOT(mettreAJourChemin()));
            _tronconActuel->liberer();
            _tronconActuel = nouveauTroncon;
            _tronconReserveSuivant = 0;
            _chemin.pop();

            _chariot.accelerer();
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
   //         qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            _chariot.freiner();
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        _chariot.freiner();
    }
}

void StrategiePilotage::pilotageTobogganProche()
{
    _chariot.freiner();
}

void StrategiePilotage::pilotageTobogganAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "donne son bagage à" << *_bagage->objectifFinal();
#endif
    _chariot.dechargerBagage(); // Renvoie le même pointeur que "bagage"
    _bagage->objectifFinal()->transfererBagage(_bagage);
    _bagage = 0;
    mettreAJourChemin();
    _chariot.accelerer();
}

void StrategiePilotage::pilotageTapisProche()
{
    _chariot.freiner();
}

void StrategiePilotage::pilotageTapisAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "a atteint" << *_tapisAssocie;
#endif
    _tapisAssocie->connecter(&_chariot);
}

