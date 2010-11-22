#ifndef VUEPARAMETRESELEMENTACTIF_H
#define VUEPARAMETRESELEMENTACTIF_H

#include <QWidget>

namespace Ui {
    class VueParametresElementActif;
}

class VueParametresElementActif : public QWidget
{
    Q_OBJECT

public:
    explicit VueParametresElementActif(QWidget *parent = 0);
    ~VueParametresElementActif();

private:
    Ui::VueParametresElementActif *ui;
};

#endif // VUEPARAMETRESELEMENTACTIF_H
