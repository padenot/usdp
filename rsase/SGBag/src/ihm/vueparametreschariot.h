#ifndef VUEPARAMETRESCHARIOT_H
#define VUEPARAMETRESCHARIOT_H

#include <QWidget>

class Chariot;

namespace Ui {
    class VueParametresChariot;
}

class VueParametresChariot : public QWidget
{
    Q_OBJECT

public:
    explicit VueParametresChariot(Chariot& chariot, QWidget *parent = 0);
    ~VueParametresChariot();

private:
    Ui::VueParametresChariot *ui;
    Chariot& _chariot;
};

#endif // VUEPARAMETRESCHARIOT_H
