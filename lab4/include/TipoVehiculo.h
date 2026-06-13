#ifndef TIPO_VEHICULO_H
#define TIPO_VEHICULO_H
#include <iostream>

// Agrego enum class asi no chocan los nombres de clases con valores de este enumerado
// Ahora para llamar un valor hay que utilizar TipoLibreta::X
enum class TipoVehiculo {
    Auto,
    Moto
};

#endif
// sobrecarga del operador << 
std::ostream& operator<<(std::ostream& os, TipoVehiculo tipo);