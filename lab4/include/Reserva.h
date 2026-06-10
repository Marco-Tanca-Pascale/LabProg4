#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <set>
#include "DTFecha.h"
class Viaje;
class Calificacion;
class Pasajero;
class Usuario;
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

    ~Reserva();

    Viaje *getViaje();

    int getAsientosReservados();

    bool existeCalificacion(std::string nickname, std::string nicknameCalificado);

    void crearCalificacion(int calificacion, DTFecha fecha,Usuario* usuario, Usuario* usuario_calificado);

    DTListarViaje obtenerDatosViaje();

    bool esDeUsuario(std::string nickname);
};

#endif
