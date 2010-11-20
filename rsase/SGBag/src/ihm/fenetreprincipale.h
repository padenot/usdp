#ifndef FENETREPRINCPALE_H
#define FENETREPRINCPALE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "src/noyau/Prototype.h"
#include "src/noyau/XmlConfigFactory.h"

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
    void AjouterItems(XmlConfigFactory::IndexTypesElements elements);
    void modeAjoutBagage(Tapis* tapis);
    void traitementAjoutBagage(Tapis* tapis);
    void finAjoutBagage(Tapis* tapis, Vol* vol);
    void annulerAjoutBagage();
    void verrouAjoutBagage(bool flag);

    typedef QVector<QGraphicsItem*> IndexVues;

private:
    Ui::FenetrePrincipale* ui;
    QGraphicsScene* scene;
    Prototype* prototype;

    QTimer timer;

    IndexVues vues;

};

#endif // FENETREPRINCPALE_H
