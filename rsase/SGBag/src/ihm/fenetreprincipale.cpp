    #include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

#include "src/ihm/vuebagage.h"
#include "src/ihm/vuechariot.h"

#include "src/ihm/vueconfig.h"

#include "src/noyau/XmlConfigFactory.h"

void FenetrePrincipale::AjouterItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

void FenetrePrincipale::AjouterItems(XmlConfigFactory::IndexTypesElements elementsList)
{
    QGraphicsItem* item;
    foreach(Element* chariot,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
    {
        item = new VueChariot((Chariot*)chariot);
        scene->addItem(item);
        qDebug() << "creation de la vue pour " << chariot << "." << endl;
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
void FenetrePrincipale::modeAjoutBagage(Tapis* tapis)
{
    verrouAjoutBagage(true);

    // Préparer fin de l'ajout du bagage
        // Connecter les avions à FenetrePrincipale::finAjoutBagage(Vol* vol)
        // Connecter le bouton annuler à FenetrePrincipale::annulerAjoutBagage()
}

void FenetrePrincipale::finAjoutBagage(Tapis* tapis, Vol* vol)
{
       prototype->ajouterBagage(tapis, vol);
       verrouAjoutBagage(false);
}

void FenetrePrincipale::annulerAjoutBagage()
{
    verrouAjoutBagage(false);
}

void FenetrePrincipale::verrouAjoutBagage(bool flag)
{

}


