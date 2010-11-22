#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>
#include <QVector2D>

using namespace vue_config::toboggan;

VueToboggan::VueToboggan(FenetrePrincipale& fenetrePrincipale, Toboggan &toboggan):
        VueElement(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _toboggan(toboggan)
{
    QLineF direction = QLineF(QPoint(0, 0), _toboggan.pointConnexion() - _toboggan.position());
    QVector2D vecteurDir = QVector2D(_toboggan.pointConnexion() - _toboggan.position());

    _rect = QRectF(0,-largeur/2,direction.length(), largeur);

    setZValue(zIndex);
    setPos(_toboggan.position() - (vecteurDir.normalized().toPointF() * (vue_config::chariot::largeur/2)));
    setRotation(-direction.angle());
}

void VueToboggan::associerVol(Vol* vol)
{
    _toboggan.associerVol(vol);
    qDebug() << _toboggan;
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

    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->render(painter, _rect);
}

QRectF VueToboggan::boundingRect() const
{
    return _rect;
}
