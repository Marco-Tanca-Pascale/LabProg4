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

//Método que retorna un bool dependiendo si la fecha actual es posterior a la fecha pasada por parámetro
bool DTFecha::esPosterior(DTFecha fecha){
    return ( anio > fecha.getAnio() || anio == fecha.getAnio() && mes > fecha.getMes() || anio == fecha.getAnio() && mes == fecha.getMes() && dia > fecha.getDia());
}

//Destructor de la clase DTFecha
DTFecha::~DTFecha() {}