#include "vueparametrestoboggan.h"
#include "ui_vueparametrestoboggan.h"

VueParametresToboggan::VueParametresToboggan(Toboggan& toboggan, QWidget *parent) :
    QWidget(parent),
    _toboggan(toboggan),
    ui(new Ui::VueParametresToboggan)
{
    ui->setupUi(this);
    nombreDeBagages(toboggan.nombreDeBagages());
    connect(&_toboggan, SIGNAL(nombreDeBagages(int)), this, SLOT(nombreDeBagages(int)));
}

VueParametresToboggan::~VueParametresToboggan()
{
    delete ui;
}

void VueParametresToboggan::nombreDeBagages(int nbBagages)
{
    ui->nbBagagesSpinBox->setValue(nbBagages);
}
