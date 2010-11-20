#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::toboggan;

VueToboggan::VueToboggan():
        image(new QSvgRenderer(etatNormal))
{
}


void VueToboggan::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
        setPos(x()+1,y()+1);
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
