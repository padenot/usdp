#ifndef VUEPARAMETRESTOBOGGAN_H
#define VUEPARAMETRESTOBOGGAN_H

#include <QWidget>
#include "src/noyau/Toboggan.h"

namespace Ui {
    class VueParametresToboggan;
}

/**
 * Une vue pour les paramètres d'un toboggan.
 */
class VueParametresToboggan : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructeur.
     * @param toboggan Le toboggan que cette vue doit représenter.
     * @param parent Le parent de cette instance : la fenêtre principale.
     * @return
     */
    explicit VueParametresToboggan(Toboggan& toboggan, QWidget *parent = 0);
    /**
     * Destructeur.
     */
    virtual ~VueParametresToboggan();

public slots:
	/**
	 * Un slot pour conter le nombre de bagage.
	 * @param[in] nbBagage Le nombre de bagage à  afficher.
	 */
    void nombreDeBagages(int nbBagage);

private:
    /**
     * Un pointeur vers la classe d'inteface matérielle.
     */
    Ui::VueParametresToboggan *ui;
    /**
     * Un référence vers le toboggan auquel se rapporte cette classe.
     */
    Toboggan& _toboggan;
};

#endif // VUEPARAMETRESTOBOGGAN_H
