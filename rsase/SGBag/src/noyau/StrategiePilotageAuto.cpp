#include "StrategiePilotageAuto.h"
#include "Chariot.h"
#include "Toboggan.h"
#include "Troncon.h"
#include "Tapis.h"
#include "Noeud.h"

StrategiePilotageAuto::StrategiePilotageAuto(Chariot& chariot, Troncon* tronconActuel,
                                             Tapis* tapisAssocie) :
    StrategiePilotage(chariot,tronconActuel,tapisAssocie)
{
}

StrategiePilotageAuto::StrategiePilotageAuto(const StrategiePilotage& modele) :
        StrategiePilotage(modele)
{
}

void StrategiePilotageAuto::pilotageNoeudAtteint(double dt, Direction directionConseillee, Bagage* bagage)
{
    Troncon* nouveauTroncon = 0;

#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "sur" << *_tronconActuel << ", arrive sur" << *(_tronconActuel->noeudFin());
#endif

    if (bagage != 0)
    {
        nouveauTroncon = bagage->objectifFinal()->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }
    else
    {
        nouveauTroncon = _tapisAssocie->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }

    if (changerTroncon(nouveauTroncon))
    {
        pilotageEnChemin(dt);
    }
}
