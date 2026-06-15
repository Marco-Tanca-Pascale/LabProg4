#ifndef TIPO_VEHICULO_H
#define TIPO_VEHICULO_H
using namespace std;
#include <iostream>

enum class TipoVehiculo {
    Auto,
    Moto
};

#endif
// sobrecarga del operador << 
ostream& operator<<(ostream& os, TipoVehiculo tipo);