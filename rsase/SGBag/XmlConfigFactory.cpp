#include "XmlConfigFactory.h"

#include <QDebug>

const char* XmlConfigFactory::NodeName_String[] = {
    "elementName", /// Nom de l'élément
    "config", /// Root
    "troncon", /// Un troncon de rail
    "id", /// L'ID d'un élément
    "noeud", /// Un noeud
    "x", /// Coordonnée
    "y", /// Coordonnée
    "suivant", /// Le(s) rail(s) suivant un noeud
    "tapis", /// Un tapis (true si il doit y en avoir un)
    "toboggan", /// Un toboggan (true si il doit y en avoir un)
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
  //  printElement(mapParam[NodeName_String[elementName]]);
    if(mapParam[NodeName_String[elementName]] =="troncon")
    {
//        Troncon* ttroncon = new Troncon(mapParam);
//        types_elements[NodeName_String[troncon]].push_back(ttroncon);
//        id_elements[mapParam[NodeName_String[id]].toInt()]=ttroncon;
    }
    else if(mapParam[NodeName_String[elementName]] == "noeud")
    {
//        Noeud* nnoeud = new Noeud(mapParam);
//        types_elements[NodeName_String[noeud]].push_back(nnoeud);
//        id_elements[mapParam[NodeName_String[id]].toInt()] = nnoeud;
    }
    else if(mapParam[NodeName_String[elementName]] == "chariot")
    {
//        Chariot* cchariot = new Chariot(mapParam);
//        types_elements[NodeName_String[chariot]].push_back(cchariot);
//        id_elements[mapParam[NodeName_String[id]].toInt()]=cchariot;
    }
    else if(mapParam[NodeName_String[elementName]] == "bagage")
    {
//        Bagage* bbagage = new Bagage(mapParam);
//        types_elements[NodeName_String[bagage]].push_back(bbagage);
//        id_elements[mapParam[NodeName_String[id]].toInt()]=bbagage;
    }
    else if(mapParam[NodeName_String[elementName]] == "vol")
    {
//        Vol* vvol = new Vol(mapParam);
//        types_elements[NodeName_String[vol]].push_back(vvol);
//        id_elements[mapParam[NodeName_String[id]].toInt()]=vvol;
    }
}

QMap<QString,QVector<Element*> > XmlConfigFactory::mapSurTypes()
{
    return types_elements;
}

QMap<int,Element*> XmlConfigFactory::mapSurId()
{
    return id_elements;
}


