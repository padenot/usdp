#ifndef VUECHARIOT_H
#define VUECHARIOT_H

#include <QFile>

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include "vueelement.h"
#include "src/noyau/Chariot.h"
/**
 * Une classe de d'élément graphique pour représenter un chariot.
 * Permet de dessiner un chariot.
 */
class VueChariot : public VueElement
{
public:
	/**
	 *
	 * @param _fenetrePrincipale
	 * @param chariot
	 * @return
	 */
    VueChariot(FenetrePrincipale& _fenetrePrincipale, Chariot &chariot);
	/**
	 * Dessiner l'élément graphique.
	 * @param painter L'objet Qt pour dessiner.
	 * @param option Des options en fonction  de l'environnement graphique.
	 * @param widget Le widget sur lequel dessiner.
	 */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Accesseur pour avoir le chariot dans le modèle.
     * @return Une référence vers le chariot dans le modèle.
     */
    Chariot& chariot();

protected:
    /**
     * Appelé à chaque tick d'horloge, fait avancer le bagage.
     * @param step 0 juste avant d'avancer, 1 sinon.
     */
    void advance(int step);

private:
    /**
     * L'état interne du chariot.
     */
    int _etat;
    /**
     * Un pointeur static vers un objet capable de rendre du SVG, pour dessiner
     * l'icone.
     */
    static QSvgRenderer *_renderer;
    /**
     * Un pointer vers l'image, pour éviter de la redessiner.
     */
    QGraphicsSvgItem *_image;
    /**
     * Une référence vers le chariot, dans le modèle.
     */
    Chariot &_chariot;

    /**
     * Une image rasterisée de l'icône vectorielle, pour la mise en cache.
     */
    QPixmap _pixmap;
    /**
     * Un objet capable de dessiner l'icône en mode raster.
     */
    QPainter _paintPixmap;
};

#endif // VUECHARIOT_H
