#ifndef MODELVOLS_H
#define MODELVOLS_H

#include <QAbstractTableModel>
#include <QVector>
#include "Vol.h"


/**
 * @todo TODO : Renommer en français.
 */
class ModelVols : public QAbstractTableModel
{
    Q_OBJECT
public:
    /**
     * Construit un model de vol, dont le but est d'être mappé sur une vue,
     * de type QTableView. Les interactions (suppressions d'éléments, ajout, etc.)
     * sont gérées automatiquement.
     */
    explicit ModelVols(QObject *parent = 0);
    /**
     * @brief Nombre de lignes
     * @return Le nombre de lignes du model, i.e. le nombre d'objets.
     * (évolue en fonction du model).
     */
    int rowCount(const QModelIndex&) const ;
    /**
     * @brief Le nombre de colonnes du model, i.e. le nombre de champs
     * dans les objets (constante).
     */
    int columnCount(const QModelIndex&) const;
    /**
     * Accesseur pour les données.
     */
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    /**
     * Accesseur en ecriture pour les données.
     */
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    /**
     * Ajouter un vol au model
     */
    void ajouterVol(Vol* vol);
    /**
     * Retirer un vol au model
     */
    void retirerVol(int index);

    /**
     * Données pour les entetes.
     */
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    /**
     * Prendre le index-ieme element du model.
     */
    Vol* at(int index);

signals:

public slots:

protected:
    static const char* LABEL_ENTETE[2];
    enum {
        kNom,
        kToboggan,
        _COUNT
    } _header_index;
    /**
     * Les données du model.
     */
    QVector<Vol*> _data;
    QVector<QString> _header;
};

#endif // MODELVOLS_H
