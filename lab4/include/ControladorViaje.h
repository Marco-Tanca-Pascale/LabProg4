#ifndef CONTROLADOR_VIAJE_H
#define CONTROLADOR_VIAJE_H

#include "IControladorViaje.h"

class ControladorViaje : public IViaje {
private:
    static ControladorViaje* instancia;

    ControladorViaje();

public:
    static ControladorViaje* getInstance();

    virtual void altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio) = 0;
    virtual void listarPasajeros() = 0;
    virtual void consultarViajes(DTFecha fecha, string origen, string destino, int asientosPublicados) = 0;
    virtual void listarViajes() = 0;
    virtual void detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
};

#endif