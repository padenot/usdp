#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Noeud.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::troncon;

VueTroncon::VueTroncon(FenetrePrincipale& fenetrePrincipale, Troncon& troncon):
        VueElement(fenetrePrincipale),
        _troncon(troncon)
{
    setZValue(zIndex);
}


void VueTroncon::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
}

void VueTroncon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter,0,0);
    painter->setPen(Qt::black);
    painter->drawLine(_troncon.noeudDebut()->position(), _troncon.noeudFin()->position());
}

QRectF VueTroncon::boundingRect() const
{
    return rect;
}
