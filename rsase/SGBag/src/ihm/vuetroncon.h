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
     * @param [in] fenetrePrincipale - la fen�tre principale de l'application
     * @param [in] troncon - le troncon associ� � la vue r�spective
     */
    VueTroncon(FenetrePrincipale& _fenetrePrincipale, Troncon& troncon);

    /**
     * Destructeur de la classe.
     */
    ~VueTroncon();

    /**
     * M�thode qui permet de dessiner la vue
     * @param [in] painter - l'objet Qt pour dessiner
     * @param [in] option - des options en fonction  de l'environnement graphique.
     * @param [in] widget - le widget sur lequel dessiner.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * M�thode qui permet de mettre le troncon hors service
     */
    void mettreHorsService();

    /**
     * M�thode qui permet remettre le troncon en service
     */
    void reparer();


protected:
    /**
     * M�thode vide mais n�cessaire
     */
    void advance(int step);

private:
    /**
     * Montre l'�tat d'un troncon (en service ou hors service)
     */
    int _etat;

    /**
     * L'objet Troncon associ� � la vue
     */
    Troncon &_troncon;

    /**
     * Instance de VueTronconHandler int�gr�e � la vue.
     */
    VueTronconHandler& _handler;

};

/**
 * Gestionnnaire d'�v�nements pour VueTroncon
 */
class VueTronconHandler : public QObject
{
    Q_OBJECT

    public:
        /**
         * Le handler associ� � la vue
         * @param [in] vueTroncon - la vue du troncon associ�
         * @param [in] fenetrePrincipale - la fen�tre principale de l'application
         */
        VueTronconHandler(VueTroncon& vueTroncon, FenetrePrincipale& fenetrePrincipale);

    public slots:
        /**
         * M�thode qui permet de mettre le troncon hors service
         */
        void mettreHorsService();

        /**
         * M�thode qui permet remettre le troncon en service
         */
        void reparer();

    protected:
        /**
         * La vue du troncon associ�e
         */
        VueTroncon& _vueTroncon;

        /**
         * La fen�tre principale de l'application
         */
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETRONCON_H
