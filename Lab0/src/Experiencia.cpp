#include "../include/Experiencia.h"
#include "../include/Turista.h"


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

//agrega un turista a una experiencia
void Experiencia::agregarTurista(Turista *t)
{
    turistas.insert(t);
}

//implemento funciones
DTExpe Experiencia::getDT(){
    DTExpe dt(codigoReserva,descripcion,fecha);
    return dt;
}

float Experiencia::getPrecioBase(){
    return this->precioBase;
}

set<Turista*> Experiencia::getTuristas(){
    return this->turistas;
}


float Experiencia::calcularCosto(){

};


