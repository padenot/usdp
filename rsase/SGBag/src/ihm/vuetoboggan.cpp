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
    setZValue(zIndex);
    definirCoordonnees(_toboggan.position(),_toboggan.pointConnexion(),
                       largeur,vue_config::chariot::largeur);
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

    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->render(painter, _rect);
}
