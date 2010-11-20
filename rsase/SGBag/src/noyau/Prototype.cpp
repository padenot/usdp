#include <QXmlSimpleReader>
#include <QFile>
#include <QXmlInputSource>
#include <QDebug>

#include "Prototype.h"
#include "XmlConfigFactory.h"

//Begin section for file Prototype.cpp
//TODO: Add definitions that you want preserved
//End section for file Prototype.cpp

const int Prototype::INTERVALLE_DEFAUT = 1;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Prototype::Prototype(const QString& xmlfilepath) :
        QObject(0),
        _elementsParType(),
        _mode_generation_bagage(AUTOMATIQUE)
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

        foreach(Element* chariot,
                _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::chariot]])
        {
            connect(&_horloge,SIGNAL(timeout()),chariot,SLOT(maj()));
        }

        foreach(Element* tapis,
                _elementsParType[XmlConfigFactory::NodeName_String[XmlConfigFactory::tapis]])
        {
            connect(&_horloge,SIGNAL(timeout()),tapis,SLOT(maj()));
        }

        qDebug() << _elementsParType;
    }

    _horloge.setInterval(INTERVALLE_DEFAUT);
    commencerSimulation();
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
    //TODO Auto-generated method stub
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

void Prototype::changerVitesse(int msec)
{
    _horloge.setInterval(msec);
}

XmlConfigFactory::IndexTypesElements Prototype::elements()
{
    return _elementsParType;
}

