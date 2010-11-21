#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::toboggan;

VueToboggan::VueToboggan(FenetrePrincipale& fenetrePrincipale, Toboggan &toboggan):
        VueElement(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _toboggan(toboggan)
{
    QLineF ligneDirection(_toboggan.position(),_toboggan.pointConnexion());
    ligneDirection.setLength(ligneDirection.length()-vue_config::chariot::largeur/2);

    _rect = QRectF(0,largeur/2,ligneDirection.length(),largeur);

    qDebug() << ligneDirection << _rect;

    setZValue(zIndex);
    setPos(_toboggan.position());
    setTransformOriginPoint(0,largeur/2);
    setRotation(-ligneDirection.angle());
}

void VueToboggan::associerVol(Vol* vol)
{
    _toboggan.associerVol(vol);
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
    _image->render(painter, _rect);
}

QRectF VueToboggan::boundingRect() const
{
    return _rect;
}
