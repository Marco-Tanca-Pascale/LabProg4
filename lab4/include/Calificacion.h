#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
using namespace std;
class Usuario;
class Reserva;


class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificador;
    Usuario* calificado;
public:
    Calificacion(DTFecha fecha, int puntaje);
    void asociarCalificacion(Usuario* calificador, Usuario* calificado, Reserva* reserva);
    bool esCalificacionDe(string nicknameCalificado, string nicknameCalificador);
    ~Calificacion();
};

#endif