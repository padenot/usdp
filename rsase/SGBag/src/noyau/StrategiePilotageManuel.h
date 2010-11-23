#ifndef STRATEGIEPILOTAGEMANUEL_H
#define STRATEGIEPILOTAGEMANUEL_H

#include "StrategiePilotage.h"

class StrategiePilotageManuel : public StrategiePilotage
{
    public:
        StrategiePilotageManuel(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotageManuel(const StrategiePilotage& modele);

    protected :
        virtual void pilotageNoeudAtteint(
                Direction directionConseillee, Bagage *bagage);
        virtual void pilotageNoeudProche(
                Direction directionConseillee, Bagage* bagage);
};

#endif // STRATEGIEPILOTAGEMANUEL_H
