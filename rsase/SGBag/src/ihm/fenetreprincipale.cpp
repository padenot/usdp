#include <QDebug>
#include <QTableView>
#include <QTableWidgetItem>

#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"
#include "ui_ajouterVol.h"

#include "vue.h"
#include "vuebagage.h"
#include "vuechariot.h"
#include "vuetapis.h"
#include "vuetoboggan.h"
#include "vuetroncon.h"

#include "vueparametreschariot.h"

#include "vueconfig.h"

#include <QInputDialog>
#include <QDir>
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

void FenetrePrincipale::changementSelection()
{
    QList<QGraphicsItem*> selectedItems= scene->selectedItems();

    if (selectedItems.empty())
    {
        return;
    }
    else
    {
        VueChariot* vueChariot = dynamic_cast<VueChariot*>(selectedItems.first());
        if (vueChariot != 0)
        {
            if (_vueParametres != 0)
            {
                ui->layoutParametres->removeWidget(_vueParametres);
                delete _vueParametres;
            }

            _vueParametres = new VueParametresChariot(vueChariot->chariot(),this);

            ui->layoutParametres->addWidget(_vueParametres);
        }
        VueToboggan* vueToboggan = dynamic_cast<VueToboggan*>(selectedItems.first());
        if(vueToboggan != 0)
        {
            QItemSelectionModel* selectionmodel = ui->volTableView->selectionModel();
            QModelIndexList listIndex = selectionmodel->selectedIndexes();
            vueToboggan->associerVol(prototype->vol(listIndex.at(0).row()));
            // L'association a été faite : on rechange l'état des boutons, et on rend
            // tout selectionnable.
            annulerAssociation();
        }

        // TODO : autres types
    }
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
    _etat(NORMAL),
    prototype(proto),
    _vueParametres(0)
{
    ui->setupUi(this);

    //TODO Faire des slots, et merger les boutons start/stop
    connect(ui->startStopButton, SIGNAL(clicked()), this, SLOT(changerEtat()));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changerVitesse(int)));
    ui->speedSlider->setValue(50);
    ui->vitesse->setText(QString::number(prototype->acqVitesse())+"x");

    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(changementSelection()));

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
    ui->volTableView->setModel(prototype->modelVols());

    connect(ui->volAjouterToolButton, SIGNAL(clicked()), this,SLOT(ajouterVol()));
    connect(ui->volAssocierButton, SIGNAL(clicked()), this, SLOT(associerVolToboggan()));
    connect(ui->volAnnulerButton, SIGNAL(clicked()), this, SLOT(annulerAssociation()));
    //ui->TableParametres->setColumnCount(2);

    timer.start(vue_config::dt);
    _dialog = new QDialog(this);
}

FenetrePrincipale::~FenetrePrincipale()
{
    foreach(QGraphicsItem* item, scene->items())
    {
        delete item;
    }

    delete scene;
    delete ui;
    delete _dialog;
}

void FenetrePrincipale::ajouterVol()
{
       bool ok;
       QString text = QInputDialog::getText(this, tr("Choix du nom du vol"),
                                            tr("Nom du vol ?"), QLineEdit::Normal);
       if (ok && !text.isEmpty())
       {
            Vol* vol = new Vol(text);
            prototype->ajouterVol(vol);
       }
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

void FenetrePrincipale::associerVolToboggan()
{
    if(_etat == NORMAL)
    {
        qDebug() << __func__ << " Etat : normal";
        QItemSelectionModel* selectionmodel = ui->volTableView->selectionModel();
        QModelIndexList listIndex = selectionmodel->selectedIndexes();
        if( ! listIndex.empty())
        {
            changementEtat(SELECTIONTOBOGGAN);
            desactiverToutSaufToboggans();
            // listIndex.at(0).row() permet d'avoir la row dans le model
            ui->volAssocierButton->setEnabled(false);
            ui->volAnnulerButton->setEnabled(true);
        }
    }
}

void FenetrePrincipale::annulerAssociation()
{
    qDebug() << __func__ << " Etat : SELECTIONTOBOGGAN";
    ui->volAnnulerButton->setEnabled(false);
    ui->volAssocierButton->setEnabled(true);
    activerSelection();
    changementEtat(NORMAL);
}

void FenetrePrincipale::desactiverToutSaufToboggans()
{
    QList<QGraphicsItem *> gilist = scene->items();
    foreach(QGraphicsItem* item, gilist)
    {
        VueToboggan* tob = dynamic_cast<VueToboggan*>(item);
        if(tob == 0)
        {
           item->setFlags(0);
        }
    }
}

void FenetrePrincipale::activerSelection()
{
    QList<QGraphicsItem *> gilist = scene->items();
    foreach(QGraphicsItem* item, gilist)
    {
        qDebug() << "selection";
        item->setFlags(QGraphicsItem::ItemIsSelectable);
    }
}

void FenetrePrincipale::changementEtat(Etat etat)
{
    qDebug() << "Changement d'etat vers : " << etat;
    switch(etat)
    {
    case SELECTIONTOBOGGAN:
        qDebug() << "On passe en selection toboggan";
        ui->volAssocierButton->setText("&Annuler");
        _etat = SELECTIONTOBOGGAN;
        break;
    case NORMAL:
        qDebug() << "On passe en mode normal";
        ui->volAssocierButton->setText("&Associer");
        _etat = NORMAL;
        break;
    };
}

