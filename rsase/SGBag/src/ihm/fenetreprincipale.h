#ifndef FENETREPRINCPALE_H
#define FENETREPRINCPALE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QMap>

#include "fenetreprincipale.h"
#include "src/noyau/Prototype.h"
#include "src/noyau/XmlConfigFactory.h"
#include <QDialog>

#include "vuevol.h"
#include "vuetapis.h"
#include "vueparametreschariot.h"

namespace Ui {
    class FenetrePrincipale;
}


class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT
private:
    /**
     * Etat de la vue.
     */
    enum Etat
    {
        NORMAL,
        SELECTIONTOBOGGAN,
        AJOUTBAGAGE
    };

public:
    explicit FenetrePrincipale(Prototype *proto, QWidget *parent = 0);
    ~FenetrePrincipale();

    void AjouterItem(QGraphicsItem *item);
    void AjouterItems(const XmlConfigFactory::IndexTypesElements &elements);

    void ajoutBagage(VueTapis* tapis);

    typedef QVector<QGraphicsItem*> IndexVues;

signals:
    void volSelectionne(VueVol* vueVol);

protected slots :
    void finAjoutBagage(VueVol* vol);
    void annulerAjoutBagage();

    void ajouterVol();
    void associerVolToboggan();
    void annulerAssociation();

    void changerVitesse(int pourcentage);

    void changementSelection();

    void changerEtat();

    void desactiverToutSaufToboggans();

    void changementEtat(Etat etat);
    void activerSelection();

private:
    void afficherParametres(const QMap<QString, QString> *parametres);

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

    Etat _etat;
};

#endif // FENETREPRINCPALE_H
