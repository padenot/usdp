/**
  * \file vuefenetreprincipale
  * \autor
  * \brief Classe g�rant la vue de la fen�tre principale
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
 * @todo TODO implémenter le zoom
 */
class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        /**
          Le constructeur de la classe
          @param [in] proto - le prototype
          @param [in] parent - parent de l'entit� qui
        */
        explicit FenetrePrincipale(Prototype *proto, QWidget *parent = 0);
        ~FenetrePrincipale();

        /**
          M�thode qui permet de recup�rer les vues de tous les �lements graphiques affich�s dans la fen�tre principale
          @param [in] elements - la carte qui contient tous les �lements
        */
        void extraireVuesCanevas(const XmlConfigFactory::IndexTypesElements &elements);

        /**
          Methode qui permet d'afficher un message dans la barre de status de la fen�tre principale
          @param [in] message - le message qui va �tre affich� dans la bare de status de la fen�tre principale
          @param [in] ms - l'identifiant du message affich�
        */
        void messageBarreDeStatus(const QString& message, int ms);

        /**
          M�thode qui permet d'ajouter un bagage sur le tapis.
          @param [in] tapis - la vue du tapis o� le bagage va �tre ajout�
        */
        void ajoutBagage(VueTapis& tapis);

        /**
          M�thode qui permet d'obtenir le nombre de vols actifs.
        */
        int nombreVols();


    private:

        /**
         * Etat de la vue.
            NORMAL - �tat normal de simulation
            SELECTIONTOBOGGAN - �tat de la fen�tre quand un toboggan est selectionn�
            AJOUTBAGAGE - �tat de la fen�tre quand l'utilisateur a choisi l'action d'ajouter un bagage
         */
        enum Etat
        {
            NORMAL,
            SELECTIONTOBOGGAN,
            AJOUTBAGAGE
        };

        /**
         * M�thode qui permet d'ajouter un canevas sur la f�netre principale.
           @param [in] vue - la vue qui correspond au canevas
         */
        void ajouterVueCanevas(VueCanevas *vue);



    protected slots :

        /**
         * M�thode qui permet de supprimer un bagage
         * @param [in] bagage - le bagage qui va �tre d�truit
         */
        void destructionBagage(QObject* bagage);

        /**
         * M�thode qui marque la fin du traitement sur l'ajout d'un bagage
         * @param [in] vol - le vol auquel le bagage est associ�
         */
        void finAjoutBagage(VueVol& vol);

        /**
         * M�thode qui anulle l'ajout d'un bagage sur un tapis
         */
        void annulerAjoutBagage();

        /**
         * M�thode qui permet d'ajouter un vol dans la liste avec tous les vols de la fen�tre principale
         */
        void ajouterVol();

        /**
         * M�thode qui permet de supprimer un vol de la liste de vols dans la fen�tre principale
         */
        void supprimerVol();

        /**
         * M�thode qui permet d'associer un vol � un toboggan, la fen�tre passe en mode s�lection toboggan
         */
        void associerVolToboggan();

        /**
         * M�thode qui permet d'annuler l'op�ration d'association, la fen�tre sort du mode s�lection tobogan
         */
        void annulerAssociation();

        /**
         * M�thode qui permet de changer la vitesse de la simulation
         * @param [in] pourcentage - pourcentage de la vitesse normale
         */
        void changerVitesse(int pourcentage);

        /**
         * M�thode appel�e quand l'�lement selectionn� a chang�
         */
        void changementSelection();

        /**
         * M�thode qui permet d�marrer la simulation si elle est arr�t�e ou de l'arr�ter si elle est d�marr�e
         */
        void basculerMarcheArret();

        /**
         * M�thode qui permet d�marrer/arr�ter la simulation
         * @param [in] marche - true si on veut d�marrer la simulation, false si on veut l'arr�ter
         */
        void definirMarcheArret (bool marche);

        /**
         * M�thode qui emp�che de s�lectionner tous les objets de la fen�tre principale sauf les toboggans
         */
        void desactiverToutSaufToboggans();

        /**
         * M�thode qui permet de changer l'�tat de la fen�tre
         * @param [in] etat - le nouvel �tat de la fen�tre
         */
        void changementEtat(Etat etat);

        /**
         * M�thode qui rend actifs tous les objets de la fen�tre principale
         */
        void activerSelection();

        /**
         * M�thode qui permet de zoomer/dezoomer sur le canevas
         * @param [in] ratio - r�presente combien de fois on agrandit/r�duit la taille
                               du canevas par rapport � la taille actuelle
         */
        void changementRatio(int ratio);

        /**
         * M�thode qui permet decharger le circuit de rails � partir d'n fichier
         */
        void changementCircuit();

        /**
         * M�thode qui permet de quitter l'application
         */
        void quitterApplication();

        /**
         * M�thode qui ouvre la fen�tre qui contient des informations g�n�rales sur l'application SgBag
         */
        void aPropos();

        /**
         * M�thode qui ouvre la fen�tre qui contient des informations g�n�rales sur Qt
         */
        void aProposQt();

    private:

        /**
         * M�thode qui s�lectionne un chariot
         * @param vueChariot [in] - la vue de l'objet chariot qu'on veut s�lectionner
         */
        void selectionChariot(VueChariot& vueChariot);

        /**
         * M�thode qui s�lectionne un toboggan
         * @param vueToboggan [in] - la vue de l'objet toboggan qu'on veut s�lectionner
         */
        void selectionToboggan(VueToboggan& vueToboggan);

        /**
         * M�thode qui s�lectionne un vol
         * @param vueVol [in] - la vue de l'objet vol qu'on veut s�lectionner
         */
        void selectionVol(VueVol& vueVol);

        /**
         * M�thode qui s�lectionne un chariot
         * @param vueTapis [in] - la vue de l'objet tapis qu'on veut s�lectionner
         */
        void selectionTapis(VueTapis& vueTapis);

        /**
         * M�thode qui s�lectionne un bagage
         * @param vueBagage [in] - la vue de l'objet bagage qu'on veut s�lectionner
         */
        void selectionBagage(VueBagage& vueBagage);
        void selectionTroncon(VueTroncon&);
        void vueParametresDefaut();

        /**
         * L'objet qui correspond � la fen�tre principale
         */
        Ui::FenetrePrincipale* ui;

        /**
         * L'objet qui correspond au canevas de la fen�tre principale
         */
        QGraphicsScene* scene;

        /**
         * L'objet qui correspond au prototype li� � la fen�tre principale
         */
        Prototype* prototype;

        /**
         * Le timer utilis� pour la simulation
         */
        QTimer timer;

        /**
         * La vue du tapis qui correspond � l'ajout du bagage
         */
        VueTapis* _vueTapisAjoutBagage;

        /**
         * La vue qui correspond � l'onglet Param�tres dans la fen�tre principale
         */
        QWidget* _vueParametres;

        /**
        * Dialog pour l'ajout de vol
        */
        QDialog* _dialog;

        /**
        * Param�tre qui marque le fait qu'on est en train de s�lectionner un toboggan
        */
        bool enTrainDeSelectionnerUnToboggan;

        /**
        * Le niveau actuel de granularit� du canevas
        */
        qreal ratioActuel;

        /**
        * L'�tat de la fen�tre principale
        */
        Etat _etat;
};

#endif // FENETREPRINCPALE_H
