#ifndef STRATEGIEPILOTAGEMANUEL_H
#define STRATEGIEPILOTAGEMANUEL_H

#include "StrategiePilotage.h"

class StrategiePilotageManuel : public StrategiePilotage
{
    public:
        StrategiePilotageManuel(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);

    protected :
        virtual void pilotageNoeudAtteint(qreal dt, Bagage *bagage);
};

#endif // STRATEGIEPILOTAGEMANUEL_H
