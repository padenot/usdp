#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

#include "src/ihm/vuebagage.h"
#include "src/ihm/vuechariot.h"
#include "src/ihm/vuetapis.h"
#include "src/ihm/vuetoboggan.h"
#include "src/ihm/vuetroncon.h"

#include "src/ihm/vueconfig.h"

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
            scene->addItem(new VueChariot(this, dynamic_cast<Chariot*>(chariot)));
    }

    foreach(Element *tapis,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
    {
            scene->addItem(new VueTapis(this, dynamic_cast<Tapis*>(tapis)));
    }

    foreach(Element *toboggan,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::toboggan]])
    {
            scene->addItem(new VueToboggan(this, dynamic_cast<Toboggan*>(toboggan)));
    }

   foreach(Element *troncon,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::troncon]])
    {
            scene->addItem(new VueTroncon(this, dynamic_cast<Troncon*>(troncon)));
    }
}

FenetrePrincipale::FenetrePrincipale(Prototype *proto, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale),
    scene(new QGraphicsScene()),
    prototype(proto)
{
    ui->setupUi(this);

    //TODO Faire des slots, et merger les boutons start/stop
    connect(ui->startButton, SIGNAL(clicked()), prototype, SLOT(commencerSimulation()));
    connect(ui->stopButton, SIGNAL(clicked()), prototype, SLOT(arreterSimulation()));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), prototype, SLOT(changerVitesse(int)));

    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));


    //TODO ici mettre la taille d la zone de l'aeorport.
    scene->setSceneRect(vue_config::scene::rect);
    //L'index peut ralentir l'affichage lorsque les items bougent.
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->vue->setRenderHint(QPainter::Antialiasing);
    ui->vue->setCacheMode(QGraphicsView::CacheNone);
    ui->vue->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->vue->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->vue->setScene(scene);
    ui->vue->scale(5, 5);

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
       prototype->ajouterBagage(vueTapisSelectionne->tapisAssocie(), vueVol->volAssocie());
       verrouAjoutBagage(false);
}

void FenetrePrincipale::annulerAjoutBagage()
{
    verrouAjoutBagage(false);
}

void FenetrePrincipale::verrouAjoutBagage(bool flag)
{

}
