#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "IControladorUsuario.h"
#include "IControladorViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();

public:
    static Fabrica* getInstance();
    IControladorUsuario* getIUsuario();
    IControladorViaje* getIViaje();
    IControladorFechaActual* getIControladorFechaActual();
};

#endif

