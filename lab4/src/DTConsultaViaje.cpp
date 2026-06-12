#include "../include/DTConsultaViaje.h"

DTConsultaViaje::DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string conductor, float calificacionProm, float precioTotal) {
    this->codigo = codigo;
    this->marca = marca;
    this->modelo = modelo;
    this->conductor = conductor;
    this->calificacionProm = calificacionProm;
    this->precioTotal = precioTotal;
}

int DTConsultaViaje::getCodigo() const { return codigo; }
std::string DTConsultaViaje::getMarca() { return marca; }
std::string DTConsultaViaje::getModelo() { return modelo; }
std::string DTConsultaViaje::getConductor() { return conductor; }
float DTConsultaViaje::getCalificacionProm() { return calificacionProm; }
float DTConsultaViaje::getPrecioTotal() { return precioTotal; }

bool DTConsultaViaje::operator<(const DTConsultaViaje& dtcv) const {
    return this->getCodigo() < dtcv.getCodigo();
}

std::ostream& operator<<(std::ostream& os, DTConsultaViaje dtcv) {
    os << "> Codigo: " << dtcv.getCodigo() << ", Marca: " << dtcv.getMarca() << ", Modelo: " << dtcv.getModelo() << ", Conductor: "<< dtcv.getConductor() <<", CalificacionPromedio: " << dtcv.getCalificacionProm() << ", PrecioTotal: " << dtcv.getPrecioTotal();
    return os;
}