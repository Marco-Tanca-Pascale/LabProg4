#include "../include/DTVehiculosConductor.h"
#include "../include/DTDetalleVehiculo.h"
#include <vector>

DTVehiculosConductor::DTVehiculosConductor(string matricula, string modelo, int capacidad){
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

string DTVehiculosConductor::getMatricula() const {
    return this->matricula;
}

string DTVehiculosConductor::getModelo(){
    return this->modelo;
}

int DTVehiculosConductor::getCapacidad(){
    return this->capacidad;
}

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& dtvc) const {
    return this->getMatricula() < dtvc.getMatricula();
}

ostream& operator<<(ostream& os, DTVehiculosConductor dtvc) {
    os << "> Matricula: " << dtvc.getMatricula() << ", Modelo: " << dtvc.getModelo() << ", Capacidad: " << dtvc.getCapacidad();
    return os;
}