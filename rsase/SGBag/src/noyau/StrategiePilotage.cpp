#include "StrategiePilotage.h"
#include "Chariot.h"
#include "Troncon.h"
#include "Toboggan.h"
#include "Tapis.h"
#include "Noeud.h"

const double StrategiePilotage::RAYON_PROXIMITE_NOEUD = 0.5;
const double StrategiePilotage::RAYON_PROXIMITE_TAPIS = 0.5;
const double StrategiePilotage::RAYON_PROXIMITE_TOBOGGAN = 0.5;

StrategiePilotage::StrategiePilotage(Chariot& chariot, Troncon* tronconActuel,
                                     Tapis* tapisAssocie) :
        _chariot(chariot),
        _tronconActuel(tronconActuel),
        _tapisAssocie(tapisAssocie)
{
}

StrategiePilotage::StrategiePilotage(const StrategiePilotage& modele) :
        _chariot(modele._chariot),
        _tronconActuel(modele._tronconActuel),
        _tapisAssocie(modele._tapisAssocie)
{
}

void StrategiePilotage::piloter(double dt, Direction directionConseillee, Bagage* bagageTransporte)
{
    switch (situation(bagageTransporte))
    {
        case ARRET :                    pilotageArret(); break;
        case EN_CHEMIN :                pilotageEnChemin(dt); break;
        case NOEUD_ATTEINT :            pilotageNoeudAtteint(dt, directionConseillee, bagageTransporte); break;
        case TOBOGGAN_ATTEINT :         pilotageTobogganAtteint(bagageTransporte); break;
        case TAPIS_ATTEINT :            pilotageTapisAtteint(); break;
    }
}

StrategiePilotage::Situation StrategiePilotage::situation(Bagage* bagage) const
{
    if (!_chariot.estActif())
    {
        return ARRET;
    }
    else if (QVector2D(_chariot.position() - _tronconActuel->noeudFin()->position()).length()
        < RAYON_PROXIMITE_NOEUD)
    {
        // On est sur le noeud de fin du tronçon actuel
        return NOEUD_ATTEINT;
    }
    else if (bagage != 0)
    {
        // Livraison de bagage en cours
        if (bagage->objectifFinal()->estSupport(_tronconActuel)
            && QVector2D(_chariot.position() - _tronconActuel->position()).length()
            < RAYON_PROXIMITE_TOBOGGAN)
        {
            return TOBOGGAN_ATTEINT;
        }
        else
        {
            return EN_CHEMIN;
        }
    }
    else
    {
        // Retour au tapis en cours
        if (_tapisAssocie->estSupport(_tronconActuel)
            && QVector2D(_chariot.position() - _tronconActuel->position()).length()
            < RAYON_PROXIMITE_TAPIS)
        {
            return TAPIS_ATTEINT;
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
            return true;
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
#endif
            return false;
        }
    }
    else
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "est bloqué (pas de chemin jusqu'à sa destination)";
#endif
        return false;
    }
}

void StrategiePilotage::pilotageArret()
{
    // Rien à faire
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << _chariot << "à l'arrêt.";
#endif
}

void StrategiePilotage::pilotageEnChemin(double dt)
{
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << _chariot << "avance avec" << _bagage;
#endif
    _chariot.avancer(dt,_tronconActuel->noeudFin()->position());
}

void StrategiePilotage::pilotageTobogganAtteint(Bagage* bagage)
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "donne son bagage à" << *bagage->objectifFinal();
#endif
    _chariot.dechargerBagage(); // Renvoie le même pointeur que "bagage"
    bagage->objectifFinal()->transfererBagage(bagage);
}

void StrategiePilotage::pilotageTapisAtteint()
{
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "a atteint" << *_tapisAssocie;
#endif
    _tapisAssocie->connecter(&_chariot);
    _chariot.arreter();
}

