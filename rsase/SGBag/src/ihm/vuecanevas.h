#ifndef VUE_CANEVAS_H
#define VUE_CANEVAS_H

#include <QGraphicsItem>
#include <QGraphicsSvgItem>

class FenetrePrincipale;
/**
 * Classe abstraite, qui permet de définir des implémentation
 * de méthodes communes au éléments graphiques.
 */
class VueCanevas: public QGraphicsSvgItem //QGraphicsItem
{
public:
	/**
	 * Classe abstraite, qui permet de définir des implémentation
	 * de méthodes communes au éléments graphiques.
	 * @param fenetrePrincipale Un référence sur la fenêtre principale.
	 */
    explicit VueCanevas(FenetrePrincipale& fenetrePrincipale);
    /**
     * Constructeur prenant un rectangle, qui sera la boite englobante
     * de l'élément graphique.
     * @param fenetrePrincipale Une référence sur la fenêtre principale.
     * @param boundingBox La boundingbox de l'élément graphique.
     * @return
     */
    VueCanevas(FenetrePrincipale& fenetrePrincipale, QRectF boundingBox);
    /**
     * Un accesseur pour la bounding box, permettant d'optimiser le dessin.
     * @return La boite englobante de l'objet, incluant les marges.
     */
    QRectF boundingRect() const;

protected :
    /**
     * Un accesseur en écriture pour les coordonnées de l'objet graphique.
     * @param positionDebut La position du début de l'objet.
     * @param positionFin La position de fin de l'objet.
     * @param largeur La largeur de l'objet.
     * @param ajoutLongueurApresFin Une marge après la fin de l'objet.
     * @param ajoutLongueurAvantDebut Une marge avant le début de l'objet.
     */
    void definirCoordonnees(QPointF positionDebut,
                                    QPointF positionFin, double largeur,
                                    double ajoutLongueurApresFin = 0,
                                    double ajoutLongueurAvantDebut = 0);
    /**
     * @var fenetrePrincipale Référence vers la fenêtre principale.
     */
    FenetrePrincipale& _fenetrePrincipale;
    /**
     * Le rectangle englobant pour l'objet, au plus serré (sans les marges).
     */
    QRectF _rect;
};

#endif // VUE_CANEVAS_H
