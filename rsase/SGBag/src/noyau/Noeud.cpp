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
Noeud::Chemin Noeud::trouverChemin(Troncon* destination)
{
    Chemin chemin;

    if(destination != 0)
    {
        if (_tronconsSuivants.size()==1)
        {
    #ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : aucun choix possible, continuer";
    #endif
            chemin.push(_tronconsSuivants.first());
        }
        else
        {
            chemin = calculChemin(destination).first;
    #ifdef DEBUG_ACHEMINEMENT
            if (chemin.empty())
            {
                qDebug() << *this << "Aucun chemin !";
            }
            else
            {
                /*qDebug() << *this << "dit : il faut aller a"
                        << (resultat == _tronconsSuivants.first() ? "gauche" : "droite")
                        << ", sur" << *resultat;*/
            }
    #else
    #endif

        }
    }

    return chemin;
}

Noeud::Chemin Noeud::trouverChemin(Direction direction)
{
    Chemin chemin;

    if (_tronconsSuivants.size() == 1)
    {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << "dit : aucun choix possible, continuer";
#endif
        chemin.push(_tronconsSuivants.first());
    }
    else
    {
        if (direction == GAUCHE)
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << ": tu veux aller à gauche, va sur"
                    << *_tronconsSuivants[0];
#endif
            chemin.push(_tronconsSuivants[0]);
        }
        else
        {
#ifdef DEBUG_ACHEMINEMENT
            qDebug() << *this << ": tu veux aller à droite, va sur"
                    << *_tronconsSuivants[1];
#endif
            chemin.push(_tronconsSuivants[1]);
        }
    }

    return chemin;
}


QPair<Noeud::Chemin, double> Noeud::calculChemin(Troncon* destination)
{
    QPair<Chemin, double> paireMin = qMakePair(Chemin(),
                                   std::numeric_limits<double>::infinity());
    // TODO : implémenter un algorithme plus efficace
    // TODO : Proposition à discuter (pas forcément idéal) :
    //        Lorsqu'un tapis/toboggan est inaccessible (à cause de tronçons hors service), continuer
    //        à avancer jusqu'à être VRAIMENT bloqué, pour libérer les voies. Actuellement on
    //        s'arrête dès qu'on détecte que le chemin est bloqué.

    if(!_visite)
    {
        _visite = true;

        foreach(Troncon* troncon, _tronconsSuivants)
        {
            if (troncon->etat() != Troncon::HORS_SERVICE)
            {
                if (troncon == destination)
                {
                    paireMin.first.push(troncon);
                    paireMin.second = 0;
                    break;
                }
                else
                {
                    QPair<Chemin, double> paireRetour(troncon->noeudFin()->calculChemin(destination));
                    paireRetour.second += QVector2D(troncon->noeudFin()->position()
                                            - _position).length();

                    if(paireRetour.second < paireMin.second)
                    {
                        paireMin = paireRetour;
                    }
                }
            }
        }

        _visite = false;
    }

    return paireMin;
}

