#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include <string>

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    int getCodigo(); //agregué esto para que compilara att:avi
    DTListarViaje obtenerDatosViaje(std::string nickname);//igual con esto :)
    DTFecha getFecha();//y esto tmb 
};

#endif
