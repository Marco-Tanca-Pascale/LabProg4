#ifndef DT_DETALLE_RESERVA_H
#define DT_DETALLE_RESERVA_H

#include "DTFecha.h"
#include <string>
using namespace std;

class DTDetalleReserva {
private:
    int asientosReservados;
    DTFecha fecha;
    string pasajero;

public:
    //constructores
    DTDetalleReserva(int asientosReservados, DTFecha fecha, string pasajero);

    //getters
    int getAsientosReservados();
    DTFecha getFecha();
    string getPasajero();

    //operador sobrecargado
    bool operator<(const DTDetalleReserva &otro) const;
};

#endif
