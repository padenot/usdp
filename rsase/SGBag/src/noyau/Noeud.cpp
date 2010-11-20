#include <limits>
#include<QVector2D>

#include "Noeud.h"
//Begin section for file Noeud.cpp
//TODO: Add definitions that you want preserved
//End section for file Noeud.cpp

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_R4640OskEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Noeud::Noeud(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
        Element(indexParamValeur),
        _tronconsSuivants(),
        _visite(false)
{
    //TODO Auto-generated method stub
}

void Noeud::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    Troncon* suivantDroit = 0;
    Element::init(indexParamValeur,fabrique);
    _tronconsSuivants.push_back(dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::suivantGauche]].toInt())));

    suivantDroit = dynamic_cast<Troncon*> (fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::suivantDroit]].toInt()));
    if (suivantDroit != 0)
    {
        _tronconsSuivants.push_back(suivantDroit);
    }
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
    if(destination == 0)
    {
        return 0;
    }
    else if (_tronconsSuivants.size()==1)
    {
#ifdef DEBUG_ACHEMINEMENT
        qDebug() << this << "Aucun choix possible, continuer";
#endif
        return _tronconsSuivants.first();
    }
    else
    {

#ifdef DEBUG_ACHEMINEMENT
        Troncon* resultat = calculChemin(destination).first;
        qDebug() << this << "Il faut aller a"
                << (resultat == _tronconsSuivants.first() ? "gauche" : "droite");
        return resultat;
#else
        return calculChemin(destination).first;
#endif

    }
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
#ifdef DEBUG_ACHEMINEMENT
        int noNoeud = 0, noNoeudMin = 0;
#endif
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

#ifdef DEBUG_ACHEMINEMENT
                qDebug() << this << "Troncon destination atteint :" << (noNoeud == 0 ? "Gauche" : "Droite");
#endif
                _visite = false;
                return paireRetour;
            }

            paireRetour = troncon->noeudFin()->calculChemin(destination);
            tailleChemin = paireRetour.second + QVector2D(troncon->noeudFin()->position() - troncon->position()).length();

            if(tailleCheminMin>tailleChemin)
            {
                tronconMin = troncon;
                tailleCheminMin = tailleChemin;
#ifdef DEBUG_ACHEMINEMENT
                int noNoeudMin = noNoeud;
#endif
            }

#ifdef DEBUG_ACHEMINEMENT
            ++noNoeud;
#endif
        }

        _visite = false;



        paireRetour.first = tronconMin;
        paireRetour.second = tailleCheminMin;
        return paireRetour;
    }

}


#ifdef DEBUG_ACHEMINEMENT
QDebug operator<<(QDebug dbg, const Noeud *noeud)
{
    dbg.nospace() << "Noeud(" << noeud->id() << ")";

    return dbg.space();
}
#endif
