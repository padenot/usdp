#ifndef STRATEGIEPILOTAGEMANUEL_H
#define STRATEGIEPILOTAGEMANUEL_H

#include "StrategiePilotage.h"

class StrategiePilotageManuel : public StrategiePilotage
{
    Q_OBJECT

    public:
        StrategiePilotageManuel(Chariot& chariot, Troncon* tronconActuel, Tapis* tapisAssocie);
        StrategiePilotageManuel(const StrategiePilotage& modele);

    protected :
        virtual void calculerNouveauChemin();
        virtual QPointF piloter (double dt, Bagage* bagageTransporte);
};

#endif // STRATEGIEPILOTAGEMANUEL_H
