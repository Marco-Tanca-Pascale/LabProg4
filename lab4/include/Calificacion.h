#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

//fwd declarations
class Usuario;
class Reserva;

using namespace std;


class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificador;
    Usuario* calificado;
public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    //Metodos

    //asocia una calificacion a sus respectivos usuarios y la reserva sobre la que se realizó
    void asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva);

    //verifica si esta calificacion es una calificación 
    bool esCalificacionDe(string nicknameCalificado, string nicknameCalificador);

    //getters
    int getPuntaje();
    Usuario* getUsuarioCalificado();
    Usuario* getUsuarioCalificador();
};

#endif