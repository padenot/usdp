#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::chariot;

VueChariot::VueChariot(Chariot *ptrChariot):
        image(new QSvgRenderer(etatNormal)),
        chariot(ptrChariot)
{
}


void VueChariot::advance(int pas)
{
        if(!pas)
        {
                return;
        }

        //setPos(x()+1, y()+1);

        setPos(chariot->position());
        qDebug() << "position du chariot : " << chariot->position();
}

void VueChariot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    image->render(painter, rect);
}

QRectF VueChariot::boundingRect() const
{
    return rect;
}
