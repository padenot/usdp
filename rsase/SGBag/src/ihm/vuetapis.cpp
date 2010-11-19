#include "src/ihm/vuetapis.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::tapis;

VueTapis::VueTapis():
        image(new QSvgRenderer(etatNormal))
{
}


void VueTapis::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
        setPos(x()+1,y()+1);
}

void VueTapis::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    image->render(painter, rect);
}

QRectF VueTapis::boundingRect() const
{
    return rect;
}
