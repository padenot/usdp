#include "vue.h"
#include "fenetreprincipale.h"

Vue::Vue(FenetrePrincipale& fenetrePrincipale) :
    _fenetrePrincipale(fenetrePrincipale)
{
    setFlags(QGraphicsItem::ItemIsSelectable);
}
