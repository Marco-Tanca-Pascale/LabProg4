#include "../include/DTExpe.h"

DTExpe::DTExpe(std::string codigoReserva, std::string descripcion, DTFecha fecha, std::set<std::string> turistas) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->turistas = turistas;
}

std::string DTExpe::getCodigoReserva() {
    return this->codigoReserva;
}

std::string DTExpe::getDescripcion() {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() {
    return this->fecha;
}

std::set<std::string> DTExpe::getTuristas() {
    return this->turistas;
}

DTExpe::~DTExpe() {}