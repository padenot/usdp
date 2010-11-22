#include "StrategiePilotageManuel.h"
#include "Chariot.h"
#include "Troncon.h"
#include "Toboggan.h"
#include "Tapis.h"
#include "Noeud.h"

StrategiePilotageManuel::StrategiePilotageManuel(Chariot& chariot, Troncon* tronconActuel,
                                                 Tapis* tapisAssocie) :
    StrategiePilotage(chariot,tronconActuel,tapisAssocie)
{
}

StrategiePilotageManuel::StrategiePilotageManuel(const StrategiePilotage& modele) :
        StrategiePilotage(modele)
{
}

void StrategiePilotageManuel::pilotageNoeudAtteint(double dt,Direction directionConseillee,
                                                   Bagage* bagage)
{
    if (changerTroncon(_tronconActuel->noeudFin()
                   ->trouverProchainTroncon(directionConseillee)))
    {
        pilotageEnChemin(dt);
    }
}
