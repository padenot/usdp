#include "src/ihm/vueparametreselementactif.h"
#include "ui_vueparametreselementactif.h"

VueParametresElementActif::VueParametresElementActif(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VueParametresElementActif)
{
    ui->setupUi(this);
}

VueParametresElementActif::~VueParametresElementActif()
{
    delete ui;
}
