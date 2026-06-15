#include "../include/DTDetalleVehiculo.h"

DTDetalleVehiculo::DTDetalleVehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo)
    {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

string DTDetalleVehiculo::getMatricula() { return matricula; }
int DTDetalleVehiculo::getCapacidad() { return capacidad; }
string DTDetalleVehiculo::getMarca() { return marca; }
string DTDetalleVehiculo::getModelo() { return modelo; }
TipoVehiculo DTDetalleVehiculo::getTipo() { return tipo; }
//sobrecarga del operador <<
ostream& operator<<(ostream& os, TipoVehiculo tipo) {
    switch (tipo) {
        case TipoVehiculo::Auto:
            os << "Auto";
            break;
        case TipoVehiculo::Moto:
            os << "Moto";
            break;
    }
    return os; 
}