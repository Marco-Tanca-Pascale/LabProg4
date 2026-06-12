#include "../include/DTDetalleViaje.h"

DTDetalleViaje::DTDetalleViaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio, DTDetalleVehiculo vehi, set<DTDetalleReserva> res):
    codigo(codigo),
    fecha(fecha),
    origen(origen),
    destino(destino),
    asientosPublicados(asientosPublicados),
    precio(precio),
    vehiculo(vehi),
    reservas(res)
{

}

int DTDetalleViaje::getCodigo() { return codigo; }
DTFecha DTDetalleViaje::getFecha() { return fecha; }
string DTDetalleViaje::getOrigen() { return origen; }
string DTDetalleViaje::getDestino() { return destino; }
int DTDetalleViaje::getAsientosPublicados() { return asientosPublicados; }
float DTDetalleViaje::getPrecio() { return precio; }
DTDetalleVehiculo DTDetalleViaje::getVehiculo() { return vehiculo; }
set<DTDetalleReserva> DTDetalleViaje::getReservas() { return reservas; }
