#ifndef STRATEGIEPILOTAGEAUTO_H
#define STRATEGIEPILOTAGEAUTO_H

#include "StrategiePilotage.h"

class StrategiePilotageAuto : public StrategiePilotage
{
    public:
        StrategiePilotageAuto(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);

    protected :
        virtual void pilotageNoeudAtteint(qreal dt, Bagage *bagage);
};

#endif // STRATEGIEPILOTAGEAUTO_H
