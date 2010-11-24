#include <QDebug>
#include <QTableView>
#include <QTableWidgetItem>
#include <QInputDialog>
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
#include "vueparametrestoboggan.h"

#include "src/noyau/XmlConfigFactory.h"


const int INDEX_ONGLET_PARAMETRES = 0;


FenetrePrincipale::FenetrePrincipale(Prototype *proto, QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::FenetrePrincipale),
        scene(new QGraphicsScene()),
        prototype(proto),
        _vueParametres(0),
        ratioActuel(1),
        _etat(NORMAL)
{
    ui->setupUi(this);

    connect(ui->startStopButton, SIGNAL(clicked()), this, SLOT(basculerMarcheArret()));

    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(changerVitesse(int)));
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(changementSelection()));
    connect(ui->ratioSlider, SIGNAL(valueChanged(int)), this, SLOT(changementRatio(int)));

    //L'index peut ralentir l'affichage lorsque les items bougent.
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    scene->setBackgroundBrush(Qt::white);

    ui->vue->setRenderHints( QPainter::Antialiasing |
                             QPainter::TextAntialiasing |
                             QPainter::SmoothPixmapTransform |
                             QPainter::HighQualityAntialiasing);
    ui->vue->setCacheMode(QGraphicsView::CacheNone);
    ui->vue->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->vue->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->vue->setScene(scene);
    ui->vue->setAlignment(Qt::AlignCenter);


    connect(ui->volAjouterToolButton, SIGNAL(clicked()),this,SLOT(ajouterVol()));
    connect(ui->volAssocierButton, SIGNAL(clicked()), this, SLOT(associerVolToboggan()));
    connect(ui->volAnnulerButton, SIGNAL(clicked()), this, SLOT(annulerAssociation()));
    connect(ui->action_Changer_de_circuit, SIGNAL(triggered()), this, SLOT(changementCircuit()));
    connect(ui->action_propos_de_Qt, SIGNAL(triggered()), this, SLOT(aProposQt()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitterApplication()));
    connect(ui->action_propos, SIGNAL(triggered()), this, SLOT(aPropos()));
    connect(ui->volSupprimertoolButton, SIGNAL(clicked()), this, SLOT(supprimerVol()));

    timer.start(vue_config::dt);
    _dialog = new QDialog(this);

    ui->volTableView->setModel(prototype->modelVols());
    ui->speedSlider->setValue(100);
    ui->ratioSlider->setValue(1);
    ui->vitesse->setText("100%");
}

FenetrePrincipale::~FenetrePrincipale()
{
    disconnect(this,SLOT(destructionBagage(QObject*)));
    delete scene;
    delete ui;
    delete _dialog;
    delete prototype;
}

void FenetrePrincipale::changementCircuit()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Choisissez un nouveau fichier de circuit"), ".", tr("*.xml"));

    definirMarcheArret(false);
    scene->clear();
    delete prototype;
    prototype = new Prototype(fileName);
    extraireVuesCanevas(prototype->elements());

    // Initialisations liées au prototype
    ui->volTableView->setModel(prototype->modelVols());
    ui->speedSlider->setValue(100);
    ui->ratioSlider->setValue(1);
    ui->vitesse->setText("100%");
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

            ui->vue->scale(ratio/ratioActuel, ratio/ratioActuel);
            ratioActuel = ratio;

        ui->ratio->setText(QString::number(ratioActuel)+"x");

        scene->update();
    }
}

void FenetrePrincipale::basculerMarcheArret()
{
    definirMarcheArret(!prototype->estEnMarche());
}

