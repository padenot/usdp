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
         * @param [in] fenetrePrincipale - la fenêtre principale de l'application
         * @param [in] tapis - le tapis associé à la vue réspective
         */
        VueTapis(FenetrePrincipale& _fenetrePrincipale, Tapis &tapis);

        /**
         * Destructeur de la classe.
         */
        virtual ~VueTapis();

        /**
         * Méthode qui permet de dessiner la vue
         * @param [in] painter - l'objet Qt pour dessiner
         * @param [in] option - des options en fonction  de l'environnement graphique.
         * @param [in] widget - le widget sur lequel dessiner.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        /**
         * Accesseur au tapis associé à la vue
         */
        Tapis* tapisAssocie();

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
         * L'objet tapis associé à la vue
         */
        Tapis &_tapis;

        /**
         * Instance de VueTapisHandler intégrée à  la vue.
         */
        VueTapisHandler& _handler;
};

/**
 * Gestionnnaire d'Ã©vÃ©nements pour VueTapis
 */
class VueTapisHandler : public QObject
{
    Q_OBJECT

    public:
        /**
         * Le handler associé à la vue
         * @param [in] vueTapis - la vue du tapis associé
         * @param [in] fenetrePrincipale - la fenêtre principale de l'application
         */
        VueTapisHandler(VueTapis& vueTapis, FenetrePrincipale& fenetrePrincipale);
    public slots:
        /**
         * Méthode qui permet d'ajouter un bagage
         */
        void ajouterBagage();
    protected:
        /**
         * La vue tapis correspondante
         */
        VueTapis& _vueTapis;

        /**
         * La fenêtre principale de l'application
         */
        FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUETAPIS_H
