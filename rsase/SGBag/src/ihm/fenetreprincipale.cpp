#include <QDebug>
#include <QTableView>
#include <QTableWidgetItem>

#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

#include "vue.h"
#include "vuebagage.h"
#include "vuechariot.h"
#include "vuetapis.h"
#include "vuetoboggan.h"
#include "vuetroncon.h"

#include "vueconfig.h"

#include "src/noyau/XmlConfigFactory.h"

void FenetrePrincipale::AjouterItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

void FenetrePrincipale::AjouterItems(const XmlConfigFactory::IndexTypesElements &elementsList)
{
    foreach(Element *chariot,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
    {
            scene->addItem(new VueChariot(*this, *dynamic_cast<Chariot*>(chariot)));
    }

    foreach(Element *tapis,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
    {
            scene->addItem(new VueTapis(*this, *dynamic_cast<Tapis*>(tapis)));
    }

    foreach(Element *toboggan,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::toboggan]])
    {
            scene->addItem(new VueToboggan(*this, *dynamic_cast<Toboggan*>(toboggan)));
    }

   foreach(Element *troncon,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::troncon]])
    {
            scene->addItem(new VueTroncon(*this, *dynamic_cast<Troncon*>(troncon)));
    }
}

void FenetrePrincipale::changerVitesse(int pourcentage)
{
    prototype->changerVitesse(pourcentage);
    ui->vitesse->setText(QString::number(prototype->acqVitesse())+"x");
}

void FenetrePrincipale::changerEtat()
{
static bool etat = false;

    if(etat)
    {
        prototype->commencerSimulation();
        ui->startStopButton->setIcon(QIcon(":/icones/pause"));
    }
    else
    {
        prototype->arreterSimulation();
        ui->startStopButton->setIcon(QIcon(":/icones/play"));
    }

    etat = !etat;

}

FenetrePrincipale::FenetrePrincipale(Prototype *proto, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale),
    scene(new QGraphicsScene()),
    prototype(proto)
{
    ui->setupUi(this);

    //TODO Faire des slots, et merger les boutons start/stop
    connect(ui->startStopButton, SIGNAL(clicked()), this, SLOT(changerEtat()));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changerVitesse(int)));
    ui->speedSlider->setValue(50);
    ui->vitesse->setText(QString::number(prototype->acqVitesse())+"x");

    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(afficherSelection()));

    //TODO ici mettre la taille d la zone de l'aeorport.
    scene->setSceneRect(vue_config::scene::rect);
    //L'index peut ralentir l'affichage lorsque les items bougent.
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->vue->setRenderHint(QPainter::Antialiasing);
    ui->vue->setCacheMode(QGraphicsView::CacheNone);
    ui->vue->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->vue->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->vue->setScene(scene);
    ui->vue->scale(7, 7);

    //ui->TableParametres->setColumnCount(2);

    timer.start(vue_config::dt);
}

FenetrePrincipale::~FenetrePrincipale()
{
    foreach(QGraphicsItem* item, scene->items())
    {
        delete item;
    }

    delete scene;
    delete ui;
}

// declenchement du mode ajoutBagage
void FenetrePrincipale::modeAjoutBagage(VueTapis* vueTapis)
{
    verrouAjoutBagage(true);

    // Prparer fin de l'ajout du bagage
    // Connecter les avions  FenetrePrincipale::finAjoutBagage(Vol* vol)
    connect(this, SIGNAL(volSelectionne(VueVol*)), SLOT(finAjoutBagage(VueVol*)));
    // Connecter le bouton annuler  FenetrePrincipale::annulerAjoutBagage()
}

void FenetrePrincipale::finAjoutBagage(VueVol* vueVol)
{
    for(int i = 0; i<100; ++i)
        qDebug() << "Bagage ajouté";

       prototype->ajouterBagage(vueTapisSelectionne->tapisAssocie(), vueVol->volAssocie());
       verrouAjoutBagage(false);
       // Fin ajout bagage : déconnexion du signal
       this->disconnect(SIGNAL(volSelectionne(VueVol*)));
}

void FenetrePrincipale::annulerAjoutBagage()
{
    verrouAjoutBagage(false);
    // Fin ajout bagage : déconnexion du signal.
    this->disconnect(SIGNAL(volSelectionne(VueVol*)));
}

void FenetrePrincipale::afficherSelection()
{
    /*
    QList<QGraphicsItem*> selectedItems= scene->selectedItems();

    switch (selectedItems.count())
    {
        case 0:
        {
            // Aucun élement selectionné, on efface les paramètres.
            ui->TableParametres->setRowCount(0);
            return;
        }
        case 1:
        {
            afficherParametres(dynamic_cast<Vue*>(selectedItems.first())->parametres());
            return;
        }
    }
    return;*/
}

void FenetrePrincipale::afficherParametres(const QMap<QString, QString> *parametres)
{/*
    ui->TableParametres->setRowCount(parametres->count());

    int i=0;
    foreach(const QString key , parametres->keys())
    {
        QTableWidgetItem *description = new QTableWidgetItem();
        description->setData(0, key);
        description->setFlags(description->flags() &= !~Qt::ItemIsEditable);
        ui->TableParametres->setItem(i++, 0, description);
    }

    i=0;
    foreach(const QString value, parametres->values())
    {
        QTableWidgetItem *parametre = new QTableWidgetItem();
        parametre->setData(2, value);
        ui->TableParametres->setItem(i++, 1, parametre);
    }*/
}

void FenetrePrincipale::verrouAjoutBagage(bool flag)
{

}
