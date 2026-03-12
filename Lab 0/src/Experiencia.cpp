#include "Experiencia.h"

//implementacion 

//implemento constructores y destructor
Experiencia::Experiencia(){

};

Experiencia::Experiencia(string codigoReserva,string descripcion,float precioBase,DTFecha fecha, set<Turista*> turistas){
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
    // pseudoatributo para representar la asociacion con clase turista
    this->turistas = turistas;
}

Experiencia::~Experiencia(){
}

//implemento funciones
DTExpe Experiencia::getDT(){
    DTExpe dt(codigoReserva,descripcion,fecha);
    return dt;
}


float Experiencia::calcularCosto(){

};


