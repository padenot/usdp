#include "src/ihm/vuechariot.h"
#include "src/ihm/vueconfig.h"

#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <sys/time.h>
#include <unistd.h>

using namespace vue_config::chariot;

QSvgRenderer *VueChariot::_renderer = new QSvgRenderer(etatNormal);

VueChariot::VueChariot(FenetrePrincipale& fenetrePrincipale, Chariot &chariot):
        VueElement(fenetrePrincipale,rect),
        //_image(new QGraphicsSvgItem()),
        _chariot(chariot)
{
    //_image->setSharedRenderer(_renderer);
    setSharedRenderer(_renderer);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    //_image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setZValue(zIndex);
    setPos(chariot.position());
}

void VueChariot::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
        setPos(_chariot.position());
}

void VueChariot::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);

        //_image->renderer()->render(painter, rect);
        renderer()->render(painter, rect);
}

Chariot& VueChariot::chariot()
{
    return _chariot;
}
