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
        _image(new QGraphicsSvgItem()),
        _chariot(chariot)
{
    _image->setSharedRenderer(_renderer);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    _image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

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
    timeval val1;
    timeval val2;

    VueElement::paint(painter, 0, 0);

    gettimeofday(&val1, 0);

        _image->renderer()->render(painter, rect);

        /* Affichage de l'id du chariot
           Valable avec les nouveaux rendus.

        painter->setFont (font);
        QTransform matriceActuelle = _paintPixmap.transform();
        QTransform matriceTexte;
        matriceTexte.translate(dxTexte,dyTexte);
        matriceTexte.rotate(rotationTexte);
        painter->setTransform(matriceTexte);
        painter->setPen(couleurTexte);
        painter->drawText(QRectF(0,0,200,100), Qt::AlignLeft, QString::number(_chariot.id()));
        painter->setTransform(matriceActuelle);*/

    gettimeofday(&val2, 0);
}

Chariot& VueChariot::chariot()
{
    return _chariot;
}
