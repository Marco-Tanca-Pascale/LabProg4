#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

void Calificacion::asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva){
    //calificador->asociarRealiza(); //cuando esten los otros métodos
    //calificado->asociarCalifica();
}
Calificacion::~Calificacion() {}
