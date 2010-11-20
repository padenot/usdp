#include <QtGui/QApplication>

#include "fenetreprincipale.h"
#include "../noyau/Prototype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    Prototype proto("configuration_simple.xml");

    FenetrePrincipale w(&proto);
    w.AjouterItems(proto.elements());
    w.show();



    return a.exec();
}
