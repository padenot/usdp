#ifndef VUETAPIS_H
#define VUETAPIS_H

#include <QObject>
#include <QFile>

#include <QGraphicsItem>
#include <QGraphicsSvgItem>
#include <QtSvg/QSvgRenderer>

#include <QPainter>
#include <QRectF>

#include "src/noyau/Tapis.h"
#include "vueelement.h"


#define FILEPATH_SVG_ETATNORMAL ":/images/tapis-etatNormal"

class VueTapisHandler;

class VueTapis : public VueElement
{
    public:
        /**
         * Constructeur de la classe.
         * @param [in] fenetrePrincipale - la fen�tre principale de l'application
         * @param [in] tapis - le tapis associ� � la vue r�spective
         */
        VueTapis(FenetrePrincipale& _fenetrePrincipale, Tapis &tapis);

        /**
         * Destructeur de la classe.
         */
        virtual ~VueTapis();

        /**
         * M�thode qui permet de dessiner la vue
         * @param [in] painter - l'objet Qt pour dessiner
         * @param [in] option - des options en fonction  de l'environnement graphique.
         * @param [in] widget - le widget sur lequel dessiner.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        /**
         * Accesseur au tapis associ� � la vue
         */
        Tapis* tapisAssocie();

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
         * L'objet tapis associ� � la vue
         */
        Tapis &_tapis;

        /**
         * Instance de VueTapisHandler int�gr�e �  la vue.
         */
        VueTapisHandler& _handler;
};

/**
 * Gestionnnaire d'événements pour VueTapis
 */
class VueTapisHandler : public QObject
{
    Q_OBJECT

    public:
        /**
         * Le handler associ� � la vue
         * @param [in] vueTapis - la vue du tapis associ�
         * @param [in] fenetrePrincipale - la fen�tre principale de l'application
         */
        VueTapisHandler(VueTapis& vueTapis, FenetrePrincipale& fenetrePrincipale);
    public slots:
        /**
         * M�thode qui permet d'ajouter un bagage
         */
        void ajouterBagage();
    protected:
        /**
         * La vue tapis correspondante
         */
        VueTapis& _vueTapis;

        /**
         * La fen�tre principale de l'application
         */
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETAPIS_H
