#ifndef VUEPARAMETRESELEMENTACTIF_H
#define VUEPARAMETRESELEMENTACTIF_H

#include <QWidget>

namespace Ui {
    class VueParametresElementActif;
}

/**
 * Classe de vue pour les paramètres d'un élément actif.
 */
class VueParametresElementActif : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructeur.
     * @param parent Le créateur de cet objet (la fenêtre principale).
     */
    explicit VueParametresElementActif(QWidget *parent = 0);
    /**
     * Destructeur
     */
    virtual ~VueParametresElementActif();

private:
    /**
     * Un pointeur vers l'interface graphique pour les paramêtres
     *  d'un élément actif.
     */
    Ui::VueParametresElementActif *ui;
};

#endif // VUEPARAMETRESELEMENTACTIF_H
