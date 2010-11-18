#include <QXmlSimpleReader>
#include <QFile>
#include <QXmlInputSource>
#include <QDebug>

#include "Prototype.h"
#include "XmlConfigFactory.h"

//Begin section for file Prototype.cpp
//TODO: Add definitions that you want preserved
//End section for file Prototype.cpp

const int Prototype::VITESSE_DEFAUT = 0;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_14GIsOyfEd-0NvPstdZN1w?DEFCONSTRUCTOR"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
Prototype::Prototype(const QString& xmlfilepath) :
        QObject(0),
        _elementsParType(),
        _vitesseSimulation(VITESSE_DEFAUT),
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

        qDebug() << _elementsParType;
    }
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

void Prototype::commencerSimulation(const int msec)
{
     _horloge.start(msec);
}

void Prototype::arreterSimulation()
{
    _horloge.stop();
}

void Prototype::changerVitesse(const int msec)
{

}

