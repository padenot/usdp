#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::chariot;

VueChariot::VueChariot(FenetrePrincipale* _fenetrePrincipale, Chariot *ptrChariot):
        VueElement(_fenetrePrincipale),
        image(new QSvgRenderer(etatNormal)),
        chariot(ptrChariot)
{
    setZValue(zIndex);
    setPos(chariot->position());
}


void VueChariot::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
        setPos(chariot->position());
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
