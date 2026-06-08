#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha, Viaje *viaje, Pasajero *pasajero)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->viaje = viaje;
    this->pasajero = pasajero;
}

Viaje *Reserva::getViaje()
{
    return viaje;
}

int Reserva::getAsientosReservados()
{
    return asientosReservados;
}

bool Reserva::existeCalificacion(std::string nicknameCalificado, std::string nickname)
{
    for (Calificacion *c : calificaciones)
    {  //puse esCalificacionDe porque no se si hay alguna funcion ya hecha
        if (c->esCalificacionDe(nicknameCalificado, nickname))
            return true;
    }

    return false;
}

//DTListarViaje Reserva::obtenerDatosViaje()
//{
//    return viaje->obtenerDatosViaje(); falta un parámetro
//}

