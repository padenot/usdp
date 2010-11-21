#ifndef MODELVOLS_H
#define MODELVOLS_H

#include <QAbstractTableModel>
#include <QVector>
#include "Vol.h"

class ModelVols : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelVols(QObject *parent = 0);
    int rowCount();
    int columnCount();
    QVariant data();
signals:

public slots:

protected:
    QVector<Vol*> _data;
};

#endif // MODELVOLS_H
