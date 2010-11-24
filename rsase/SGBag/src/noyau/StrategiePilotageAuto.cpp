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
    mettreAJourChemin();
}

StrategiePilotageAuto::StrategiePilotageAuto(const StrategiePilotage& modele) :
        StrategiePilotage(modele)
{
    mettreAJourChemin();
}

void StrategiePilotageAuto::calculerNouveauChemin()
{
    if (_bagage != 0)
    {
        _chemin = _bagage->objectifFinal()
                  ->trouverChemin(_tronconActuel->noeudFin());
    }
    else
    {
        _chemin = _tapisAssocie->trouverChemin(_tronconActuel->noeudFin());
    }
}
