#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>
#include <QVector2D>

using namespace vue_config::toboggan;

QSvgRenderer *VueToboggan::_renderer = new QSvgRenderer(etatNormal);

VueToboggan::VueToboggan(FenetrePrincipale& fenetrePrincipale, Toboggan &toboggan):
        VueElement(fenetrePrincipale),
        _image(new QGraphicsSvgItem()),
        _toboggan(toboggan)
{
    _image->setSharedRenderer(_renderer);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    _image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setZValue(zIndex);
    definirCoordonnees(_toboggan.position(),_toboggan.pointConnexion(),
                       largeur,-vue_config::chariot::largeur/2);

    _image->renderer()->setFramesPerSecond(30);
}

void VueToboggan::associerVol(Vol* vol)
{
    _toboggan.associerVol(vol);
#ifdef DEBUG_ACHEMINEMENT
    qDebug() << _toboggan;
#endif
    vol->associer(&_toboggan);
}



void VueToboggan::advance(int pas)
{
        if(pas == 0)
        {
                return;
        }
}

void VueToboggan::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);
    //painter->drawPixmap(_rect, _pixmap, QRectF(0, 0, 200, 200));
    _image->renderer()->render(painter, _rect);
}

Toboggan& VueToboggan::toboggan() const
{
    return _toboggan;
}
