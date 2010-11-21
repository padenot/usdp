#include "StrategiePilotageManuel.h"
#include "Chariot.h"
#include "Troncon.h"
#include "Toboggan.h"
#include "Tapis.h"

StrategiePilotageManuel::StrategiePilotageManuel(Chariot& chariot, Troncon* tronconActuel,
                                                 Tapis* tapisAssocie) :
    StrategiePilotage(chariot,tronconActuel,tapisAssocie)
{
}


void StrategiePilotageManuel::pilotageNoeudAtteint(Bagage* bagage)
{
    // TODO
}
