#ifndef DT_DETALLE_VEHICULO_H
#define DT_DETALLE_VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
using namespace std;

class DTDetalleVehiculo {
private:
    string matricula;
    int capacidad;
    string marca;
    string modelo;
    TipoVehiculo tipo;

public:
    //constructores
    DTDetalleVehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);
    
    //getters
    string getMatricula();
    int getCapacidad();
    string getMarca();
    string getModelo();
    TipoVehiculo getTipo();
};

#endif
