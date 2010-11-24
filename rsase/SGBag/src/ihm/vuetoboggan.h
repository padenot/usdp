#ifndef VUETOBOGGAN_H
#define VUETOBOGGAN_H

#include <QFile>


#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include "src/noyau/Toboggan.h"
#include "vueelement.h"

class VueToboggan : public VueElement
{
public:

    /**
     * Constructeur de la classe.
     * @param [in] fenetrePrincipale - la fenêtre principale de l'application
     * @param [in] toboggan - le toboggan associé à la vue réspective
     */
    VueToboggan(FenetrePrincipale& _fenetrePrincipale, Toboggan &toboggan);

    /**
     * Méthode qui permet de dessiner la vue
     * @param [in] painter - l'objet Qt pour dessiner
     * @param [in] option - des options en fonction  de l'environnement graphique.
     * @param [in] widget - le widget sur lequel dessiner.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Méthode qui permet d'associer un vol à un toboggan
     */
    void associerVol(Vol* vol);

    /**
     * Le toboggan associé à la vue
     */
    Toboggan& toboggan() const;

protected:
    /**
     * Méthode vide mais nécessaire
     */
    void advance(int step);

private:
    /**
     * attribut qui permet de rendre le fichier svg associé à la vue
     */
    static QSvgRenderer *_renderer;

    /**
     * L'image associée à la vue du toboggan
     */
    QGraphicsSvgItem *_image;

    /**
     * L'objet toboggan associé à la vue
     */
    Toboggan &_toboggan;
};

#endif // VUETOBOGGAN_H
