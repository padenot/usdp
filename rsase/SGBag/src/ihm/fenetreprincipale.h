#ifndef FENETREPRINCPALE_H
#define FENETREPRINCPALE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QMap>

#include "fenetreprincipale.h"
#include "src/noyau/Prototype.h"
#include "src/noyau/XmlConfigFactory.h"

#include "vuevol.h"
#include "vuetapis.h"

namespace Ui {
    class FenetrePrincipale;
}


class FenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetrePrincipale(Prototype *proto, QWidget *parent = 0);
    ~FenetrePrincipale();

    void AjouterItem(QGraphicsItem *item);
    void AjouterItems(const XmlConfigFactory::IndexTypesElements &elements);
    void modeAjoutBagage(VueTapis* tapis);
    void traitementAjoutBagage(VueTapis* tapis);

    void verrouAjoutBagage(bool flag);

     typedef QVector<QGraphicsItem*> IndexVues;

signals:
    void volSelectionne(VueVol* vueVol);

protected slots :
    void finAjoutBagage(VueVol* vol);
    void annulerAjoutBagage();

    void changerVitesse(int pourcentage);

    void afficherSelection();

private:
    void afficherParametres(const QMap<QString, QString> *parametres);

    Ui::FenetrePrincipale* ui;
    QGraphicsScene* scene;
    Prototype* prototype;

    QTimer timer;

    IndexVues vues;

    VueTapis* vueTapisSelectionne;

};

#endif // FENETREPRINCPALE_H
