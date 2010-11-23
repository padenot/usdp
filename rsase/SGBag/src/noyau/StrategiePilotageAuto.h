#ifndef STRATEGIEPILOTAGEAUTO_H
#define STRATEGIEPILOTAGEAUTO_H

#include "StrategiePilotage.h"

class StrategiePilotageAuto : public StrategiePilotage
{
    public:
        StrategiePilotageAuto(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotageAuto(const StrategiePilotage& modele);

    protected :
        virtual void calculerNouveauChemin();
};

#endif // STRATEGIEPILOTAGEAUTO_H
