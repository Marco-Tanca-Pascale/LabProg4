#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include <string>
using namespace std;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    int asientosPublicados;
    float precio;

public:
    Viaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio);
    ~Viaje();
    int getCodigo(); //agregué esto para que compilara att:avi
    DTListarViaje obtenerDatosViaje(string nickname);//igual con esto :)
    DTFecha getFecha();//y esto tmb 
};

#endif
