#include "vueparametreschariot.h"
#include "ui_vueparametreschariot.h"
#include "src/noyau/Chariot.h"

VueParametresChariot::VueParametresChariot(Chariot& chariot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueParametresChariot),
    _chariot(chariot)
{
    ui->setupUi(this);
}

VueParametresChariot::~VueParametresChariot()
{
    delete ui;
}
