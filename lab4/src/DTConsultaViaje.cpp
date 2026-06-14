#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, string marca, string modelo, string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

DTConsultaViaje::DTConsultaViaje() {
    this->codigo = 0;
    this->marca = "";
    this->modelo = "";
    this->conductor = "";
    this->calificacionProm = 0.0;
    this->precioTotal = 0.0;
}

int DTConsultaViaje::getCodigo() const { return codigo; }
string DTConsultaViaje::getMarca() { return marca; }
string DTConsultaViaje::getModelo() { return modelo; }
string DTConsultaViaje::getConductor() { return conductor; }
float DTConsultaViaje::getCalificacionProm() { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() { return precioTotal; }

bool DTConsultaViaje::operator<(const DTConsultaViaje& dtcv) const {
    return this->getCodigo() < dtcv.getCodigo();
}

ostream& operator<<(ostream& os, DTConsultaViaje dtcv) {
    os << " Codigo: " << dtcv.getCodigo() << ", Marca: " << dtcv.getMarca() << ", Modelo: " << dtcv.getModelo() << ", Conductor: "<< dtcv.getConductor() <<", CalificacionPromedio: " << dtcv.getCalificacionProm() << ", PrecioTotal: " << dtcv.getPrecioTotal();
    return os;
}