#include <QtGui/QApplication>

#include "fenetreprincipale.h"
#include "../noyau/Prototype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Initialisation du générateur de nombre aléatoire,
     * sur le temps actuel
     */
    srand(time(NULL));

    Prototype* proto= new Prototype("configuration_complexe.xml");

    FenetrePrincipale w(proto);
    w.extraireVuesCanevas(proto->elements());
    w.show();

    return a.exec();
}
