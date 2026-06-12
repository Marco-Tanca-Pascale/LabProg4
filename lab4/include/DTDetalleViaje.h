#ifndef DT_DETALLE_VIAJE_H
#define DT_DETALLE_VIAJE_H

#include "DTFecha.h"
#include "DTDetalleVehiculo.h"
#include "DTDetalleReserva.h"
#include <string>
#include <set>
using namespace std;

class DTDetalleViaje {
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    int asientosPublicados;
    float precio;
    DTDetalleVehiculo vehiculo;
    set<DTDetalleReserva> reservas;

public:
    DTDetalleViaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, set<DTDetalleReserva> res);

    int getCodigo();
    DTFecha getFecha();
    string getOrigen();
    string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    DTDetalleVehiculo getVehiculo();
    set<DTDetalleReserva> getReservas();
};

#endif
