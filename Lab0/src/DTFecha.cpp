#include "../include/DTFecha.h"

//Constructor de DTFecha
DTFecha::DTFecha() { dia = 1; mes = 1; anio = 2024; }
DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

//A continuacion, getters:

int DTFecha::getDia() const{
    return this->dia;
}

int DTFecha::getMes() const{
    return this->mes;
}

int DTFecha::getAnio() const{
    return this->anio;
}

//Método que retorna un bool dependiendo si la fecha actual es posterior a la fecha pasada por parámetro
bool DTFecha::esPosterior(DTFecha fecha) {
    if (anio > fecha.getAnio()) 
        return true;
    if (anio < fecha.getAnio()) 
        return false;
    
    // Si llegamos acá, los años son iguales
    if (mes > fecha.getMes()) 
        return true;
    if (mes < fecha.getMes()) 
        return false;
    
    // Si llegamos acá, años y meses son iguales
    return dia > fecha.getDia();
}

//Destructor de la clase DTFecha
DTFecha::~DTFecha() {}

std::ostream& operator<<(std::ostream& o, const DTFecha& fecha) {
    o << fecha.getDia() << "/" 
      << fecha.getMes() << "/" 
      << fecha.getAnio();
    return o;
}