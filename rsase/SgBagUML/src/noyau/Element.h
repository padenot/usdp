/**
  * @file Element.h
  * @author H4203
  */

#ifndef ELEMENT_H
#define ELEMENT_H


#define DEBUG_ACHEMINEMENT

#include <QPointF>
#ifdef DEBUG_ACHEMINEMENT
#include <QDebug>
#endif


#include "XmlConfigFactory.h"

//class Zone; //Dependency Generated Source:Element Target:Zone

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
/**
  * @class Element
  * @brief Classe mère de l'ensemble des éléments dynamique et statique du SGBag.
  */
class Element : public QObject
{
    Q_OBJECT
    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    // TODO : utiliser l'argument "parent" du constructeur de QObject
        Element(const XmlConfigFactory::IndexParamValeur& indexParamValeur);

        /** Initialise les membres privés de l'élément
          */
        virtual void init (const XmlConfigFactory::IndexParamValeur& indexParamValeur,
                           XmlConfigFactory& fabrique);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_Y1tCkOsVEd-oy8D834IawQ?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Element();

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_h21_IPD4Ed-R6YEVT5cViQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	/**
	  * Accesseur sur la position de l'élément
	  */
        virtual QPointF position() const;

#ifdef DEBUG_ACHEMINEMENT
        friend QDebug operator<<(QDebug dbg, const Element &element);
#endif

	/**
	  * Accesseur sur la clef primaire de l'élément 
	  */
        int id();

    protected:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_ncu9YOsVEd-oy8D834IawQ"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        //Zone * zone;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_YHgIwPG4Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        QPointF _position;

        int _id;

#ifdef DEBUG_ACHEMINEMENT
        QString _typeElement;
#endif

};  //end class Element
#endif
