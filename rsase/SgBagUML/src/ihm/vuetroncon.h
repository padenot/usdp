#ifndef VUETRONCON_H
#define VUETRONCON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QVector2D>

#include "src/noyau/Troncon.h"
#include "vueelement.h"

class VueTronconHandler;

class VueTroncon : public VueElement
{
public:
    /**
     * Constructeur de la classe.
     * @param [in] fenetrePrincipale - la fenêtre principale de l'application
     * @param [in] troncon - le troncon associé à la vue réspective
     */
    VueTroncon(FenetrePrincipale& _fenetrePrincipale, Troncon& troncon);

    /**
     * Destructeur de la classe.
     */
    ~VueTroncon();

    /**
     * Méthode qui permet de dessiner la vue
     * @param [in] painter - l'objet Qt pour dessiner
     * @param [in] option - des options en fonction  de l'environnement graphique.
     * @param [in] widget - le widget sur lequel dessiner.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Méthode qui permet de mettre le troncon hors service
     */
    void mettreHorsService();

    /**
     * Méthode qui permet remettre le troncon en service
     */
    void reparer();


protected:
    /**
     * Méthode vide mais nécessaire
     */
    void advance(int step);

private:
    /**
     * Montre l'état d'un troncon (en service ou hors service)
     */
    int _etat;

    /**
     * L'objet Troncon associé à la vue
     */
    Troncon &_troncon;

    /**
     * Instance de VueTronconHandler intégrée à la vue.
     */
    VueTronconHandler& _handler;

};

/**
 * Gestionnnaire d'événements pour VueTroncon
 */
class VueTronconHandler : public QObject
{
    Q_OBJECT

    public:
        /**
         * Le handler associé à la vue
         * @param [in] vueTroncon - la vue du troncon associé
         * @param [in] fenetrePrincipale - la fenêtre principale de l'application
         */
        VueTronconHandler(VueTroncon& vueTroncon, FenetrePrincipale& fenetrePrincipale);

        /**
         * Méthode qui permet de mettre le troncon hors service
         */
        void mettreHorsService();

        /**
         * Méthode qui permet remettre le troncon en service
         */
        void reparer();

    protected:
        /**
         * La vue du troncon associée
         */
        VueTroncon& _vueTroncon;

        /**
         * La fenêtre principale de l'application
         */
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETRONCON_H
