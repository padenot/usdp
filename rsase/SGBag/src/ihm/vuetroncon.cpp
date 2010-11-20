#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Noeud.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::troncon;

VueTroncon::VueTroncon(Troncon* troncon)
:image(new QSvgRenderer(etatNormal))
,troncon(troncon)
{
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
    painter->setBrush(Qt::black);
    painter->drawLine(troncon->noeudDebut()->position(), troncon->noeudFin()->position());
}

QRectF VueTroncon::boundingRect() const
{
    return rect;
}
