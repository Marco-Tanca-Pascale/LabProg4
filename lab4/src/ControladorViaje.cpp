#include "../include/ControladorViaje.h"

ControladorViaje* ControladorViaje::instancia = nullptr;

ControladorViaje::ControladorViaje() {
}

ControladorViaje* ControladorViaje::getInstance() {
    // Si no hay una instancia inicializada, lo hace.
    if (instancia == nullptr) {
        instancia = new ControladorViaje();
    }
    // Retorna la instancia guardada para mantener el patron singleton.
    return instancia;
}