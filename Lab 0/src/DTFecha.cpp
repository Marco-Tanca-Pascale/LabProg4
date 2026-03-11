#include "../include/DTFecha.h"

//Constructor de DTFecha
DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

//A continuacion, getters:

int DTFecha::getDia() {
    return this->dia;
}

int DTFecha::getMes() {
    return this->mes;
}

int DTFecha::getAnio() {
    return this->anio;
}

//Destructor de la clase DTFecha
DTFecha::~DTFecha() {}