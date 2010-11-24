#ifndef VUECONFIG_H
#define VUECONFIG_H

#include <QString>
#include <QRectF>
#include <QPen>
#include <QFont>
/**
 * Ce namespace permet de configurer simplement les constantes
 * qui régissent la simulation.
 */
namespace vue_config
{
    /**
     * Valeur du zoom sur certains éléments, permettant de ne pas les afficher
     * en taille réelle afin de bien les voir.
     */
    const double ZOOM_ELEMENTS = 10.0;
    /**
     * Le nombre d'image par seconde désirée.
     */
    const int fps = 30;
    /**
     * Le rafraichissement en millisecondes
     */
    const int dt = 1000/fps;

    /**
     * Les constantes relatives au dessin.
     */
    namespace canevas
    {
		/**
		 * La marge utilisée pour les boites englobantes.
		 */
        const double marge = 2;
    }

    /**
     * Les constantes relatives aux éléments graphiques.
     */
    namespace element
    {
		/**
		 * La couleur du dessin pour la selection.
		 * @param La couleur effective.
		 * @return Un objet représentant un type de trait.
		 */
        const QBrush brushSelection(Qt::lightGray);
		/**
		 * La couleur du dessin pour la selection.
		 * @param La couleur effective.
		 * @return Un objet représentant un type de trait.
		 */
        const QPen penSelection(Qt::darkGray);
        /**
         * L'opacité de du cadre affiché lors de la selection.
         */
        const double opacite = 0.7;
        /**
         * Le rayon du cercle utilisé pour les coins arrondis des
         * rectangles de selection.
         */
        const double arrondis = 1;
    }

    /**
     * Les constantes relatives au bagages.
     */
    namespace bagage
    {
		/**
		 * Le l'indice de profondeur d'un élément graphique
		 * bagage.
		 */
        const int zIndex = 10;
        /**
         * La longueur d'un bagage.
         */
        const double longueur = 0.4;//*ZOOM_ELEMENTS;
        /**
         * La largeur d'un élément.
         */
        const double largeur = 0.4;//*ZOOM_ELEMENTS;
        /**
         * Nombre de ressources utilisées pour les bagages.
         */
        //const int nbrRes = 4;
        /**
         * Chemin dans un .qrc d'une image de bagage.
         */
        const QString bagageSimple = ":/images/bagageSimple";
        /**
         * Tableau pour avoir les chemins de tous les bagages.
         */
        //const QString resBagage[nbrRes] = { sacsport, saccuir, valise, homard };
        /**
         * Taille de la boite englobante pour un bagage.
         */
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);

        /**
         * La fonte pour afficher l'id sur un bagage.
         */
        const QFont font = QFont("SansSerif", 12, QFont::Normal);
        /**
         * La couleur du texte de l'id du bagage.
         */
        const QColor couleurTexte = QColor(35,35,35);
        /**
         * Rotation du texte, en degrés
         */
        const qreal rotationTexte = -15;
        /**
         * Position horizontale du texte.
         */
        const qreal dxTexte = 0;
        /**
         * Position verticale du texte.
         */
        const qreal dyTexte = 0;
    }
    /**
     * Les constantes relative au chariot
     */
    namespace chariot
    {
    /**
     * L'indice de profondeur d'un chariot : inférieur à celui d'un bagage.
     */
        const int zIndex = 9;
        /**
         * La longueur d'un chartiot.
         */
        const double longueur = 1*ZOOM_ELEMENTS;
        /**
         * La largeur d'un chariot.
         */
        const double largeur = 1*ZOOM_ELEMENTS;
        /**
         * Le chemin dans un .qrc de l'image.
         */
        const QString etatNormal = ":/images/chariot";
        /**
         * Les coordonnées de la fenetre englobante pour un chariot.
         */
        const QRectF rect = QRectF(-longueur/2, -largeur/2, longueur, largeur);
    }

    /**
     * Constantes pour l'élément graphique tapis.
     */
    namespace tapis
    {
		/**
		 * L'indice de profondeur d'un tapis.
		 */
        const int zIndex = 8;
        /**
         * La largeur d'un tapis.
         */
        const double largeur = 1*ZOOM_ELEMENTS;
        /**
         * L'image représentant un tapis.
         */
        const QString etatNormal = ":/images/tapis-roulant";
    }

    /**
     * Constantes pour l'élément graphique toboggan.
     */
    namespace toboggan
    {
		/**
		 * L'indice de profondeur pour un tapis.
		 */
        const int zIndex = 5;
        /**
         * La largeur d'un toboggan.
         */
        const double largeur = 1*ZOOM_ELEMENTS;
        /**
         * Le chemin dans un .qrc d'un toboggan
         */
        const QString etatNormal = ":/images/toboggan";
    }

    /**
     * Les constantes pour un élément graphique tronçon.
     */
    namespace troncon
    {
    /**
     * L'indice de profondeur d'un tronçon.
     */
        const int zIndex = 5;
        /**
         * La demi largeur d'un rail à l'affichage
         */
        const double largeur = 0.5;
        /**
         * Le rayon d'un noeud.
         */
        const double rayonNoeud = largeur*1.3;
		/**
		 * La couleur de fond du rail
		 */
        const QBrush brushGray(Qt::gray);
        /**
         * L'affichage du fond du rail
         */
        const QPen penLight(Qt::gray, 0);
        /**
         * L'affichage des bords du rail
         */
        const QPen penDark(Qt::darkGray, 0.3);
        /**
         * Couleur de fond du rail en état cassé
         */
        const QBrush brushRed(Qt::red);
        /**
         * L'affichage du fond du rail en état cassé
         */
        const QPen penRedLight(Qt::red, 0);
        /**
         * L'affichage des bords du rail en état cassé
         */
        const QPen penRedDark(Qt::darkRed, 0.3);
    }

    /**
     *Les constantes pour un élément graphique vol.
     */
    namespace vol
    {
		/**
		 * L'indice de pronfondeur de l'élément graphique vol.
		 */
        const int zIndex = 10;
        /**
         * La longueur d'un avion.
         */
        const double longueur = 70;
        /**
         * La largeur d'un avion.
         */
        const double largeur = longueur*0.5;//0.77;
        /**
         * L'écart avec le toboggan d'un avion.
         */
        const double ecartToboggan = 3*ZOOM_ELEMENTS;
        /**
         * Le chemin dans un .qrc de l'image d'un avion.
         */
        const QString etatNormal = ":/images/avion";
    }
}

#endif // VUECONFIG_H
