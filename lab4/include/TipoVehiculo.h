#ifndef TIPO_VEHICULO_H
#define TIPO_VEHICULO_H
#include <iostream>

enum class TipoVehiculo {
    Auto,
    Moto
};

#endif
// sobrecarga del operador << 
std::ostream& operator<<(std::ostream& os, TipoVehiculo tipo);