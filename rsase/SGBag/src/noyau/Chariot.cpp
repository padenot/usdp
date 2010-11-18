#include "Chariot.h"
#include "Troncon.h"
#include "Noeud.h"
//Begin section for file Chariot.cpp
//TODO: Add definitions that you want preserved
//End section for file Chariot.cpp


const qreal Chariot::RAYON_PROXIMITE_NOEUD = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TAPIS = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TOBOGGAN = 1.0;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::Chariot(const QMap<QString,QString>& mapParam)
    :ElementActif(mapParam),
    _bagage (0),
    _tronconActuel (0),
    _tapisAssocie (0)
{
    //TODO Auto-generated method stub
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


Etat Chariot::etat()
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
        if (_bagage->estDestination(_tronconActuel) &&
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
        if (_tapisAssocie->estDestination(_tronconActuel) &&
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

void majArret()
{
    // Rien à faire
}

void majNoeudAtteint()
{
    // TODO
}

void majTobogganAtteint()
{
    // TODO
}

void majLivraisonBagage()
{
    // TODO
}

void majTapisAtteint()
{
    // TODO
}

void majRetourTapis()
{
    // TODO
}
