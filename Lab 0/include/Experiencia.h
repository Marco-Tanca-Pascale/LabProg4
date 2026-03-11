#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

//incluyo librerias 
//string no existe en el lenguaje base en C++
#include <string>
#include "DTFecha.h"
#include "DTExpe.h"

using namespace std;
//clase abstracta no podemos crear objetos de ella

class Experiencia{
    protected :
        string codigoReserva;
        string descripcion;
        int precioBase;
        DTFecha fecha;
        
    public :
    Experiencia();
    Experiencia(String codigoReserva,String descripcion,int precioBase,DTFecha fecha);
    virtual ~Experiencia();
    virtual float calcularCosto() = 0;
    DTExpe getDT();
};

#endif 