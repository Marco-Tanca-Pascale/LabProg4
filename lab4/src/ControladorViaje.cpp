#include "../include/ControladorViaje.h"
<<<<<<< HEAD
#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Fabrica.h"
#include "../include/Conductor.h"
=======
>>>>>>> 18fedb72483223ef66a702e9e48b4bb2c4062b7c

ControladorViaje* ControladorViaje::instancia = nullptr;

ControladorViaje::ControladorViaje() {
<<<<<<< HEAD

}

ControladorViaje* ControladorViaje::getInstance() {
    //Si no hay una instancia inicializada, la inicializa.
    if (instancia == nullptr) {
        instancia = new ControladorViaje();
    }
    //Retorna la instancia.
    return instancia;
}

set<DTVehiculosConductor> ControladorViaje::listarVehiculosConductor(string nickname) {
    ControladorUsuario* m = ControladorUsuario::getInstance();

    Usuario c = getUsuario(nickname);
    set<DTVehiculosConductor> listaVehiculos = listarVehiculos();
}

bool ControladorViaje::altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) {

}

set<string> ControladorViaje::listarPasajeros() {

}

set<DTConsultaViaje> ControladorViaje::consultarViajes(DTFecha fecha, string origen, string destino, int asientos) {

}

set<DTListarViaje> ControladorViaje::listarViajes() {

}

DTDetalleViaje ControladorViaje::detalleViaje(int codigo) {

}

void ControladorViaje::eliminarViaje() {

}

void ControladorViaje::cancelarEliminarViaje() {

=======
}

ControladorViaje* ControladorViaje::getInstance() {
    // Si no hay una instancia inicializada, lo hace.
    if (instancia == nullptr) {
        instancia = new ControladorViaje();
    }
    // Retorna la instancia guardada para mantener el patron singleton.
    return instancia;
>>>>>>> 18fedb72483223ef66a702e9e48b4bb2c4062b7c
}