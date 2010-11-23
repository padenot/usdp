#include <QLineF>

#include "vuecanevas.h"
#include "fenetreprincipale.h"

VueCanevas::VueCanevas(FenetrePrincipale& fenetrePrincipale) :
    _fenetrePrincipale(fenetrePrincipale)
{
    setFlags(QGraphicsItem::ItemIsSelectable);
}

VueCanevas::VueCanevas(FenetrePrincipale& fenetrePrincipale,
                       QRectF rect) :
    _fenetrePrincipale(fenetrePrincipale),
    _rect(rect)
{
    setFlags(QGraphicsItem::ItemIsSelectable);
}

void VueCanevas::definirCoordonnees(QPointF positionDebut,
                                QPointF positionFin, double largeur,
                                double ajoutLongueurApresFin,
                                double ajoutLongueurAvantDebut)
{
    QLineF direction(positionDebut, positionFin);
    direction.setLength(direction.length()
                        + ajoutLongueurApresFin + ajoutLongueurAvantDebut);
    direction.translate(QVector2D(positionDebut-positionFin).normalized()
                        .toPointF()*ajoutLongueurAvantDebut);

    _rect = QRectF(0,-largeur/2,direction.length(), largeur);

    setPos(direction.p1());
    setRotation(-direction.angle());
}

QRectF VueCanevas::boundingRect() const
{
    return _rect;
}
