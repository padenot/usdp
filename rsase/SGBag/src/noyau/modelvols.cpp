#include "modelvols.h"
#include <QDebug>

const char* ModelVols::LABEL_ENTETE[ModelVols::_COUNT] = {
    "Nom",
    "Toboggan"
};

ModelVols::ModelVols(QObject *parent)
:QAbstractTableModel(parent)
{

    _header.push_back(LABEL_ENTETE[kNom]);
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
    if(role == Qt::DisplayRole)
    {
        if(index.column() == kNom)
            return QVariant(_data[index.row()]->nom());
    }
    return QVariant();
}

bool ModelVols::setData(const QModelIndex & index, const QVariant & value, int role)
{
//    if(index.column() == kToboggan)
//        _data[index.row()]->associer(value);
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
    qDebug() << "Retirer Vol :)";
    _data.remove(index);
    endRemoveRows();
}

QVariant ModelVols::headerData ( int section, Qt::Orientation orientation, int role) const
{
    if(section == kNom)
        return QVariant(LABEL_ENTETE[kNom]);
    return QVariant();
}

Vol* ModelVols::at(int index)
{
    if(index < _data.size())
        return _data[index];
}


