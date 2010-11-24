#include "Vol.h"

Vol::Vol(const QString& nom) : _dateDepart(0), _toboggan(0), _nom(nom)
{
    //TODO Auto-generated method stub
}

Vol::~Vol() 
{
    //TODO Auto-generated method stub
}

Toboggan* Vol::tobogganAssocie ()
{
    return _toboggan;
}

void Vol::associer(Toboggan* toboggan)
{
    _toboggan = toboggan;
}

QString Vol::nom()
{
    return _nom;
}
