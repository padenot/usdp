#ifndef VUEPARAMETRESTAPIS_H
#define VUEPARAMETRESTAPIS_H

#include <QWidget>
#include "src/noyau/Tapis.h"

namespace Ui {
    class VueParametresTapis;
}

class VueParametresTapis : public QWidget
{
    Q_OBJECT

public:
    explicit VueParametresTapis(Tapis& tapis, QWidget *parent = 0);
    ~VueParametresTapis();

private:
    Ui::VueParametresTapis *ui;
    Tapis& _tapis;
};

#endif // VUEPARAMETRESTAPIS_H
