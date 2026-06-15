#include "../include/DTDetalleReserva.h"

DTDetalleReserva::DTDetalleReserva(int asientosReservados, DTFecha fecha,string pasajero) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = pasajero;
}

int DTDetalleReserva::getAsientosReservados() { return asientosReservados; }
DTFecha DTDetalleReserva::getFecha() { return fecha; }
string DTDetalleReserva::getPasajero() { return pasajero; }

bool DTDetalleReserva::operator<(const DTDetalleReserva &otro) const
{
    // Ordenamos alfabeticamente por el nombre/nickname del pasajero
    return this->pasajero < otro.pasajero;
}