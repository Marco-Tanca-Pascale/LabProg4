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

    Usuario* c = m->getUsuario(nickname);
    // Nahue: Comenté porque listarVehiculos devuelve void. Agregué casteo inline para que el llamado no explote, pero seria mejor intentar castear antes y manejar de manera defensiva el caso en el que sea un Pasajero.
    //set<DTVehiculosConductor> listaVehiculos = dynamic_cast<Conductor*>(c)->listarVehiculos();
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