#include "vue.h"
#include "fenetreprincipale.h"

Vue::Vue(FenetrePrincipale& fenetrePrincipale) :
    _fenetrePrincipale(fenetrePrincipale)
{
    setFlags(QGraphicsItem::ItemIsSelectable);
}

const QMap<QString, QString>* Vue::parametres()
{
    QMap<QString, QString> *map = new QMap<QString, QString>();
    map->insert("tachatte","tachatte");

    return map;
}
