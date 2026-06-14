#include "../include/ControladorFechaActual.h"

ControladorFechaActual* ControladorFechaActual::instancia = nullptr;

// Constructor de la calse ControladorFechaActual.
ControladorFechaActual::ControladorFechaActual() {
    fechaActual = DTFecha(1, 1, 2024);
}

ControladorFechaActual* ControladorFechaActual::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorFechaActual();
    }
    return instancia;
}

// Este Metodo devuelve la fecha actual.
DTFecha ControladorFechaActual::getFecha() {
    return fechaActual;
}

// Este metodo cambia el valor de fechaActual por nuevaFecha.
void ControladorFechaActual::setFecha(DTFecha nuevaFecha) {
    fechaActual = nuevaFecha;
}
