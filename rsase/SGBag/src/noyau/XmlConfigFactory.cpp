#include <QDebug>

#include "XmlConfigFactory.h"
#include "Elements.h"

const char* XmlConfigFactory::NodeName_String[] = {
    "elementName", /// Nom de l'élément
    "config", /// Root
    "troncon", /// Un troncon de rail
    "id", /// L'ID d'un élément
    "noeud", /// Un noeud
    "x", /// Coordonnée
    "y", /// Coordonnée
    "suivant", /// Le(s) rail(s) suivant un noeud
    "tapis", /// Un tapis
    "toboggan", /// Un toboggan
    "chariot", /// Chariot
    "pos", /// Position d'origin du chariot
    "bagage", /// Un bagage
    "destination", /// L'ID de son vol
    "vol", /// Un vol
    "date", /// La date d'un vol, en seconde depuis l'epoch UNIX.
    "nom" /// Le nom d'un vol
};


XmlConfigFactory::XmlConfigFactory()
    :noeudInterne(false)
{
    element_list.append("troncon");
    element_list.append("noeud");
    element_list.append("chariot");
    element_list.append("bagage");
    element_list.append("vol");
}


bool XmlConfigFactory::startElement(const QString &/*namespaceURI*/,
                                const QString &/*localName*/,
                                const QString &qname,
                                const QXmlAttributes & /*attributes*/)
{
    if(element_list.contains(qname))
    {
        noeudInterne = true;
    }
    return true;
}


bool XmlConfigFactory::endElement(const QString &/*namespaceURI*/,
                              const QString &/*localName*/,
                              const QString &qname)
{
    if(element_list.contains(qname))
    {
        mapParam[NodeName_String[elementName]] = qname;
        noeudInterne = false;
        construireElements(mapParam);
        mapParam.clear();
    }
    else
    {
        mapParam[qname] = noeudTexte.trimmed();
    }

    noeudTexte.clear();

    return true;
}

bool XmlConfigFactory::characters(const QString &str)
{
        if( ! str.isEmpty())
                noeudTexte += str;
        return true;
}

/**
 * For debugging
 */
void XmlConfigFactory::afficherElements(const QString& qname)
{
    qDebug() << qname << " " << mapParam;
}


void XmlConfigFactory::construireElements(const QMap<QString,QString>& mapParam)
{
    Element* nElement = 0;
    //  printElement(mapParam[NodeName_String[elementName]]);
    if(mapParam[NodeName_String[elementName]] =="troncon")
    {
        nElement = new Troncon();
        types_elements[NodeName_String[troncon]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == "noeud")
    {
        nElement = new Noeud();
        types_elements[NodeName_String[noeud]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == "chariot")
    {
        nElement = new Chariot();
        types_elements[NodeName_String[chariot]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == "bagage")
    {
        nElement = new Bagage();
        types_elements[NodeName_String[bagage]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == "toboggan")
    {
        nElement = new Toboggan();
        types_elements[NodeName_String[toboggan]].push_back(nElement);
    }

    _idInfosElements[mapParam[NodeName_String[id]].toInt()]=qMakePair(nElement,mapParam);
}

QMap<QString,QVector<Element*> > XmlConfigFactory::mapSurTypes()
{
    return types_elements;
}

XmlConfigFactory::IndexIdInfosElements XmlConfigFactory::mapSurId()
{
    return _idInfosElements;
}


