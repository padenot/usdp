#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"

using namespace vue_config::bagage;

QSvgRenderer *VueBagage::_renderer = new QSvgRenderer(bagageSimple);

VueBagage::VueBagage(FenetrePrincipale& fenetrePrincipale, Bagage &bagage):
        VueElement(fenetrePrincipale,rect),
        //_image(new QGraphicsSvgItem()),
        _bagage(bagage)
{
    //_image->setSharedRenderer(_renderer);
    setSharedRenderer(_renderer);

    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    //_image->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

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

    renderer()->render(painter, boundingRect());

    /* Affichage de l'id du bagage
       Valable avec les nouveaux rendus.

    painter->setFont (font);
    QTransform matriceActuelle = painter->transform();
    QTransform matriceTexte = matriceActuelle;
    matriceTexte.translate(-0.5,-0.3);
    matriceTexte.rotate(rotationTexte);
    matriceTexte.scale(0.1,0.1);
    painter->setTransform(matriceTexte);
    painter->setPen(couleurTexte);
    painter->drawText(QRectF(0,0,200,100), Qt::AlignLeft, QString::number(_bagage.id()));
    painter->setTransform(matriceActuelle);//*/
}

Bagage* VueBagage::bagageAssocie()
{
    return &_bagage;
}
