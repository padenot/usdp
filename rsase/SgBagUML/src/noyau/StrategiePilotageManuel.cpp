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
    mettreAJourChemin();
}

StrategiePilotageManuel::StrategiePilotageManuel(const StrategiePilotage& modele) :
        StrategiePilotage(modele)
{
    mettreAJourChemin();
}

void StrategiePilotageManuel::calculerNouveauChemin()
{
    _chemin = _tronconActuel->noeudFin()
        ->trouverChemin(_chariot.directionConseillee());
}

void StrategiePilotageManuel::pilotageNoeudAtteint()
{
    StrategiePilotage::pilotageNoeudAtteint();
    mettreAJourChemin(); // Opération peu gourmande, on ne
                        // fait que demander le tronçon
                        // de gauche/droite
}
