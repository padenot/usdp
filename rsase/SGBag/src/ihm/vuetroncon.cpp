#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::troncon;

VueTroncon::VueTroncon():
        image(new QSvgRenderer(etatNormal))
{
}


void VueTroncon::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
        setPos(x()+1,y()+1);
}

void VueTroncon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    image->render(painter, rect);
}

QRectF VueTroncon::boundingRect() const
{
    return rect;
}
