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
    VueElement::paint(painter, 0, 0);
    image->render(painter, rect);
}

void VueTapis::ajoutBagage()
{
    //VueGlobale.ajoutBagage(tapis);
}

QRectF VueTapis::boundingRect() const
{
    return rect;
}
