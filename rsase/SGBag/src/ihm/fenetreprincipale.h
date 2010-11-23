#ifndef FENETREPRINCPALE_H
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
        explicit FenetrePrincipale(Prototype *proto, QWidget *parent = 0);
        ~FenetrePrincipale();

        void extraireVuesCanevas(const XmlConfigFactory::IndexTypesElements &elements);
        void messageBarreDeStatus(const QString& message, int ms);


        void ajoutBagage(VueTapis& tapis);
        int nombreVols();

        typedef QVector<QGraphicsItem*> IndexVues;

    private:

        void ajouterVueCanevas(VueCanevas *vue);

        /**
         * Etat de la vue.
         */
        enum Etat
        {
            NORMAL,
            SELECTIONTOBOGGAN,
            AJOUTBAGAGE
        };

    protected slots :
        void destructionBagage(QObject* bagage);

        void finAjoutBagage(VueVol& vol);
        void annulerAjoutBagage();

        void ajouterVol();
        void supprimerVol();

        void associerVolToboggan();
        void annulerAssociation();

        void changerVitesse(int pourcentage);

        void changementSelection();

        void basculerMarcheArret();
        void definirMarcheArret (bool marche);

        void desactiverToutSaufToboggans();

        void changementEtat(Etat etat);
        void activerSelection();

        void changementRatio(int ratio);
        void changementCircuit();
        void quitterApplication();
        void aPropos();
        void aProposQt();

    private:
        void selectionChariot(VueChariot& vueChariot);
        void selectionToboggan(VueToboggan& vueToboggan);
        void selectionVol(VueVol& vueVol);
        void selectionTapis(VueTapis& vueTapis);
        void selectionBagage(VueBagage& vueBagage);

        Ui::FenetrePrincipale* ui;
        QGraphicsScene* scene;
        Prototype* prototype;

        QTimer timer;

        IndexVues vues;

        VueTapis* _vueTapisAjoutBagage;
        QWidget* _vueParametres;
        /* Dialog pour l'ajout de vol */
        QDialog* _dialog;

        bool enTrainDeSelectionnerUnToboggan;

        qreal ratioActuel;

        Etat _etat;
};

#endif // FENETREPRINCPALE_H
