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
        _tapisAssocie(tapisAssocie)
{
    _tronconActuel->occuper();
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
        //case ARRET :                    pilotageArret(); break;
        case EN_CHEMIN :                pilotageEnChemin(); break;
        case NOEUD_ATTEINT :            pilotageNoeudAtteint(directionConseillee, bagageTransporte); break;
        case TOBOGGAN_PROCHE :          pilotageTobogganProche(bagageTransporte); break;
        case TOBOGGAN_ATTEINT :         pilotageTobogganAtteint(bagageTransporte); break;
        case TAPIS_PROCHE :             pilotageTapisProche(); break;
        case TAPIS_ATTEINT :            pilotageTapisAtteint(); break;
    }

    return _tronconActuel->noeudFin()->position();
}

StrategiePilotage::Situation StrategiePilotage::situation(Bagage* bagage) const
{
    // TODO : régler le problème de dépassement de noeud lorsque le prochain tronçon est
    // occupé induisant un blocage du chariot. Gestion différente des collisions ?
    if (QVector2D(_chariot.position() - _tronconActuel->noeudFin()->position()).length()
        < RAYON_ACTION_NOEUD)
    {
        // On est sur le noeud de fin du tronçon actuel
        return NOEUD_ATTEINT;
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
            else if ((distance - _chariot.distanceArret()) < 0)
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
            else if ((distance - _chariot.distanceArret()) < 0)
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

bool StrategiePilotage::changerTroncon(Troncon* nouveauTroncon)
{
    if(nouveauTroncon != 0)
    {
        if (nouveauTroncon->occuper())
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "passe sur" << *nouveauTroncon;
#endif
            _tronconActuel->liberer();
            _tronconActuel = nouveauTroncon;
            _chariot.demarrer();
            return true;
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            _chariot.arreter();
            return false;
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        _chariot.arreter();
        return false;
    }
}

void StrategiePilotage::pilotageArret()
{
    // Rien à faire
#ifdef DEBUG_ACHEMINEMENT
//    qDebug() << _chariot << "à l'arrêt.";
#endif
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

