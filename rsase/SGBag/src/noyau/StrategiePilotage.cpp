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
        _chariot(chariot),
        _tronconActuel(tronconActuel),
        _tronconReserveSuivant(0),
        _tapisAssocie(tapisAssocie)
{
    _tronconActuel->occuper(&_chariot);
}

StrategiePilotage::StrategiePilotage(const StrategiePilotage& modele) :
        _chariot(modele._chariot),
        _tronconActuel(modele._tronconActuel),
        _tapisAssocie(modele._tapisAssocie)
{
}

QPointF StrategiePilotage::piloter(Direction directionConseillee, Bagage* bagageTransporte)
{
    switch (situation(bagageTransporte))
    {
        case EN_CHEMIN :
            pilotageEnChemin(); break;
        case NOEUD_PROCHE :
            pilotageNoeudProche(directionConseillee, bagageTransporte); break;
        case NOEUD_ATTEINT :
            pilotageNoeudAtteint(directionConseillee, bagageTransporte); break;
        case TOBOGGAN_PROCHE :
            pilotageTobogganProche(bagageTransporte); break;
        case TOBOGGAN_ATTEINT :
            pilotageTobogganAtteint(bagageTransporte); break;
        case TAPIS_PROCHE :
            pilotageTapisProche(); break;
        case TAPIS_ATTEINT :
            pilotageTapisAtteint(); break;
    }

    return _tronconActuel->noeudFin()->position();
}

StrategiePilotage::Situation StrategiePilotage::situation(Bagage* bagage) const
{
    // TODO : régler le problème de dépassement de noeud lorsque le prochain tronçon est
    // occupé induisant un blocage du chariot. Gestion différente des collisions ?
    double distanceArret = _chariot.distanceArret();
    double distanceNoeud = QVector2D(_chariot.position() -
                     _tronconActuel->noeudFin()->position()).length();

    if (distanceNoeud < RAYON_ACTION_NOEUD)
    {
        return NOEUD_ATTEINT;
    }
    else if ((distanceNoeud - distanceArret) < 0)
    {
        return NOEUD_PROCHE;
    }
    else if (bagage != 0)
    {
        // Livraison de bagage en cours
        if (bagage->objectifFinal()->estSupport(_tronconActuel))
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

void StrategiePilotage::changerTroncon(Troncon* nouveauTroncon)
{
    if (_tronconReserveSuivant != 0 && nouveauTroncon != _tronconReserveSuivant)
    {
        // On libère l'ancien "tronçon suivant", car on a
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
            _tronconActuel->liberer();
            _tronconActuel = nouveauTroncon;
            _tronconReserveSuivant = 0;

            _chariot.demarrer();
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
   //         qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            _chariot.arreter();
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        _chariot.arreter();
    }

    pilotageEnChemin();
}

void StrategiePilotage::preparerChangementTroncon(Troncon* nouveauTroncon)
{
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
            _chariot.demarrer();
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            _chariot.arreter();
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        _chariot.arreter();
    }

    pilotageEnChemin();
}

void StrategiePilotage::pilotageEnChemin()
{
#ifdef DEBUG_ACHEMINEMENT
//    qDebug() << _chariot << "avance";
#endif
}

void StrategiePilotage::pilotageTobogganProche(Bagage* bagage)
{
    _chariot.arreter();
}

void StrategiePilotage::pilotageTobogganAtteint(Bagage* bagage)
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "donne son bagage à" << *bagage->objectifFinal();
#endif
    _chariot.dechargerBagage(); // Renvoie le même pointeur que "bagage"
    bagage->objectifFinal()->transfererBagage(bagage);
    _chariot.demarrer();
}

void StrategiePilotage::pilotageTapisProche()
{
    _chariot.arreter();
}

void StrategiePilotage::pilotageTapisAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "a atteint" << *_tapisAssocie;
#endif
    _tapisAssocie->connecter(&_chariot);
}

