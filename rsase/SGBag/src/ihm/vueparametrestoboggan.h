#ifndef VUEPARAMETRESTOBOGGAN_H
#define VUEPARAMETRESTOBOGGAN_H

#include <QWidget>
#include "src/noyau/Toboggan.h"

namespace Ui {
    class VueParametresToboggan;
}

class VueParametresToboggan : public QWidget
{
    Q_OBJECT

public:
    explicit VueParametresToboggan(Toboggan& toboggan, QWidget *parent = 0);
    ~VueParametresToboggan();

public slots:
    void nombreDeBagages(int);

private:
    Ui::VueParametresToboggan *ui;
    Toboggan& _toboggan;
};

#endif // VUEPARAMETRESTOBOGGAN_H
