#include <QtSvg/QSvgRenderer>

#include "fenetreprincipale.h"

#include "vuevol.h"
#include "vueconfig.h"

#include "src/noyau/Vol.h"
#include "src/noyau/Toboggan.h"


using namespace vue_config::vol;

QSvgRenderer *VueVol::_renderer = new QSvgRenderer(etatNormal);

VueVol::VueVol(FenetrePrincipale& fenetrePrincipale, Vol& vol):
        VueCanevas(fenetrePrincipale),
        //_image(new QSvgRenderer(etatNormal)),
        _vol (vol)
{
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);

    //TODO : utiliser VueCanevas::definirCoordonnees
    QVector2D directionToboggan(_vol.tobogganAssocie()->position() -
                                _vol.tobogganAssocie()->pointConnexion());
    directionToboggan.normalize();
    QVector2D directionVol(directionToboggan.y(),-directionToboggan.x());
    directionVol.normalize();

    QPointF positionDebut = _vol.tobogganAssocie()->position()
                            + directionToboggan.toPointF() * ecartToboggan
                            - directionVol.toPointF() * longueur/2;
    QPointF positionFin = positionDebut + directionVol.toPointF() * longueur;

    // TODO
    definirCoordonnees(positionDebut, positionFin,
                       largeur);
    /*setPos(_vol.tobogganAssocie()->position() +
           QVector2D(_vol.tobogganAssocie()->position()
                     - vol.tobogganAssocie()->pointConnexion())
           .normalized().toPointF()*ecartToboggan);*/
    //setPos(2*_vol.tobogganAssocie()->position() - -vol.tobogganAssocie()->pointConnexion());
    //setPos(0,0);
}

void VueVol::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // TODO : faire un rendu à chaque repaint (donc toutes les 10ms environ), c'est violent.
    renderer()->render(painter, _rect);
}

Vol* VueVol::volAssocie()
{
    return &_vol;
}
