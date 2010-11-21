#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::toboggan;

VueToboggan::VueToboggan(FenetrePrincipale& fenetrePrincipale, Toboggan &toboggan):
        VueElement(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _toboggan(toboggan)
{
    setZValue(zIndex);
    setPos(toboggan.position());
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
    _image->render(painter, rect);
}

QRectF VueToboggan::boundingRect() const
{
    return rect;
}
