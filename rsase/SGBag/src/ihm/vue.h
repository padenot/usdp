#ifndef VUE_H
#define VUE_H

#include <QGraphicsItem>

class FenetrePrincipale;

class Vue: public QGraphicsItem
{
public:
    Vue(FenetrePrincipale& fenetrePrincipale);
    virtual const QMap<QString, QString>* ackParametres();

protected :

    /**
     * @var fenetrePrincipale Référence vers la fenêtre principale.
     */
    FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUE_H
