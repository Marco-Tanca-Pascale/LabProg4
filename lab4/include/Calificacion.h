#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
class Usuario;
class Reserva;


class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

public:
    Calificacion(DTFecha fecha, int puntaje);
    void asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva);
    ~Calificacion();
};

#endif