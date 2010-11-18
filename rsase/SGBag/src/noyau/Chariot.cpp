#define DEBUG_CHARIOT

#include <QVector2D>
#ifdef DEBUG_CHARIOT
#include <QDebug>
#endif

#include "Chariot.h"
#include "Noeud.h"
#include "Tapis.h"
#include "Toboggan.h"
#include "XmlConfigFactory.h"


//Begin section for file Chariot.cpp
//TODO: Add definitions that you want preserved
//End section for file Chariot.cpp


const qreal Chariot::RAYON_PROXIMITE_NOEUD = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TAPIS = 1.0;
const qreal Chariot::RAYON_PROXIMITE_TOBOGGAN = 1.0;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
    ElementActif(indexParamValeur),
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
    _tronconActuel = dynamic_cast<Troncon*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()
            ));
    _tapisAssocie = dynamic_cast<Tapis*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapisAssocie]].toInt()
            ));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::~Chariot()
{
    delete _bagage;
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
    QVector2D deplacement(_tronconActuel->noeudFin()->position() - _position);
    deplacement.normalize();
    deplacement *= _vitesse;

    _position += deplacement.toPointF();
    if (_bagage != 0)
    {
        _bagage->simulerDeplacement(deplacement);
    }
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
        if (_bagage->objectifFinal()->estSupport(_tronconActuel) &&
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
        if (_tapisAssocie->estSupport(_tronconActuel) &&
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
    // Rien   faire
#ifdef DEBUG_CHARIOT
    qDebug() << this << "à l'arrêt.";
#endif
}

void Chariot::majNoeudAtteint()
{
    Troncon* troncon;
    if(_bagage != 0)
    {
        troncon = _bagage->objectifFinal()->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }
    else
    {
        troncon = _tapisAssocie->trouverObjectifImmediat(_tronconActuel->noeudFin());
    }

#ifdef DEBUG_CHARIOT
    qDebug() << this << "sur" << _tronconActuel << ", arrive sur" << _tronconActuel->noeudFin();
#endif

    if(troncon->occuper())
    {
        _tronconActuel->liberer();
        _tronconActuel = troncon;
        avancer();
#ifdef DEBUG_CHARIOT
        qDebug() << this << "passe sur" << troncon;
#endif
    }
#ifdef DEBUG_CHARIOT
    else
    {
        qDebug() << this << "attend son tour pour passer sur" << troncon;
    }
#endif
}

void Chariot::majTobogganAtteint()
{
#ifdef DEBUG_CHARIOT
    qDebug() << this << "donne son bagage à" << _bagage->objectifFinal();
#endif
    _bagage->objectifFinal()->transfererBagage(_bagage);
    _bagage = 0;
}

void Chariot::majLivraisonBagage()
{
    qDebug() << this << "avance avec" << _bagage;
    avancer();
}

void Chariot::majTapisAtteint()
{
#ifdef DEBUG_CHARIOT
    qDebug() << this << "a atteint son tapis" << _tapisAssocie;
#endif
    _tapisAssocie->connecter(this);
    arreter();
}

void Chariot::majRetourTapis()
{
    qDebug() << this << "retourne sur" << _tapisAssocie;
    avancer();
}
