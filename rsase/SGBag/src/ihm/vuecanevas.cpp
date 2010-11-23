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
                                double ecartSecurite)
{
    QLineF direction = QLineF(QPoint(0, 0), positionFin - positionDebut);
    direction.setLength(direction.length() - ecartSecurite);

    _rect = QRectF(0,-largeur/2,direction.length(), largeur);

    setPos(positionDebut);
    setRotation(-direction.angle());
}

QRectF VueCanevas::boundingRect() const
{
    return _rect;
}
