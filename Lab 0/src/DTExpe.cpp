#include "../include/DTExpe.h"

//Constructor de la clase DTExpe
DTExpe::DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string> turistas) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->turistas = turistas;
}

//A continuacion, getters:

string DTExpe::getCodigoReserva() {
    return this->codigoReserva;
}

string DTExpe::getDescripcion() {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() {
    return this->fecha;
}

set<string> DTExpe::getTuristas() {
    return this->turistas;
}

//Destructor de la clase DTExpe
DTExpe::~DTExpe() {}