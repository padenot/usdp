#include "StrategiePilotage.h"
#include "Chariot.h"
#include "Troncon.h"
#include "Toboggan.h"
#include "Tapis.h"
#include "Noeud.h"

const qreal StrategiePilotage::RAYON_PROXIMITE_NOEUD = 0.1;
const qreal StrategiePilotage::RAYON_PROXIMITE_TAPIS = 0.1;
const qreal StrategiePilotage::RAYON_PROXIMITE_TOBOGGAN = 0.1;

StrategiePilotage::StrategiePilotage(Chariot& chariot, Troncon* tronconActuel,
                                     Tapis* tapisAssocie) :
        _chariot(chariot),
        _tronconActuel(tronconActuel),
        _tapisAssocie(tapisAssocie)
{
}

void StrategiePilotage::piloter(Bagage* bagageTransporte)
{
    switch (situation(bagageTransporte))
    {
        case ARRET :                    pilotageArret(); break;
        case EN_CHEMIN :                pilotageEnChemin(); break;
        case NOEUD_ATTEINT :            pilotageNoeudAtteint(bagageTransporte); break;
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

void StrategiePilotage::pilotageArret()
{
    // Rien à faire
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << _chariot << "à l'arrêt.";
#endif
}

void StrategiePilotage::pilotageEnChemin()
{
#ifdef DEBUG_ACHEMINEMENT
    //qDebug() << _chariot << "avance avec" << _bagage;
#endif
    _chariot.avancer(_tronconActuel->noeudFin()->position());
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

