#include <QtGui/QApplication>

#include "fenetreprincipale.h"
#include "../noyau/Prototype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale w;
    w.show();

    Prototype proto("configuration_simple.xml");

    return a.exec();
}
