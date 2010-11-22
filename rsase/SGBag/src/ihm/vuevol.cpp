#include "fenetreprincipale.h"

#include "src/ihm/vuevol.h"
#include "src/ihm/vueconfig.h"

#include "src/noyau/Vol.h"
#include "src/noyau/Toboggan.h"

#include <QtSvg/QSvgRenderer>

using namespace vue_config::vol;

VueVol::VueVol(FenetrePrincipale& fenetrePrincipale, Vol& vol):
        VueCanevas(fenetrePrincipale),
        _image(new QSvgRenderer(etatNormal)),
        _vol (vol)
{
    //TODO
    setPos(_vol.tobogganAssocie()->position() +
           QVector2D(_vol.tobogganAssocie()->position()
                     - vol.tobogganAssocie()->pointConnexion())
           .normalized().toPointF()*ecartToboggan);
    //setPos(2*_vol.tobogganAssocie()->position() - -vol.tobogganAssocie()->pointConnexion());
    //setPos(0,0);
}

void VueVol::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    _image->render(painter, rect);
}

QRectF VueVol::boundingRect() const
{
    return rect;
}

Vol* VueVol::volAssocie()
{
    return &_vol;
}
