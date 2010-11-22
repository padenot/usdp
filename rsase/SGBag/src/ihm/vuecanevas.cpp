#include "vuecanevas.h"
#include "fenetreprincipale.h"

VueCanevas::VueCanevas(FenetrePrincipale& fenetrePrincipale) :
    _fenetrePrincipale(fenetrePrincipale)
{
    setFlags(QGraphicsItem::ItemIsSelectable);
}
