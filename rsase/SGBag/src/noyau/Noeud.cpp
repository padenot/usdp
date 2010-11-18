
#include <limits>
#include<QVector2D>

#include "Noeud.h"
//Begin section for file Noeud.cpp
//TODO: Add definitions that you want preserved
//End section for file Noeud.cpp


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Noeud::Noeud()
    : _visite(false)
{
    //TODO Auto-generated method stub
}

void Noeud::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Element::init(indexParamValeur,fabrique);
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Noeud::~Noeud()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_bT8WAPD8Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Troncon* Noeud::trouverProchainTroncon(Troncon* destination)
{
    Troncon* troncon = 0;

    if(_tronconsSuivants.size()==1)
    {
        troncon = _tronconsSuivants.first();
    }
    else{
        troncon = calculChemin(destination).first;
    }

    return troncon;
}


QPair<Troncon*, qreal> Noeud::calculChemin(Troncon* destination)
{
    QPair<Troncon*, qreal> paireRetour;

    if(_visite)
    {
        paireRetour.first = 0;
        paireRetour.second = std::numeric_limits<qreal>::infinity();
        return paireRetour;
    }
    else
    {
        _visite = true;
        qreal tailleCheminMin = std::numeric_limits<qreal>::infinity();
        qreal tailleChemin = 0;
        Troncon* tronconMin = 0;

        foreach(Troncon* troncon, _tronconsSuivants)
        {
            if(troncon == destination)
            {
                paireRetour.first = troncon;
                paireRetour.second = 0;
                return paireRetour;
            }

            paireRetour = troncon->noeudFin()->calculChemin(destination);
            tailleChemin = paireRetour.second + QVector2D(troncon->noeudFin()->position() - troncon->position()).length();

            if(tailleCheminMin>tailleChemin)
            {
                tronconMin = troncon;
                tailleCheminMin = tailleChemin;
            }
        }

        paireRetour.first = tronconMin;
        paireRetour.second = tailleCheminMin;
        return paireRetour;
    }

}
