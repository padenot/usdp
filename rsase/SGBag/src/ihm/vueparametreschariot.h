#ifndef VUEPARAMETRESCHARIOT_H
#define VUEPARAMETRESCHARIOT_H

#include <QWidget>
#include "src/noyau/Chariot.h"

namespace Ui {
    class VueParametresChariot;
}

class VueParametresChariot : public QWidget
{
    Q_OBJECT

    public:
        explicit VueParametresChariot(Chariot& chariot, QWidget *parent = 0);
        ~VueParametresChariot();

    protected slots :
        void modifierTypePilotage(int typePilotage);
        void modifierDirectionConseillee(int direction);

    private:
        Ui::VueParametresChariot *ui;
        Chariot& _chariot;
};

#endif // VUEPARAMETRESCHARIOT_H
