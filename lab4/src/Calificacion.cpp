#include "../include/Calificacion.h"
#include "../include/Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

void Calificacion::asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva){
    
    calificador->asociarRealiza(this); //?
    calificado->asociarCalifica(this); //?
}

bool Calificacion::esCalificacionDe(string nicknameCalificado, string nicknameCalificador){
    return (this->calificado->getNickname() == nicknameCalificado && this->calificador->getNickname() == nicknameCalificador);
}
Calificacion::~Calificacion() {}
