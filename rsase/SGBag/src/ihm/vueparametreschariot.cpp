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
    connect(ui->modePilotage, SIGNAL(valueChanged(int)),
            this,SLOT(modifierTypePilotage(int)));
    connect(ui->directionConseillee, SIGNAL(valueChanged(int)),
            this,SLOT(modifierDirectionConseillee(int)));
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
