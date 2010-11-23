#ifndef VUEPARAMETRESCHARIOT_H
#define VUEPARAMETRESCHARIOT_H

#include <QWidget>
#include "src/noyau/Chariot.h"

namespace Ui {
    class VueParametresChariot;
}

/**
 * Vue pour les paramêtres d'un chariot.
 */
class VueParametresChariot : public QWidget
{
    Q_OBJECT

    public:
    /**
     * Constructeur
     * @param chariot Le chariot que cette vue doit représenter.
     * @param parent Le parent de cette fenêtre (la fenêtre principale).
     */
        explicit VueParametresChariot(Chariot& chariot, QWidget *parent = 0);
     /**
      * Destructeur pour une VueParametresChariot
      * @return
      */
     virtual ~VueParametresChariot();

    protected slots :
		/**
		 * Changer le type de pilotage d'un chariot : automatique ou manuel.
		 * @param[in] typePilotage Le type de pilotage souhaité.
		 */
        void modifierTypePilotage(int typePilotage);
        /**
         * Changer la prochaine direction conseillée.
         * @param direction La prochaine direction conseillée.
         */
        void modifierDirectionConseillee(int direction);

    private:
        /**
         * Un pointeur vers la classe d'interface graphique.
         */
        Ui::VueParametresChariot *ui;
        /**
         * Le chariot actuellement contrôlé.
         */
        Chariot& _chariot;
};

#endif // VUEPARAMETRESCHARIOT_H
