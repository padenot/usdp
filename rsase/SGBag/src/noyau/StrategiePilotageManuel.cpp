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

void StrategiePilotageManuel::pilotageNoeudProche(Direction directionConseillee,
                                                   Bagage* /*bagage*/)
{
    preparerChangementTroncon(_tronconActuel->noeudFin()
                   ->trouverProchainTroncon(directionConseillee));
}

void StrategiePilotageManuel::pilotageNoeudAtteint(Direction directionConseillee,
                                                   Bagage* /*bagage*/)
{
    changerTroncon(_tronconActuel->noeudFin()
                   ->trouverProchainTroncon(directionConseillee));
}
