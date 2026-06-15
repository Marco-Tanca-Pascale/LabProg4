#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <set>
#include "DTFecha.h"
class Viaje;
class Calificacion;
class Pasajero;
class Usuario;
using namespace std;
#include "DTListarViaje.h"

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;
    Viaje *viaje;
    Pasajero *pasajero;
    set<Calificacion*> calificaciones;

public:
    Reserva(int asientosReservados, DTFecha fecha, Viaje *viaje, Pasajero *pasajero);
    ~Reserva();

    //getters
    Viaje* getViaje();
    int getAsientosReservados();
    DTFecha getFecha();
    Pasajero *getPasajero();

    bool existeCalificacion(string nickname, string nicknameCalificado);

    //crea una calificacion y la asocia con su usuario y la reserva sobre la que esta hecha
    void crearCalificacion(int calificacion, DTFecha fecha,Usuario* usuario, Usuario* usuario_calificado);

    //obtiene los datos de un viaje
    DTListarViaje obtenerDatosViaje();

    bool esDeUsuario(string nickname);

    //destruye las calificaciones hechas sobre esta reserva
    void destruirCalificaciones();
};

#endif
