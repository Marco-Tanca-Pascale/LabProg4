#include "../include/Calificacion.h"
#include "../include/Usuario.h"

// Constructor de la clase Calificacion.
Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

// Este Metodo asocia una calificacion con el que la realiza y el que la recibe.
void Calificacion::asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva){
    calificador->asociarRealiza(this); 
    calificado->asociarCalifica(this);
    this->calificador = calificador;
    this->calificado = calificado;
}

// Este metodo devuelve true sii el nickname del Usuario calificado y el Usuario calificador asociados a la calificacion son iguales a nicknameCalificado y nicknameCalificador respectivamente. 
bool Calificacion::esCalificacionDe(string nicknameCalificado, string nicknameCalificador){
    return (this->calificado->getNickname() == nicknameCalificado && this->calificador->getNickname() == nicknameCalificador);
}

// Este metodo devuelve el Usuario calificado asociado a la calificacion.
Usuario* Calificacion::getUsuarioCalificado(){
    return this->calificado;
}

// Este metodo devuelve el Usuario calificador asociado a la calificacion.
Usuario* Calificacion::getUsuarioCalificador(){
    return this->calificador;
}

// Este metodo devuelve el puntaje de la calificacion.
int Calificacion::getPuntaje(){
    return this->puntaje;
}

// Destructor de la clase Calificacion.
Calificacion::~Calificacion() {}
