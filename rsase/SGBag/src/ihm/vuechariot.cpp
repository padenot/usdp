#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::chariot;

VueChariot::VueChariot(FenetrePrincipale* fenetrePrincipale, Chariot *Chariot):
        VueElement(_fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _chariot(Chariot)
{
    setZValue(zIndex);
    setPos(_chariot->position());
}


void VueChariot::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
        setPos(_chariot->position());
}

void VueChariot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    _image->render(painter, rect);
}

QRectF VueChariot::boundingRect() const
{
    return rect;
}
