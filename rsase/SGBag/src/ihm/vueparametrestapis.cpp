#include "vueparametrestapis.h"
#include "ui_vueparametrestapis.h"

VueParametresTapis::VueParametresTapis(Tapis& tapis, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueParametresTapis),
    _tapis(tapis)
{
    ui->setupUi(this);
    ui->vitesseMax->setValue(tapis.vitesseMax());
    connect(ui->vitesseMax, SIGNAL(valueChanged(double)), &_tapis, SLOT(modifierVitesseMax(double)));
}

VueParametresTapis::~VueParametresTapis()
{
    delete ui;
}
