#include "src/ihm/vuetroncon.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/Noeud.h"

#include <QtSvg/QSvgRenderer>
#include <QVector2D>

using namespace vue_config::troncon;

VueTroncon::VueTroncon(FenetrePrincipale& fenetrePrincipale, Troncon& troncon):
        VueElement(fenetrePrincipale),
        _troncon(troncon),
        _vecteurDirection(_troncon.noeudDebut()->position() - _troncon.noeudFin()->position()),
        _lignePerpendiculaire(QPointF(0,0), _vecteurDirection.toPointF())
{
    setZValue(zIndex);

    _vecteurDirection.normalize();
    _lignePerpendiculaire.setLength(1);
    _lignePerpendiculaire.setAngle( _lignePerpendiculaire.angle() + 90 );

    point1 = QPointF(_troncon.noeudDebut()->position() - _vecteurDirection.toPointF()*largeur + _lignePerpendiculaire.p2()*largeur);
    point2 = QPointF(_troncon.noeudFin()->position() + _vecteurDirection.toPointF()*largeur + _lignePerpendiculaire.p2()*largeur);
    point3 = QPointF(_troncon.noeudDebut()->position() - _vecteurDirection.toPointF()*largeur - _lignePerpendiculaire.p2()*largeur);
    point4 = QPointF(_troncon.noeudFin()->position() + _vecteurDirection.toPointF()*largeur - _lignePerpendiculaire.p2()*largeur);


    _fond[0] = _troncon.noeudDebut()->position() + _lignePerpendiculaire.p2()*largeur*0.5;
    _fond[1] = _troncon.noeudFin()->position() + _lignePerpendiculaire.p2()*largeur*0.5;
    _fond[2] = _troncon.noeudFin()->position() - _lignePerpendiculaire.p2()*largeur*0.5;
    _fond[3] = _troncon.noeudDebut()->position() - _lignePerpendiculaire.p2()*largeur*0.5;
}


void VueTroncon::advance(int pas)
{
}

void VueTroncon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    VueElement::paint(painter,0,0);

    painter->setBrush(brushGray);

    painter->setPen(penDark);
    painter->drawEllipse(_troncon.noeudFin()->position(), largeur*1.2, largeur*1.2);
    painter->drawEllipse(_troncon.noeudDebut()->position(), largeur*1.2, largeur*1.2);

    painter->setPen(penLight);
    painter->drawPolygon(_fond, 4);

    painter->setPen(penDark);
    painter->drawLine(point1, point2);
    painter->drawLine(point3, point4);

}

QRectF VueTroncon::boundingRect() const
{
    return QRectF(0,0,1,1);
    //return QRectF(point1,point3);
}
