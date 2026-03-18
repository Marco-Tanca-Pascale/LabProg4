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

// Sobrecarga del operador << que permite imprimir un DTExpe con el formato:
// codigoReserva->descripcion(fecha)/turista1,turista2,.,turistaN 
ostream &operator<<(ostream &o, const DTExpe &exp)
{

    o << exp.getCodigoReserva() << "->";
    o << exp.getDescripcion() << "(" << exp.getFecha() << ")/";

    set<string> turistas = exp.getTuristas();

    bool primero = true;

    set<string>::iterator it;
    for (it = turistas.begin(); it != turistas.end();++it)
    {
        if (!primero)
            o << ",";
        o << it*;
        primero = false;
    }

    return o;
}