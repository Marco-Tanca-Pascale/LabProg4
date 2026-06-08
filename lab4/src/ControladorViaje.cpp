#include "../include/ControladorViaje.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Fabrica.h"
#include "../include/Conductor.h"

ControladorViaje* ControladorViaje::instancia = nullptr;

ControladorViaje::ControladorViaje() {

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

}