#include <QtGui/QApplication>

#include "fenetreprincipale.h"
#include "../noyau/Prototype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Prototype proto("configuration_simple.xml");

    FenetrePrincipale w(&proto);
    w.show();



    return a.exec();
}
