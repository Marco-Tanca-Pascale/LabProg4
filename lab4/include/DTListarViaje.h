#ifndef DT_LISTAR_VIAJE_H
#define DT_LISTAR_VIAJE_H

#include "DTFecha.h"
#include <iostream>
#include <string>
using namespace std;

class DTListarViaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    string conductor;
public:
    //constructores
    DTListarViaje();
    DTListarViaje(int codigo, DTFecha fecha, string origen, string destino, string conductor);

    //getters
    int getCodigo() const;
    DTFecha getFecha();
    string getOrigen();
    string getDestino();
    string getConductor();

    //operador sobrecargado
    bool operator<(const DTListarViaje& dtlv) const;
};

//operador de flujo sobrecargado
ostream& operator<<(ostream& o, const DTListarViaje dtlv);

#endif
