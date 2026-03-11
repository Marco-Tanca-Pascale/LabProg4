#include "Experiencia.h"

//implementacion 

//implemento constructores y destructor
Experiencia::Experiencia(){

};

Experiencia::Experiencia(string codigoReserva,string descripcion,float precioBase,DTFecha fecha){
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
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


