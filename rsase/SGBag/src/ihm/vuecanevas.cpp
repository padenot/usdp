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
                                double largeurSecurite)
{
    QLineF direction = QLineF(QPoint(0, 0), positionFin - positionDebut);
    QVector2D vecteurDir = QVector2D(positionFin - positionDebut);

    _rect = QRectF(0,-largeur/2,direction.length(), largeur);

    setPos(positionDebut); // + (vecteurDir.normalized().toPointF() * (largeurSecurite/2)));
    setRotation(-direction.angle());
}

QRectF VueCanevas::boundingRect() const
{
    return _rect;
}
