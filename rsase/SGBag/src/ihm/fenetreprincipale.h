/**
  * \file vuefenetreprincipale
  * \autor
  * \brief Classe gérant la vue de la fenêtre principale
  */

ifndef FENETREPRINCPALE_H
#define FENETREPRINCPALE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDialog>

#include "fenetreprincipale.h"
#include "src/noyau/Prototype.h"
#include "src/noyau/XmlConfigFactory.h"

#include <QtGlobal>

class VueCanevas;
class VueVol;
class VueBagage;
class VueToboggan;
class VueChariot;
class VueTapis;
class VueParametresChariot;
class VueTroncon;

namespace Ui {
    class FenetrePrincipale;
}

/**
 * @todo TODO implÃ©menter le zoom
 */
class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        /**
          Le constructeur de la classe
          @param [in] proto - le prototype
          @param [in] parent - parent de l'entité qui
        */
        explicit FenetrePrincipale(Prototype *proto, QWidget *parent = 0);
        ~FenetrePrincipale();

        /**
          Méthode qui permet de recupérer les vues de tous les élements graphiques affichés dans la fenêtre principale
          @param [in] elements - la carte qui contient tous les élements
        */
        void extraireVuesCanevas(const XmlConfigFactory::IndexTypesElements &elements);

        /**
          Methode qui permet d'afficher un message dans la barre de status de la fenêtre principale
          @param [in] message - le message qui va être affiché dans la bare de status de la fenêtre principale
          @param [in] ms - l'identifiant du message affiché
        */
        void messageBarreDeStatus(const QString& message, int ms);

        /**
          Méthode qui permet d'ajouter un bagage sur le tapis.
          @param [in] tapis - la vue du tapis où le bagage va être ajouté
        */
        void ajoutBagage(VueTapis& tapis);

        /**
          Méthode qui permet d'obtenir le nombre de vols actifs.
        */
        int nombreVols();


    private:

        /**
         * Etat de la vue.
            NORMAL - état normal de simulation
            SELECTIONTOBOGGAN - état de la fenêtre quand un toboggan est selectionné
            AJOUTBAGAGE - état de la fenêtre quand l'utilisateur a choisi l'action d'ajouter un bagage
         */
        enum Etat
        {
            NORMAL,
            SELECTIONTOBOGGAN,
            AJOUTBAGAGE
        };

        /**
         * Méthode qui permet d'ajouter un canevas sur la fênetre principale.
           @param [in] vue - la vue qui correspond au canevas
         */
        void ajouterVueCanevas(VueCanevas *vue);



    protected slots :

        /**
         * Méthode qui permet de supprimer un bagage
         * @param [in] bagage - le bagage qui va être détruit
         */
        void destructionBagage(QObject* bagage);

        /**
         * Méthode qui marque la fin du traitement sur l'ajout d'un bagage
         * @param [in] vol - le vol auquel le bagage est associé
         */
        void finAjoutBagage(VueVol& vol);

        /**
         * Méthode qui anulle l'ajout d'un bagage sur un tapis
         */
        void annulerAjoutBagage();

        /**
         * Méthode qui permet d'ajouter un vol dans la liste avec tous les vols de la fenêtre principale
         */
        void ajouterVol();

        /**
         * Méthode qui permet de supprimer un vol de la liste de vols dans la fenêtre principale
         */
        void supprimerVol();

        /**
         * Méthode qui permet d'associer un vol à un toboggan, la fenêtre passe en mode sélection toboggan
         */
        void associerVolToboggan();

        /**
         * Méthode qui permet d'annuler l'opération d'association, la fenêtre sort du mode sélection tobogan
         */
        void annulerAssociation();

        /**
         * Méthode qui permet de changer la vitesse de la simulation
         * @param [in] pourcentage - pourcentage de la vitesse normale
         */
        void changerVitesse(int pourcentage);

        /**
         * Méthode appelée quand l'élement selectionné a changé
         */
        void changementSelection();

        /**
         * Méthode qui permet démarrer la simulation si elle est arrêtée ou de l'arrêter si elle est démarrée
         */
        void basculerMarcheArret();

        /**
         * Méthode qui permet démarrer/arrêter la simulation
         * @param [in] marche - true si on veut dámarrer la simulation, false si on veut l'arrêter
         */
        void definirMarcheArret (bool marche);

        /**
         * Méthode qui empêche de sélectionner tous les objets de la fenêtre principale sauf les toboggans
         */
        void desactiverToutSaufToboggans();

        /**
         * Méthode qui permet de changer l'état de la fenêtre
         * @param [in] etat - le nouvel état de la fenêtre
         */
        void changementEtat(Etat etat);

        /**
         * Méthode qui rend actifs tous les objets de la fenêtre principale
         */
        void activerSelection();

        /**
         * Méthode qui permet de zoomer/dezoomer sur le canevas
         * @param [in] ratio - répresente combien de fois on agrandit/réduit la taille
                               du canevas par rapport à la taille actuelle
         */
        void changementRatio(int ratio);

        /**
         * Méthode qui permet decharger le circuit de rails à partir d'n fichier
         */
        void changementCircuit();

        /**
         * Méthode qui permet de quitter l'application
         */
        void quitterApplication();

        /**
         * Méthode qui ouvre la fenêtre qui contient des informations générales sur l'application SgBag
         */
        void aPropos();

        /**
         * Méthode qui ouvre la fenêtre qui contient des informations générales sur Qt
         */
        void aProposQt();

    private:

        /**
         * Méthode qui sélectionne un chariot
         * @param vueChariot [in] - la vue de l'objet chariot qu'on veut sélectionner
         */
        void selectionChariot(VueChariot& vueChariot);

        /**
         * Méthode qui sélectionne un toboggan
         * @param vueToboggan [in] - la vue de l'objet toboggan qu'on veut sélectionner
         */
        void selectionToboggan(VueToboggan& vueToboggan);

        /**
         * Méthode qui sélectionne un vol
         * @param vueVol [in] - la vue de l'objet vol qu'on veut sélectionner
         */
        void selectionVol(VueVol& vueVol);

        /**
         * Méthode qui sélectionne un chariot
         * @param vueTapis [in] - la vue de l'objet tapis qu'on veut sélectionner
         */
        void selectionTapis(VueTapis& vueTapis);

        /**
         * Méthode qui sélectionne un bagage
         * @param vueBagage [in] - la vue de l'objet bagage qu'on veut sélectionner
         */
        void selectionBagage(VueBagage& vueBagage);
        void selectionTroncon(VueTroncon&);
        void vueParametresDefaut();

        /**
         * L'objet qui correspond à la fenêtre principale
         */
        Ui::FenetrePrincipale* ui;

        /**
         * L'objet qui correspond au canevas de la fenêtre principale
         */
        QGraphicsScene* scene;

        /**
         * L'objet qui correspond au prototype lié à la fenêtre principale
         */
        Prototype* prototype;

        /**
         * Le timer utilisé pour la simulation
         */
        QTimer timer;

        /**
         * La vue du tapis qui correspond à l'ajout du bagage
         */
        VueTapis* _vueTapisAjoutBagage;

        /**
         * La vue qui correspond à l'onglet Paramètres dans la fenêtre principale
         */
        QWidget* _vueParametres;

        /**
        * Dialog pour l'ajout de vol
        */
        QDialog* _dialog;

        /**
        * Paramètre qui marque le fait qu'on est en train de sélectionner un toboggan
        */
        bool enTrainDeSelectionnerUnToboggan;

        /**
        * Le niveau actuel de granularité du canevas
        */
        qreal ratioActuel;

        /**
        * L'état de la fenêtre principale
        */
        Etat _etat;
};

#endif // FENETREPRINCPALE_H
