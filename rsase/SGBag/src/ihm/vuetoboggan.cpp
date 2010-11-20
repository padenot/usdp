#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::toboggan;

VueToboggan::VueToboggan(FenetrePrincipale* _fenetrePrincipale, Toboggan *toboggan):
        VueElement(_fenetrePrincipale),
        image(new QSvgRenderer(etatNormal)),
        toboggan(toboggan)
{
    setZValue(zIndex);
    setPos(toboggan->position());
}


void VueToboggan::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
}

void VueToboggan::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    image->render(painter, rect);
}

QRectF VueToboggan::boundingRect() const
{
    return rect;
}
