#include "vueparametreschariot.h"
#include "ui_vueparametreschariot.h"
#include "src/noyau/Chariot.h"

VueParametresChariot::VueParametresChariot(Chariot& chariot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueParametresChariot),
    _chariot(chariot)
{
    ui->setupUi(this);

    connect(ui->vitesseMax,SIGNAL(valueChanged(double)),
            &_chariot,SLOT(modifierVitesseMax(double)));
    ui->vitesseMax->setValue(_chariot.vitesseMax());

    connect(&chariot,SIGNAL(vitesseModifiee(double)),
            ui->vitesseActuelle,SLOT(setValue(double)));
    ui->vitesseActuelle->setValue(_chariot.vitesse());

    connect(ui->modePilotage, SIGNAL(valueChanged(int)),
            this,SLOT(modifierTypePilotage(int)));
    ui->modePilotage->setValue(_chariot.typePilotage());

    connect(ui->directionConseillee, SIGNAL(valueChanged(int)),
            this,SLOT(modifierDirectionConseillee(int)));
    ui->directionConseillee->setValue(_chariot.directionConseillee());
}

VueParametresChariot::~VueParametresChariot()
{
    delete ui;
}

void VueParametresChariot::modifierTypePilotage(int typePilotage)
{
    _chariot.modifierTypePilotage(
            static_cast<Chariot::TypePilotage>(typePilotage));
}

void VueParametresChariot::modifierDirectionConseillee(int direction)
{
    _chariot.modifierDirectionConseillee(
            static_cast<Direction>(direction));
}
