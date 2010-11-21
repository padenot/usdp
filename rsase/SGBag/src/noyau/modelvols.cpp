#include "modelvols.h"
#include <QDebug>

const char* ModelVols::LABEL_ENTETE[ModelVols::_COUNT] = {
    "Nom",
    "Toboggan"
};

ModelVols::ModelVols(QObject *parent)
:QAbstractTableModel(parent)
{
    _header.push_back(LABEL_ENTETE[Nom]);
    _header.push_back(LABEL_ENTETE[Toboggan]);
//    setHeaderData(0, Qt::Horizontal, _header[0]);
//    setHeaderData(1, Qt::Horizontal, _header[1]);
    ajouterVol(new Vol("plop"));
    ajouterVol(new Vol("plap"));
}

int ModelVols::rowCount(const QModelIndex&) const
{
    return _data.size();
}

int ModelVols::columnCount(const QModelIndex&) const
{
    return _header.size();
}

QVariant ModelVols::data(const QModelIndex & index, int role) const
{
    if(index.column() == Nom)
        return QVariant(_data[index.row()]->nom());
    if(index.column() == Toboggan)
        return QVariant(_data[index.row()] ? false : true);
    return QVariant();
}

void ModelVols::ajouterVol(Vol* vol)
{
    beginInsertRows(QModelIndex(), _data.size(), _data.size()+1);
    _data.push_back(vol);
    endInsertRows();
}

void ModelVols::retirerVol(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    _data.remove(index);
    endRemoveRows();
}

QVariant ModelVols::headerData ( int section, Qt::Orientation orientation, int role) const
{
    if(section == Nom)
        return QVariant(LABEL_ENTETE[Nom]);
    if(section == Toboggan)
        return QVariant(LABEL_ENTETE[Toboggan]);
    return QVariant();
}

Vol* ModelVols::at(int index)
{
    if(index < _data.size())
        return _data[index];
}


