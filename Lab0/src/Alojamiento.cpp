#include "Alojamiento.h"

//implementacion 

//constructores
Alojamiento::Alojamiento() : Experiencia(){};

Alojamiento::Alojamiento(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas ,string hotel,TipoRegimen regimen, int cantNoches) :
Experiencia(codigoReserva, descripcion, precioBase,fecha){
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
};

/*En el caso de Alojamiento la
operación da como resultado el precio base multiplicado por la cantidad de noches y se le
agrega 10 unidades por cada noche si el régimen es all inclusive.*/

float Alojamiento::calcularCosto(){
    float rCosto = precioBase * cantNoches;

    if(regimen == AllInclusive){
        rCosto +=10 * cantNoches;
    }

    return rCosto;
};