void FenetrePrincipale::definirMarcheArret (bool marche)
{
    if (marche)
    {
        prototype->commencerSimulation();
        ui->startStopButton->setIcon(QIcon(":/icones/pause"));
    }
    else
    {
        prototype->arreterSimulation();
        ui->startStopButton->setIcon(QIcon(":/icones/play"));
    }
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
    pourcentage = prototype->changerVitesse(pourcentage);
    ui->vitesse->setText(QString::number(pourcentage)+"%");
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

void FenetrePrincipale::supprimerVol()
{
    if(_etat == NORMAL)
    {
        QItemSelectionModel* selectionmodel = ui->volTableView->selectionModel();
        QModelIndexList listIndex = selectionmodel->selectedIndexes();
        if( ! listIndex.empty())
        {
            // On cherche si ce vol a des bagages en attente.
            // On sauvegarde l'adresse du vol.
            Vol* vol = prototype->vol(listIndex.at(0).row());
            if(prototype->retirerVol(listIndex.at(0).row()))
            {
                QList<QGraphicsItem*> list =  scene->items();
                foreach(QGraphicsItem* item, list)
                {
                    VueVol* vueVol = dynamic_cast<VueVol*>(item);
                    if(vueVol != 0 && vueVol->volAssocie() == vol)
                        scene->removeItem(vueVol);
                }
            }
            else
                ui->statusBar->showMessage("Retrait du vol impossible, bagages en attente.", 2000);
        }
    }
}

int FenetrePrincipale::nombreVols()
{
    return prototype->modelVols()->rowCount(QModelIndex());
}


void FenetrePrincipale::finAjoutBagage(VueVol& vueVol)
{
    Bagage* bagage = prototype->ajouterBagage(_vueTapisAjoutBagage->tapisAssocie(), vueVol.volAssocie());
    if(bagage != 0)
    {
        connect(bagage,SIGNAL(destroyed(QObject*)),
                this,SLOT(destructionBagage(QObject*))/*,Qt::BlockingQueuedConnection*/);

        ajouterVueCanevas(new VueBagage(*this, *bagage));

        ui->statusBar->showMessage(trUtf8("Bagage ajouté"), 5000);
    }
    else
    {
        ui->statusBar->showMessage(trUtf8("Plus de place sur le tapis ! Le bagage n'a pas Ã©tÃ© ajoutÃ©"), 5000);
    }
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
        if(prototype->vol(listIndex.at(0).row())->tobogganAssocie() != 0)
        {
            ui->statusBar->showMessage(trUtf8("Ce vol a déjà un toboggan associé."), 2000);
        }
        else if( ! listIndex.empty())
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

        VueTroncon* vueTroncon = dynamic_cast<VueTroncon*>(selectedItems.first());
        if(vueTroncon != 0)
        {
            selectionTroncon(*vueTroncon);
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
        // L'association a été faite : on rechange l'état des boutons, et on rend
        // tout selectionnable.
        annulerAssociation();
        ui->statusBar->showMessage(trUtf8("Toboggan associé"), 2000);
    }

    _vueParametres = new VueParametresToboggan(vueToboggan.toboggan(), this);
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}

void FenetrePrincipale::selectionVol(VueVol& vueVol)
{
    if (_etat == AJOUTBAGAGE)
    {
        finAjoutBagage(vueVol);
    }
    vueParametresDefaut();
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}


void FenetrePrincipale::selectionTapis(VueTapis& vueTapis)
{
    vueParametresDefaut();
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}

void FenetrePrincipale::selectionBagage(VueBagage& vueBagage)
{
    vueParametresDefaut();
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}

void FenetrePrincipale::selectionTroncon(VueTroncon&)
{
    vueParametresDefaut();
    ui->layoutParametres->addWidget(_vueParametres);
    ui->onglets->setCurrentIndex(INDEX_ONGLET_PARAMETRES);
}

void FenetrePrincipale::vueParametresDefaut()
{
    _vueParametres = new QLabel(trUtf8("Pas de paramÃ¨tres pour cet objet"), this);
}

void FenetrePrincipale::messageBarreDeStatus(const QString& message, int ms)
{
    ui->statusBar->showMessage(message, ms);
}

