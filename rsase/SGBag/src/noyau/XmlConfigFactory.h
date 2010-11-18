#ifndef MYXMLHANDLER_H
#define MYXMLHANDLER_H

#include <QtXml/QXmlDefaultHandler>
#include <QTextStream>
#include <QMap>
#include <QString>
#include <QVector>
#include <QPair>


class Element;

class XmlConfigFactory : public QXmlDefaultHandler
{
public:
    explicit XmlConfigFactory();

    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &str);

    Element* elementParId(int id);

    enum NodeName
    {
        config, /// Racine du fichier
        elementName, /// Nom de l'élément
        id, /// L'ID d'un élément
        x, /// Coordonnée en abscisse
        y, /// Coordonnée en ordonnée
        troncon, /// Un troncon de rail
            noeudDebut, // Noeud de début
            noeudFin, // Noeud de fin
        noeud, /// Un noeud
            suivantGauche, /// Le rail gauche suivant un noeud, toujours présent
            suivantDroit, /// Le rail droit suivant un noeud, parfois absent
        tapis, /// Tapis
        toboggan, /// Toboggan
        chariot, /// Chariot
            pos, /// Position d'origine du chariot, tapis ou toboggan
            tapisAssocie, /// Tapis associé au chariot
        vol, /// Un vol
            date, /// La date d'un vol, en secondes depuis l'epoch UNIX.
            nom, /// Le nom d'un vol
        _COUNT
    };

    static const char* NodeName_String[_COUNT];

    QList<QString> element_list;


    typedef QMap<QString,QString> IndexParamValeur;
    typedef QMap<QString,QVector<Element*> > IndexTypesElements;

    IndexTypesElements resultat();



private:
    bool noeudInterne;
    QString noeudTexte;
    QMap<QString,QString> mapParam;

    /**
     * @brief Map des types vers les instances.
     */
    IndexTypesElements types_elements;

    typedef QMap<int,QPair<Element*,IndexParamValeur> >  IndexIdInfosElements;
    IndexIdInfosElements _idInfosElements;

    void construireElement(const QMap<QString,QString>& mapParam);
};

#endif // MYXMLHANDLER_H
