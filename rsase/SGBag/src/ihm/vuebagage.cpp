#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"
#include <QtSvg/QSvgRenderer>

using namespace vue_config::bagage;

VueBagage::VueBagage():
        image(new QSvgRenderer(etatNormal))
{
}


void VueBagage::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //bagage.getPos();
        setPos(x()+1,y()+1);
}

void VueBagage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    image->render(painter, rect);
    VueElement::paint(painter, 0, 0);
}

QRectF VueBagage::boundingRect() const
{
    return rect;
}
