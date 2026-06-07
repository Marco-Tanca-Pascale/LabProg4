#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "Viaje.h"
#include "Calificacion.h"
#include "Pasajero.h"
#include "DTListarViaje.h"

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;
    Viaje *viaje;
    Pasajero *pasajero;
    std::set<Calificacion*> calificaciones;

public:
    Reserva(int asientosReservados, DTFecha fecha, Viaje *viaje, Pasajero *pasajero);

    Viaje *getViaje();

    //se evalua que r.asientosReservados + asientos <= vi.asientosPublicados
    int getAsientosReservados();

    bool existeCalificacion(std::string nickname, std::string nicknameCalificado);

    void crearCalificacion(int calificacion, DTFecha fecha,Usuario* usuario, Usuario* usuario_calificado);

    DTListarViaje obtenerDatosViaje();
};

#endif
