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
}

void StrategiePilotageAuto::pilotageNoeudAtteint(Bagage* bagage)
{
    Troncon* nouveauTroncon = 0;

#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _chariot << "sur" << *_tronconActuel << ", arrive sur" << *(_tronconActuel->noeudFin());
#endif

    if (bagage != 0)
    {
        nouveauTroncon = bagage->objectifFinal()->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }
    else
    {
        nouveauTroncon = _tapisAssocie->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }

    if(nouveauTroncon != 0 && nouveauTroncon->occuper())
    {
        _tronconActuel->liberer();
        _tronconActuel = nouveauTroncon;
        pilotageEnChemin();
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
