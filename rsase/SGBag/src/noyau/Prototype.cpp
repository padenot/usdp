#include <QXmlSimpleReader>
#include <QFile>
#include <QXmlInputSource>
#include <QDebug>

#include "Prototype.h"
#include "XmlConfigFactory.h"


//Begin section for file Prototype.cpp
//TODO: Add definitions that you want preserved
//End section for file Prototype.cpp

const int NOMBRE_CHANCE_BAGAGE_PAR_TICK = 10000;

const int Prototype::INTERVALLE_RAFRAICHISSEMENT_MODELE = 10; // En ms

const qreal Prototype::INTERVALLE_SIMULATION_DEFAUT =
        1.0 / Prototype::INTERVALLE_RAFRAICHISSEMENT_MODELE;
const qreal Prototype::INTERVALLE_SIMULATION_MAX = Prototype::INTERVALLE_SIMULATION_DEFAUT*2;
const qreal Prototype::INTERVALLE_SIMULATION_MIN = Prototype::INTERVALLE_SIMULATION_DEFAUT/2;


//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Prototype::Prototype(const QString& xmlfilepath) :
        QObject(0),
        _elementsParType(),
        _mode_generation_bagage(AUTOMATIQUE),
        _dt (INTERVALLE_SIMULATION_DEFAUT)
{
    // Désérialise le fichier XML.
    // Extrait et classe par type des pointeurs d'éléments.
    XmlConfigFactory handler;
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);

    QFile file(xmlfilepath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Cannot read XML file." << endl;
        exit(1);
    }

    QXmlInputSource xmlInputSource(&file);
    if (reader.parse(xmlInputSource))
    {
        _elementsParType = handler.resultat();

        qDebug() << _elementsParType;
    }

    _horloge.setInterval(INTERVALLE_RAFRAICHISSEMENT_MODELE);

    connect(&_horloge, SIGNAL(timeout()), this, SLOT(ajouterBagageAleatoire()));
    connect(&_horloge, SIGNAL(timeout()), this, SLOT(maj()));
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DESTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Prototype::~Prototype()
{
    foreach(QVector<Element*> tabElements, _elementsParType)
    {
        foreach(Element* element, tabElements)
        {
            delete element;
        }
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_oCLrkO59Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Prototype::changementMode(ModeSimulation mode)
{
    // TODO
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_0yUWMO59Ed-Jn7v3SB1Zsg"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Prototype::ajouterBagage(Tapis* tapis, Vol* vol)
{
}

void Prototype::ajouterBagageAleatoire()
{
    if( ! qrand()%NOMBRE_CHANCE_BAGAGE_PAR_TICK)
    {
        // Bagage* bagage = new Bagage(0);
        // _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::bagage]].append()
    }
}

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Eq-X8PCiEd-54vpurc77FA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void Prototype::changementModeAjoutBagage(ModeSimulation mode)
{
    //TODO Auto-generated method stub
}

void Prototype::commencerSimulation()
{
     _horloge.start();
}

void Prototype::arreterSimulation()
{
    _horloge.stop();
}

void Prototype::changerVitesse(int pourcentage)
{
    if (pourcentage > 100)
    {
        pourcentage = 100;
    }
    else if (pourcentage < 0)
    {
        pourcentage = 0;
    }

    _dt = INTERVALLE_SIMULATION_MIN +
          (INTERVALLE_SIMULATION_MAX-INTERVALLE_SIMULATION_MIN)*(pourcentage);
}

const XmlConfigFactory::IndexTypesElements &Prototype::elements()
{
    return _elementsParType;
}

void Prototype::maj()
{
    foreach(Element* chariot,
            _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
    {
        dynamic_cast<Chariot*>(chariot)->maj(_dt);
    }

    foreach(Element* tapis,
            _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
    {
        dynamic_cast<Tapis*>(tapis)->maj(_dt);
    }
}
