#ifndef VUE_CANEVAS_H
#define VUE_CANEVAS_H

#include <QGraphicsItem>

class FenetrePrincipale;

class VueCanevas: public QGraphicsItem
{
public:
    explicit VueCanevas(FenetrePrincipale& fenetrePrincipale);
    VueCanevas(FenetrePrincipale& fenetrePrincipale, QRectF boundingBox);
    QRectF boundingRect() const;

protected :
    void definirCoordonnees(QPointF positionDebut,
                            QPointF positionFin, double largeur,
                            double largeurSecurite = 0);
    /**
     * @var fenetrePrincipale Référence vers la fenêtre principale.
     */
    FenetrePrincipale& _fenetrePrincipale;
    QRectF _rect;
};

#endif // VUE_CANEVAS_H
