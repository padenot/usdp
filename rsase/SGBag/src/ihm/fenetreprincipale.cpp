#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"
#include "src/ihm/vuebagage.h"

void FenetrePrincipale::AjouterItem(QGraphicsItem *item)
{
    scene->addItem(item);
}

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale),
    scene(new QGraphicsScene())
{
    ui->setupUi(this);

    //TODO ici mettre la taille d la zone de l'aeorport.
    scene->setSceneRect(0, 0, 300,300);
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
