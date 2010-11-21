#include "vueparametreschariot.h"
#include "ui_vueparametreschariot.h"
#include "src/noyau/Chariot.h"

VueParametresChariot::VueParametresChariot(Chariot& chariot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueParametresChariot),
    _chariot(chariot)
{
    ui->setupUi(this);
    connect(ui->vitesseMax,SIGNAL(valueChanged(double)),&_chariot,SLOT(modifierVitesseMax(double)));
}

VueParametresChariot::~VueParametresChariot()
{
    delete ui;
}
