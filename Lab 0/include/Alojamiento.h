#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

//incluyo librerias 
//string no existe en el lenguaje base en C++
#include <string>
#include "TipoRegimen.h"
#include "Experiencia.h"

using namespace std;

//hereda los atributos de experiencia
class Alojamiento: public Experiencia{
    private:
        string hotel;
        TipoRegimen regimen;
        int cantNoches;

    public:
        Alojamiento();
        Alojamiento(string codigoReserva, string descripcion, int precioBase, DTFecha fecha,string hotel,TipoRegimen regimen, int cantNoches);
        float calcularCosto();
};

#endif