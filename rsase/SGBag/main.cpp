#include <QtGui/QApplication>
#include "fenetreprincipale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetrePrincipale w;
    w.show();

    return a.exec();
}
