#include <QDebug>

#include "XmlConfigFactory.h"
#include "Elements.h"

const char* XmlConfigFactory::NodeName_String[] = {
    "config", /// Racine du fichier
    "elementName", /// Nom de l'élément
    "id", /// L'ID d'un élément
    "x", /// Coordonnée en abscisse
    "y", /// Coordonnée en ordonnée
    "troncon", /// Un troncon de rail
        "noeudDebut", // Noeud de début
        "noeudFin", // Noeud de fin
    "noeud", /// Un noeud
        "suivantGauche", /// Le rail gauche suivant un noeud, toujours présent
        "suivantDroit", /// Le rail droit suivant un noeud, parfois absent
    "tapis", /// Tapis
    "toboggan", /// Toboggan
    "chariot", /// Chariot
        "pos", /// Position d'origine du chariot, tapis ou toboggan
        "tapisAssocie", /// Tapis associé au chariot
    "vol", /// Un vol
        "date", /// La date d'un vol, en secondes depuis l'epoch UNIX.
        "nom", /// Le nom d'un vol
};


XmlConfigFactory::XmlConfigFactory()
    :noeudInterne(false)
{
    element_list.append(NodeName_String[troncon]);
    element_list.append(NodeName_String[noeud]);
    element_list.append(NodeName_String[chariot]);
    element_list.append(NodeName_String[toboggan]);
    element_list.append(NodeName_String[tapis]);
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
        construireElement(mapParam);
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

Element* XmlConfigFactory::elementParId(int id)
{
    IndexIdInfosElements::const_iterator it = _idInfosElements.find(id);
    if (it != _idInfosElements.end())
    {
        return it->first;
    }
    else
    {
        return 0;
    }
}

void XmlConfigFactory::construireElement(const QMap<QString,QString>& mapParam)
{
    Element* nElement = 0;
    //  printElement(mapParam[NodeName_String[elementName]]);
    if(mapParam[NodeName_String[elementName]] == NodeName_String[troncon])
    {
        nElement = new Troncon(mapParam);
        types_elements[NodeName_String[troncon]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == NodeName_String[noeud])
    {
        nElement = new Noeud(mapParam);
        types_elements[NodeName_String[noeud]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == NodeName_String[chariot])
    {
        nElement = new Chariot(mapParam);
        qDebug() << "construction d'un chariot : " << nElement;
        types_elements[NodeName_String[chariot]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == NodeName_String[toboggan])
    {
        nElement = new Toboggan(mapParam);
        types_elements[NodeName_String[toboggan]].push_back(nElement);
    }
    else if(mapParam[NodeName_String[elementName]] == NodeName_String[tapis])
    {
        nElement = new Tapis(mapParam);
        types_elements[NodeName_String[tapis]].push_back(nElement);
    }

    _idInfosElements[mapParam[NodeName_String[id]].toInt()]=qMakePair(nElement,mapParam);
}

XmlConfigFactory::IndexTypesElements XmlConfigFactory::resultat()
{
    typedef QPair<Element*,IndexParamValeur> Paire;
    // Nécessaire pour utiliser la macro foreach (problème
    // de parsing s'il y a une virgule dans un type)

    foreach(Paire paire, _idInfosElements)
    {
        paire.first->init(paire.second,*this);
    }

    return types_elements;
}



