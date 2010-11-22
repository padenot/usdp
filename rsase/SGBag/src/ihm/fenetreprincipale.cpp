#include <QDebug>
#include <QTableView>
#include <QTableWidgetItem>
#include <QInputDialog>
#include <QMetaClassInfo>
#include <QMessageBox>
#include <QFileDialog>

#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"
#include "ui_ajouterVol.h"
#include "ui_about.h"


#include "vueconfig.h"
#include "vuecanevas.h"
#include "vuebagage.h"
#include "vuechariot.h"
#include "vuetapis.h"
#include "vuetoboggan.h"
#include "vuetroncon.h"
#include "vuevol.h"
#include "vueparametreschariot.h"

#include "src/noyau/XmlConfigFactory.h"


const int INDEX_ONGLET_PARAMETRES = 0;


FenetrePrincipale::FenetrePrincipale(Prototype *proto, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetrePrincipale),
    scene(new QGraphicsScene()),
    prototype(proto),
    _vueParametres(0),
    _etat(NORMAL),
    ratioActuel(1)
{
    ui->setupUi(this);

    connect(ui->startStopButton, SIGNAL(clicked()), this, SLOT(basculerMarcheArret()));

    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changerVitesse(int)));
    ui->speedSlider->setValue(50);
    ui->ratioSlider->setValue(1);
    ui->vitesse->setText(QString::number(prototype->acqVitesse())+"x");

    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(changementSelection()));
    connect(ui->ratioSlider, SIGNAL(valueChanged(int)), this, SLOT(changementRatio(int)));
    //TODO ici mettre la taille d la zone de l'aeorport.
    scene->setSceneRect(vue_config::scene::rect);
    //L'index peut ralentir l'affichage lorsque les items bougent.
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    // TODO : enlever ça, ça ne sert qu'à Etienne ?
    scene->setBackgroundBrush(Qt::white);

    ui->vue->setRenderHint(QPainter::Antialiasing);
    ui->vue->setCacheMode(QGraphicsView::CacheNone);
    ui->vue->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->vue->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->vue->setScene(scene);
    ui->vue->setAlignment(Qt::AlignCenter);

    ui->volTableView->setModel(prototype->modelVols());

    connect(ui->volAjouterToolButton, SIGNAL(clicked()), this,SLOT(ajouterVol()));
    connect(ui->volAssocierButton, SIGNAL(clicked()), this, SLOT(associerVolToboggan()));
    connect(ui->volAnnulerButton, SIGNAL(clicked()), this, SLOT(annulerAssociation()));
    connect(ui->action_Changer_de_circuit, SIGNAL(triggered()), this, SLOT(changementCircuit()));
    connect(ui->action_propos_de_Qt, SIGNAL(triggered()), this, SLOT(aProposQt()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));
    connect(ui->action_propos, SIGNAL(triggered()), this, SLOT(aPropos()));

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
    delete prototype;
}

void FenetrePrincipale::changementCircuit()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choisissez un nouveau fichier de circuit"), ".", tr("*.xml"));
    scene->clear();
    delete prototype;
    prototype = new Prototype(fileName);
    extraireVuesCanevas(prototype->elements());
}

void FenetrePrincipale::quitterApplication()
{
    QApplication::exit(0);
}

void FenetrePrincipale::aPropos()
{
    Ui::About aboutt;
    QDialog dialog;
    aboutt.setupUi(&dialog);
    dialog.exec();
}

void FenetrePrincipale::aProposQt()
{
    QMessageBox().aboutQt(this);
}



void FenetrePrincipale::changementRatio(int valeur)
{
    if(valeur > 0)
    {
        qreal ratio = valeur;

        ratio /= ratioActuel;
        ratioActuel *= ratio;
        ui->vue->scale(ratio, ratio);

        ui->ratio->setText(QString::number(ratioActuel)+"x");

        //mapToScene(ui->vue->rect())

        qDebug() << ui->vue->rect().center();
    }
}

