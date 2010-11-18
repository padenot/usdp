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

    enum NodeName
    {
        elementName, /// Nom de l'élément
        config, /// Root
        troncon, /// Un troncon de rail
        id, /// L'ID d'un élément
        noeud, /// Un noeud
        x, /// Coordonnée
        y, /// Coordonnée
        suivant, /// Le(s) rail(s) suivant un noeud
        tapis, /// Un tapis (true si il doit y en avoir un)
        toboggan, /// Un toboggan (true si il doit y en avoir un)
        chariot, /// Chariot
        pos, /// Position d'origin du chariot
        bagage, /// Un bagage
        destination, /// L'ID de son vol
        vol, /// Un vol
        date, /// La date d'un vol, en seconde depuis l'epoch UNIX.
        nom, /// Le nom d'un vol
        _COUNT
    };

    typedef QMap<QString,QString> IndexParamValeur;
    typedef QMap<int,QPair<Element*,IndexParamValeur> >  IndexIdInfosElements;
    typedef QMap<QString,QVector<Element*> > IndexTypesElements;


    static const char* NodeName_String[_COUNT];
    QList<QString> element_list;
     QMap<QString,QVector<Element*> > mapSurTypes();
     IndexIdInfosElements mapSurId();



private:
    bool noeudInterne;
    QString noeudTexte;
    QMap<QString,QString> mapParam;
    /**
     * @brief Map des types vers les instances.
     */
    IndexTypesElements types_elements;
    IndexIdInfosElements _idInfosElements;
    void afficherElements(const QString& qname);
    void construireElements(const QMap<QString,QString>& mapParam);
};

#endif // MYXMLHANDLER_H
