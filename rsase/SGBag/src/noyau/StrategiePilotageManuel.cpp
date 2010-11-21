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

void StrategiePilotageManuel::pilotageNoeudAtteint(double dt,Direction directionConseillee,
                                                   Bagage* bagage)
{
    Troncon* nouveauTroncon = _tronconActuel->noeudFin()
                              ->trouverProchainTroncon(directionConseillee);

    if(nouveauTroncon != 0 && nouveauTroncon->occuper())
    {
        _tronconActuel->liberer();
        _tronconActuel = nouveauTroncon;
        pilotageEnChemin(dt);
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << _chariot << "passe sur" << *nouveauTroncon;
#endif
    }
#ifdef DEBUG_ACHEMINEMENT
    else
    {
        qDebug() << _chariot << "attend son tour pour passer sur" << *nouveauTroncon;
    }
#endif
}
