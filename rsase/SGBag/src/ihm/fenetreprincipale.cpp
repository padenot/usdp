#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"
#include "src/ihm/vuebagage.h"
#include "src/ihm/vueconfig.h"
#include "src/noyau/XmlConfigFactory.h"

void FenetrePrincipale::AjouterItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

void FenetrePrincipale::AjouterItems(XmlConfigFactory::IndexTypesElements elements)
{
    //foreach
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
    connect(ui->stopButton, SIGNAL(clicked()), prototype, SLOT(ArreterSimulation()));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), prototype, SLOT(changerVitesse(int)));

    //TODO ici mettre la taille d la zone de l'aeorport.
    scene->setSceneRect(vue_config::scene::rect);
    //L'index peut ralentir l'affichage lorsque les items bougent.
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->vue->setRenderHint(QPainter::Antialiasing);
    ui->vue->setCacheMode(QGraphicsView::CacheNone);
    ui->vue->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->vue->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->vue->setScene(scene);
}

FenetrePrincipale::~FenetrePrincipale()
{
    delete scene;
    delete ui;
}
