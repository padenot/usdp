#ifndef VUE_CANEVAS_H
#define VUE_CANEVAS_H

#include <QGraphicsItem>

class FenetrePrincipale;

class VueCanevas: public QGraphicsItem
{
public:
    VueCanevas(FenetrePrincipale& fenetrePrincipale);

protected :

    /**
     * @var fenetrePrincipale Référence vers la fenêtre principale.
     */
    FenetrePrincipale& _fenetrePrincipale;
};

#endif // VUE_CANEVAS_H
