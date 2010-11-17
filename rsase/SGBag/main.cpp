#include <QtGui/QApplication>
#include "fenetreprincipale.h"

#include "Prototype.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale w;
    w.show();

    Prototype proto("../SGBag/configuration_simple.xml");

    return a.exec();
}
