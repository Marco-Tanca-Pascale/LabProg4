#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include "Usuario.h"
#include "Reserva.h"


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