#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"
#include "../include/DTListarViaje.h"
#include "../include/Calificacion.h"


Reserva::Reserva(int asientosReservados, DTFecha fecha, Viaje *viaje, Pasajero *pasajero)
{
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->viaje = viaje;
    this->pasajero = pasajero;
}

//devuelve viaje asociado a esta reserva
Viaje *Reserva::getViaje()
{
    return this->viaje;
}

//devuelve cantidad de asientos que se reservaron
int Reserva::getAsientosReservados()
{
    return this->asientosReservados;
}

//devuelve la fecha en la que se hizo la reserva
DTFecha Reserva::getFecha() {
    return this->fecha;
}

//devuelve el pasajero que es "dueñp" de esta reserva
Pasajero *Reserva::getPasajero() {
    return this->pasajero;
}


//chequea si ya existe la calificacion entre estos 2 usuarios en esta resera
bool Reserva::existeCalificacion(string nicknameCalificado, string nickname)
{
    for (Calificacion *c : this->calificaciones)
    {  
        if (c->esCalificacionDe(nicknameCalificado, nickname))
            return true; // la encontro 
    }

    return false;//no existe aun
}


//se crea una nueva calificacion que se vincula con los usuarios y se guarda en la reserva
void Reserva::crearCalificacion(int calificacion, DTFecha fecha, Usuario *usuario, Usuario *usuario_calificado)
{
    Calificacion *nuevaCalificacion = new Calificacion(fecha, calificacion);
    nuevaCalificacion->asociarCalificacion(usuario, usuario_calificado, this); 
    this->calificaciones.insert(nuevaCalificacion);
}

//obtiene los datos del viaje asociado para asi armar el DT, si no hay viaje entonces decuelve uno vacio.
DTListarViaje Reserva::obtenerDatosViaje()
{
    if (this->viaje != nullptr) {
return this->viaje->obtenerDatosViaje();
}
 return DTListarViaje(0, DTFecha(), "", "", "");
;
}

//destructor 
Reserva::~Reserva()
{
    for (Calificacion *c : this->calificaciones)
    {
        delete c;
    }
    this->calificaciones.clear();
}

//chequea si el nickname pasado por paramero coincide con el del pasajero de la reserva
bool Reserva::esDeUsuario(string nickname)
{
    return (this->pasajero != nullptr && this->pasajero->getNickname() == nickname);
}

//rompe los vinculos de las calificaciones con los usuarios y las borra de la memoria
void Reserva::destruirCalificaciones(){
    for(auto const& calif : this->calificaciones){
        calif->getUsuarioCalificado()->removerCalificacion(calif);
        calif->getUsuarioCalificador()->removerCalificacion(calif);
        delete calif; //borro el obj de la memoria
    } 
    this->calificaciones.clear(); //vacia el contenedor
}