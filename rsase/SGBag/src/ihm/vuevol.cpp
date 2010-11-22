#include <QtSvg/QSvgRenderer>

#include "fenetreprincipale.h"

#include "vuevol.h"
#include "vueconfig.h"

#include "src/noyau/Vol.h"
#include "src/noyau/Toboggan.h"


using namespace vue_config::vol;

VueVol::VueVol(FenetrePrincipale& fenetrePrincipale, Vol& vol):
        VueCanevas(fenetrePrincipale,rect),
        _image(new QSvgRenderer(etatNormal)),
        _vol (vol)
{
    //TODO : utiliser VueCanevas::definirCoordonnees
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

Vol* VueVol::volAssocie()
{
    return &_vol;
}