void FenetrePrincipale::basculerMarcheArret()
{
    // TODO : convertir en donnée membre d'objet, ou récupérer
    // la valeur dans le modèle
    static bool etat = false;

    if(!etat)
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

void FenetrePrincipale::ajouterVueCanevas(VueCanevas *vue)
{
    scene->addItem(vue);
}

void FenetrePrincipale::extraireVuesCanevas(
        const XmlConfigFactory::IndexTypesElements &elementsList)
{
    foreach(Element *chariot,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
    {
            ajouterVueCanevas(new VueChariot(*this, *dynamic_cast<Chariot*>(chariot)));
    }

    foreach(Element *tapis,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
    {
            ajouterVueCanevas(new VueTapis(*this, *dynamic_cast<Tapis*>(tapis)));
    }

    foreach(Element *toboggan,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::toboggan]])
    {
            ajouterVueCanevas(new VueToboggan(*this, *dynamic_cast<Toboggan*>(toboggan)));
    }

    foreach(Element *troncon,
            elementsList[XmlConfigFactory::NodeName_String[XmlConfigFactory::troncon]])
    {
            ajouterVueCanevas(new VueTroncon(*this, *dynamic_cast<Troncon*>(troncon)));
    }
}

void FenetrePrincipale::changerVitesse(int pourcentage)
{
    prototype->changerVitesse(pourcentage);
    ui->vitesse->setText(QString::number(prototype->acqVitesse())+"x");
}

void FenetrePrincipale::ajouterVol()
{
    QString text = QInputDialog::getText(this, tr("Choix du nom du vol"),
                                         tr("Nom du vol ?"), QLineEdit::Normal);
    if (!text.isEmpty())
    {
         Vol* vol = new Vol(text);
         prototype->ajouterVol(vol);
    }
}

void FenetrePrincipale::destructionBagage(QObject* bagage)
{
    QList<QGraphicsItem *> listeObjetsGraphiques = scene->items();
    foreach(QGraphicsItem* objet, listeObjetsGraphiques)
    {
        VueBagage* vueBagage = dynamic_cast<VueBagage*>(objet);
        if (vueBagage != 0 && vueBagage->bagageAssocie() == bagage)
        {
            scene->removeItem(vueBagage);
            delete vueBagage;
            break;
        }
    }
}

// declenchement du mode ajoutBagage
void FenetrePrincipale::ajoutBagage(VueTapis& vueTapis)
{
    _vueTapisAjoutBagage = &vueTapis;
    changementEtat(AJOUTBAGAGE);
}

void FenetrePrincipale::finAjoutBagage(VueVol& vueVol)
{
    Bagage* bagage = prototype->ajouterBagage(_vueTapisAjoutBagage->tapisAssocie(), vueVol.volAssocie());
    connect(bagage,SIGNAL(destroyed(QObject*)),
            this,SLOT(destructionBagage(QObject*))/*,Qt::BlockingQueuedConnection*/);

    ajouterVueCanevas(new VueBagage(*this, *bagage));

    qDebug() << "Bagage ajouté";

    changementEtat(NORMAL);
}

void FenetrePrincipale::annulerAjoutBagage()
{
    // TODO
}

void FenetrePrincipale::associerVolToboggan()
{
    if(_etat == NORMAL)
    {
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
        item->setFlags(QGraphicsItem::ItemIsSelectable);
    }
}

void FenetrePrincipale::changementEtat(Etat etat)
{
    switch(etat)
    {
    case SELECTIONTOBOGGAN:
        qDebug() << "On passe en selection toboggan";
        ui->volAssocierButton->setText("&Annuler");
        break;
    case NORMAL:
        qDebug() << "On passe en mode normal";
        ui->volAssocierButton->setText("&Associer");
        break;
    case AJOUTBAGAGE:
        qDebug() << "On passe en ajout bagage";
        break;
    };
    _etat = etat;
}


/*------------------------------------------------------------
             SELECTION D'UNE VUE SUR LE CANEVAS
  ------------------------------------------------------------*/

void FenetrePrincipale::changementSelection()
{
    QList<QGraphicsItem*> selectedItems= scene->selectedItems();

    if (selectedItems.empty())
    {
        return;
    }
    else
    {
        if (_vueParametres != 0)
        {
            ui->layoutParametres->removeWidget(_vueParametres);
            delete _vueParametres;
            _vueParametres = 0;
        }

        VueChariot* vueChariot = dynamic_cast<VueChariot*>(selectedItems.first());
        if (vueChariot != 0)
        {
            selectionChariot(*vueChariot);
            return;
        }

        VueToboggan* vueToboggan = dynamic_cast<VueToboggan*>(selectedItems.first());
        if(vueToboggan != 0)
        {
            selectionToboggan(*vueToboggan);
            return;
        }

        VueVol* vueVol = dynamic_cast<VueVol*>(selectedItems.first());
        if(vueVol != 0)
        {
            selectionVol(*vueVol);
            return;
        }

        VueTapis* vueTapis = dynamic_cast<VueTapis*>(selectedItems.first());
        if(vueTapis != 0)
        {
            selectionTapis(*vueTapis);
            return;
        }

        VueBagage* vueBagage = dynamic_cast<VueBagage*>(selectedItems.first());
        if(vueBagage != 0)
        {
            selectionBagage(*vueBagage);
            return;
        }
    }
}

void FenetrePrincipale::selectionChariot(VueChariot& vueChariot)
{
    _vueParametres = new VueParametresChariot(vueChariot.chariot(),this);
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}

void FenetrePrincipale::selectionToboggan(VueToboggan& vueToboggan)
{
    if (_etat == SELECTIONTOBOGGAN)
    {
        QItemSelectionModel* selectionmodel = ui->volTableView->selectionModel();
        QModelIndexList listIndex = selectionmodel->selectedIndexes();
        vueToboggan.associerVol(prototype->vol(listIndex.at(0).row()));
        ajouterVueCanevas(new VueVol(*this, *prototype->vol(listIndex.at(0).row())));
        // TODO : détruire la vue en même temps que le vol
        // L'association a été faite : on rechange l'état des boutons, et on rend
        // tout selectionnable.
        annulerAssociation();
        ui->statusBar->showMessage(trUtf8("Toboggan associé"), 2000);
    }
    // TODO : autres états + paramètres
}

void FenetrePrincipale::selectionVol(VueVol& vueVol)
{
    if (_etat == AJOUTBAGAGE)
    {
        finAjoutBagage(vueVol);
    }
    // TODO : autres états + paramètres
}


void FenetrePrincipale::selectionTapis(VueTapis& vueTapis)
{
    // TODO
}

void FenetrePrincipale::selectionBagage(VueBagage& vueBagage)
{
    // TODO
}
