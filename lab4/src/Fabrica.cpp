#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
//#include "../include/ControladorUsuarios.h"
//#include "../include/ControladorViaje.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}

//IUsuario* Fabrica::getIUsuario(){
//    return ControladorUsuario::getInstance();
//}

//IViaje* Fabrica::getIViaje(){
//    return ControladorViaje::getInstance();
//}
