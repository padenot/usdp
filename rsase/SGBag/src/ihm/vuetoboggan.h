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
     * @param [in] fenetrePrincipale - la fen�tre principale de l'application
     * @param [in] toboggan - le toboggan associ� � la vue r�spective
     */
    VueToboggan(FenetrePrincipale& _fenetrePrincipale, Toboggan &toboggan);

    /**
     * M�thode qui permet de dessiner la vue
     * @param [in] painter - l'objet Qt pour dessiner
     * @param [in] option - des options en fonction  de l'environnement graphique.
     * @param [in] widget - le widget sur lequel dessiner.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * M�thode qui permet d'associer un vol � un toboggan
     */
    void associerVol(Vol* vol);

    /**
     * Le toboggan associ� � la vue
     */
    Toboggan& toboggan() const;

protected:
    /**
     * M�thode vide mais n�cessaire
     */
    void advance(int step);

private:
    /**
     * attribut qui permet de rendre le fichier svg associ� � la vue
     */
    static QSvgRenderer *_renderer;

    /**
     * L'image associ�e � la vue du toboggan
     */
    QGraphicsSvgItem *_image;

    /**
     * L'objet toboggan associ� � la vue
     */
    Toboggan &_toboggan;
};

#endif // VUETOBOGGAN_H
