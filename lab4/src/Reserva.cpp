#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"
#include "../include/DTListarViaje.h"
#include "Calificacion.h"


Reserva::Reserva(int asientosReservados, DTFecha fecha, Viaje *viaje, Pasajero *pasajero)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->viaje = viaje;
    this->pasajero = pasajero;
}

Viaje *Reserva::getViaje()
{
    return this->viaje;
}

int Reserva::getAsientosReservados()
{
    return this->asientosReservados;
}

bool Reserva::existeCalificacion(std::string nicknameCalificado, std::string nickname)
{
    for (Calificacion *c : this->calificaciones)
    {  
        if (c->esCalificacionDe(nicknameCalificado, nickname))
            return true;
    }

    return false;
}

void Reserva::crearCalificacion(int calificacion, DTFecha fecha, Usuario *usuario, Usuario *usuario_calificado)
{
    Calificacion *nuevaCalificacion = new Calificacion(fecha, calificacion);
    nuevaCalificacion->asociarCalificacion(usuario, usuario_calificado, this); 
    this->calificaciones.insert(nuevaCalificacion);
}

DTListarViaje Reserva::obtenerDatosViaje()
{
    if (this->viaje != nullptr) {
return this->viaje->obtenerDatosViaje();
}
 return DTListarViaje(0, DTFecha(), "", "", "");
;
}

Reserva::~Reserva()
{
    for (Calificacion *c : this->calificaciones)
    {
        delete c;
    }
    this->calificaciones.clear();
}
//agregue la funcion para el verificar el getReserva
bool Reserva::esDeUsuario(std::string nickname)
{
    return (this->pasajero != nullptr && this->pasajero->getNickname() == nickname);
}