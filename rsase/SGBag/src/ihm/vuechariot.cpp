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
        if(pas == 0)
        {
                return;
        }

        //setPos(x()+1, y()+1);
        setPos(chariot->position());
        qDebug() << "position de : vue " << (void*)chariot << " = " << chariot->position();
}

void VueChariot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    image->render(painter, rect);
}

QRectF VueChariot::boundingRect() const
{
    return rect;
}
