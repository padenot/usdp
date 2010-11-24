#ifndef VUEBAGAGE_H
#define VUEBAGAGE_H

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include <QFile>

#include "vueelement.h"

#include "src/noyau/Bagage.h"

class VueBagage : public VueElement
{
public:
	/**
	 * Crée un élément graphique pour un bagage
	 * @param[in] _fenetrePrincipale Une référence sur la fenetre principale.
	 * @param[in] bagage Une référence vers le bagage.
	 */
    VueBagage(FenetrePrincipale& _fenetrePrincipale, Bagage &bagage);
	/**
	 * Dessiner l'élément graphique.
	 * @param painter L'objet Qt pour dessiner.
	 * @param option Des options en fonction  de l'environnement graphique.
	 * @param widget Le widget sur lequel dessiner.
	 */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Avoir le bagage associé.
     * @return Le bagage associé à cet élément graphique.
     */
    Bagage* bagageAssocie();

protected:
    /**
     * Appelé à chaque tick d'horloge, fait avancer le bagage.
     * @param step 0 juste avant d'avancer, 1 sinon.
     */
    void advance(int step);

private:
    /**
     * L'état interne de la vue bagage
     */
    int _etat;
    /**
     * Un pointeur static vers un objet capable de rendre du SVG, pour dessiner
     * l'icone.
     */
    static QSvgRenderer *_renderer;
    /**
     * Une référence vers le bagage, dans le modèle.
     */
    Bagage &_bagage;
};

#endif // VUEBAGAGE_H
