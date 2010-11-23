#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"

using namespace vue_config::bagage;

QSvgRenderer *VueBagage::_renderer = new QSvgRenderer(bagageSimple);

VueBagage::VueBagage(FenetrePrincipale& fenetrePrincipale, Bagage &bagage):
        VueElement(fenetrePrincipale,rect),
        _image(new QGraphicsSvgItem()),
        _bagage(bagage)
{
    _image->setSharedRenderer(_renderer);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    _image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    setZValue(zIndex);
}


void VueBagage::advance(int pas)
{
    if(pas == 0)
    {
            return;
    }
    setPos(_bagage.position());
}

void VueBagage::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter, 0, 0);

    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->renderer()->render(painter, rect);
}

Bagage* VueBagage::bagageAssocie()
{
    return &_bagage;
}
