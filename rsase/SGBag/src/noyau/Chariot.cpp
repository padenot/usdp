#include <QVector2D>

#include "Chariot.h"
#include "Troncon.h"
#include "Tapis.h"
#include "XmlConfigFactory.h"
#include "StrategiePilotageAuto.h"
#include "StrategiePilotageManuel.h"

const double Chariot::ACCELERATION_CHARIOT = 0.001; // m/s²
const double Chariot::DECELERATION_CHARIOT = 0.002; // m/s²
const double Chariot::VITESSE_NULLE = 0.001; // m/s
//Begin section for file Chariot.cpp
//TODO: Add definitions that you want preserved
//End section for file Chariot.cpp

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::Chariot(const XmlConfigFactory::IndexParamValeur& indexParamValeur) :
    ElementActif(indexParamValeur),
    _bagage (0),
    _directionConseillee (GAUCHE),
    _typePilotage (AUTOMATIQUE),
    _pilote (0)
{
}

void Chariot::init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                   XmlConfigFactory& fabrique)
{
    ElementActif::init(indexParamValeur,fabrique);
    Troncon* tronconActuel = 0;
    Tapis* tapisAssocie = 0;

    tronconActuel = dynamic_cast<Troncon*>(fabrique.elementParId(
        indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::pos]].toInt()
        ));
    tapisAssocie = dynamic_cast<Tapis*>(fabrique.elementParId(
            indexParamValeur[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapisAssocie]].toInt()));

    _position = tronconActuel->position();
    _pilote = new StrategiePilotageAuto(*this, tronconActuel, tapisAssocie);
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_8wh8EOseEd-oy8D834IawQ?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Chariot::~Chariot()
{
    // _bagage est détruit par le prototype
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_XNzMkO52Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::chargerBagage(Bagage* bagage)
{
    _bagage = bagage;
    // TODO : positionner le bagage exactement sur le chariot
    demarrer(); // TODO : déplacer dans stratégie pilotage
}

Bagage* Chariot::dechargerBagage()
{
    Bagage* bagage = _bagage;
    _bagage = 0;
    return bagage;
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_pgh1sO55Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::dechargerBatterie()
{
    //TODO Auto-generated method stub
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_r3Lz8PD-Ed-R6YEVT5cViQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Chariot::avancer(double dt, QPointF destination)
{
    QVector2D deplacement(destination - _position);
    deplacement.normalize();

    if (_estActif)
    {
        if (_vitesse < _vitesseMax)
        {
            _vitesse += ACCELERATION_CHARIOT*dt;
            emit vitesseModifiee(_vitesse);
        }
    }
    else
    {
        if (_vitesse > VITESSE_NULLE)
        {
            _vitesse -= DECELERATION_CHARIOT*dt;
            emit vitesseModifiee(_vitesse);
        }
    }

    if (_vitesse > VITESSE_NULLE)
    {
        deplacement *= _vitesse * dt;
        _position += deplacement.toPointF();
        if (_bagage != 0)
        {
            _bagage->simulerDeplacement(deplacement);
        }
    }
}

void Chariot::maj(double dt)
{
    avancer(dt,_pilote->piloter(_directionConseillee,_bagage));
}


Chariot::TypePilotage Chariot::typePilotage()
{
    return _typePilotage;
}

Direction Chariot::directionConseillee()
{
    return _directionConseillee;
}

void Chariot::modifierTypePilotage(TypePilotage type)
{
    StrategiePilotage* ancienPilote = _pilote;
    if (type != _typePilotage)
    {
        switch(type)
        {
            case AUTOMATIQUE :
                _pilote = new StrategiePilotageAuto(*_pilote);
                break;
            case MANUEL :
                _pilote = new StrategiePilotageManuel(*_pilote);
                break;
        }

        _typePilotage = type;

        delete ancienPilote;
    }
}

void Chariot::modifierDirectionConseillee(Direction direction)
{
    _directionConseillee = direction;
}
