#include "../include/ControladorViaje.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Conductor.h"
#include "../include/Vehiculo.h"

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

    Conductor* c = m->getUsuario(nickname);
    set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
    
    return listaVehiculos;
}

bool ControladorViaje::altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precio) {
    ControladorUsuario* m = ControladorUsuario::getInstance();

    Vehiculo* v = getVehiculo(matricula);
    int capacidad = v->getCapacidad();
    if (capacidad >= asientos){
        bool hayViajesFecha = v->hayViajesConductor(fecha);
        if (!hayViajesFecha){
            Viaje* cvi = crearViaje(v, fecha, origen, destino, asientos, precio);
            v->asociarViaje(cvi);

            return true;
        }
    }
    return false;
}

Vehiculo* ControladorViaje::getVehiculo(string matricula){
    // Encuentra y retorna el vehiculo relacionado a matricula.
    auto it = this->vehiculos.find(matricula);
    if (it == this->vehiculos.end()) {
        return nullptr;
    }
    return it->second;
}

Viaje* ControladorViaje::crearViaje(Vehiculo* v, DTFecha fecha, string origen, string destino, int asientos, float precio){
    int cod;//obtenerCodigo y sumar 1

    Viaje* vi = new Viaje(cod, fecha, origen, destino, asientos, precio);
    //crear link con Vehiculo v
    
    this->viajes[cod] = vi;
    

    return vi;
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