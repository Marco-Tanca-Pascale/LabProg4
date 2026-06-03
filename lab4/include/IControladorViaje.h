#ifndef IVIAJE_H
#define IVIAJE_H

#include "DTFecha.h"
using namespace std;

class IViaje {
public:
    virtual ~IViaje() {}
    
    virtual void altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) = 0;
    virtual void listarPasajeros() = 0;
    virtual void consultarViajes(DTFecha fecha, string origen, string destino, int asientos) = 0;
    virtual void listarViajes() = 0;
    virtual void detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
};

#endif