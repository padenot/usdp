#ifndef VOL_H
#define VOL_H
//Begin section for file Vol.h
//TODO: Add definitions that you want preserved
//End section for file Vol.h

#include <QString>
#include <QMap>

class Troncon;
class Bagage; //Dependency Generated Source:Vol Target:Bagage
class Toboggan;

//@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA"
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
class Vol
{

    //Begin section for Vol
    //TODO: Add attributes that you want preserved
    //End section for Vol

    private:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_j91OhPCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Bagage * _bagage;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_c8bTgPG8Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        unsigned  long _dateDepart;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_lueswvCwEd-54vpurc77FA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Toboggan * _toboggan;

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_O3of4PG4Ed-XFOLnxrkHLA"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        const QString _nom;

    public:

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DEFCONSTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        Vol(const QString& nom);

        //@uml.annotationsderived_abstraction="platform:/resource/usdp/ModeleStructurel.emx#_gpyD0PCwEd-54vpurc77FA?DESTRUCTOR"
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~Vol();

        /** R�cup�re le toboggan sur lequel doivent être déversés les bagages de ce vol.
          * Peut être nul si le vol n'est pas associé �  un toboggan.
          * @return Le toboggan associé au vol, s'il existe.
          */
        Toboggan* tobogganAssocie ();
        void associer(Toboggan* toboggan);


        QString nom();


};  //end class Vol

#endif
