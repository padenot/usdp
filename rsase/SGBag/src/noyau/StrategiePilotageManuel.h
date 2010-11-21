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
                qreal dt, Direction directionConseillee, Bagage *bagage);
};

#endif // STRATEGIEPILOTAGEMANUEL_H
