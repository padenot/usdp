#include "Chariot.h"
#include "Troncon.h"
#include "Noeud.h"
#include "Tapis.h"
#include "XmlConfigFactory.h"

#include <QVector2D>
//Begin section for file Chariot.cpp
//TODO: Add definitions that you want preserved
//End section for file Chariot.cpp


const qreal Chariot::RAYON_PROXIMITE_NOEUD = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TAPIS = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TOBOGGAN = 1.0;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::Chariot() :
    _bagage (0),
    _tronconActuel (0),
    _tapisAssocie (0)
{

    //TODO Auto-generated method stub
}

void Chariot::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::~Chariot()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_XNzMkO52Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::chargerBagage(Bagage* bagage)
{
    _bagage = bagage;
    // TODO : positionner le bagage exactement sur le chariot
    _tapisAssocie->deconnecter();
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::dechargerBatterie()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::avancer()
{
    //TODO Auto-generated method stub
}


void Chariot::maj()
{
    switch (etat())
    {
        case ARRET :            majArret(); break;
        case NOEUD_ATTEINT :    majNoeudAtteint(); break;
        case TOBOGGAN_ATTEINT : majTobogganAtteint(); break;
        case LIVRAISON_BAGAGE : majLivraisonBagage(); break;
        case TAPIS_ATTEINT :    majTapisAtteint(); break;
        case RETOUR_TAPIS :     majRetourTapis(); break;
    }

}


Chariot::Etat Chariot::etat()
{
    if (QVector2D(_tronconActuel->noeudFin()->position() - _position).length()
        < RAYON_PROXIMITE_NOEUD)
    {
        // On est sur le noeud de fin du tronçon actuel
        return NOEUD_ATTEINT;
    }
    else if (_bagage != 0)
    {
        // Livraison de bagage en cours
        if (_bagage->estObjectifFinal(_tronconActuel) &&
            QVector2D(_tronconActuel->noeudFin()->position() - _tronconActuel->position()).length()
                    < RAYON_PROXIMITE_NOEUD)
        {
            return TOBOGGAN_ATTEINT;
        }
        else
        {
            return LIVRAISON_BAGAGE;
        }
    }
    else
    {
        // Retour au tapis en cours
        if (_tapisAssocie->estObjectifFinal(_tronconActuel) &&
            QVector2D(_tronconActuel->noeudFin()->position() - _tronconActuel->position()).length()
                    < RAYON_PROXIMITE_NOEUD)
        {
            return TAPIS_ATTEINT;
        }
        else
        {
            return RETOUR_TAPIS;
        }
    }
}

void Chariot::majArret()
{
    // Rien à faire
}

void Chariot::majNoeudAtteint()
{
    // TODO
}

void Chariot::majTobogganAtteint()
{
    // TODO
}

void Chariot::majLivraisonBagage()
{
    // TODO
}

void Chariot::majTapisAtteint()
{
    // TODO
}

void Chariot::majRetourTapis()
{
    // TODO
}
