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

bool ControladorFechaActual::compararFechas(DTFecha fecha1) {
    if (fecha1.getAnio() >= this->fechaActual.getAnio()) {
        if (fecha1.getMes() >= this->fechaActual.getMes()) {
            return fecha1.getDia() >= this->fechaActual.getDia();
        }
    }
    return false;   
}
