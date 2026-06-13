#include "../include/ControladorViaje.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/Viaje.h"

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

map<string, DTVehiculosConductor> ControladorViaje::listarVehiculosConductor(string nickname) {
    ControladorUsuario* m = ControladorUsuario::getInstance();

    Usuario* c = m->getUsuario(nickname);
    map<string, DTVehiculosConductor> listaVehiculos = dynamic_cast<Conductor*>(c)->listarVehiculos();
    
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
    int cod = this->viajes.size() > 0 ? this->viajes.rbegin()->first + 1 : 1;

    Viaje* vi = new Viaje(cod, fecha, origen, destino, asientos, precio, v);
    //crear link con Vehiculo v?
    
    this->viajes[cod] = vi;
    

    return vi;
}

set<string> ControladorViaje::listarPasajeros() {
    ControladorUsuario* m = ControladorUsuario::getInstance();
    // Set para almacenar los nicknames de los pasajeros.
    set<string> pasajerosNicknames;
     
    // Obtengo la lista de usuarios del sistema.
    map<string, Usuario*> usuarios = m->getUsuarios();
    
    // Itero por la lista de usuarios y agrego los nicknames solo de los pasajeros al set.
    for (const auto& pair : usuarios) {
        Pasajero* p = dynamic_cast<Pasajero*>(pair.second);
        if (p != nullptr) {
            string nickname = p->getNickname();
            pasajerosNicknames.insert(nickname);
        }
    }

    return pasajerosNicknames;
}

map<int, DTConsultaViaje> ControladorViaje::consultarViajes(DTFecha fecha, string origen, string destino, int asientos) {
    map<int, DTConsultaViaje> res;

    for (const auto& pair : this->viajes) {
        Viaje* vi = pair.second;
        
        DTConsultaViaje* dtcv = vi->obtenerViajeValido(fecha, origen, destino, asientos);
        if (dtcv != nullptr){
            res[dtcv->getCodigo()] = *dtcv;
        }
    }
    return res;
}

set<DTListarViaje> ControladorViaje::listarViajes() {
    set<DTListarViaje> res;
    
    for (const auto& pair : this->viajes) {
        Viaje* vi = pair.second;
        
        DTListarViaje dtvi = vi->obtenerDatosViaje();
        res.insert(dtvi);
    }

    return res;
}

//Precondiciones: existe un viaje vi con vi.codigo = codigo
DTDetalleViaje ControladorViaje::detalleViaje(int codigo) {
    auto it = this->viajes.find(codigo);

    Viaje* vi = it->second;
    DTDetalleViaje res = vi->obtenerDetalleViaje();

    //guarda en memoria el codigo del viaje.
    this->codigo_memo = codigo;
    return res;
}

bool ControladorViaje::generarReserva(string nickname, int codigo, int asientos){
    // Se obtiene una instancia del controladorViaje para obtener el viaje relacionado al codigo.
    ControladorUsuario* m = ControladorUsuario::getInstance();
    Viaje* vi = this->viajes[codigo];
    int reservados = vi->asientosReservados();
    int publicados = vi->getAsientosPublicados();
    // Si no hay espacio para los asientos reservados o ya se hizo una reserva con ese usuario, se retorna false.
    if (asientos + reservados > publicados || vi->existeReserva(nickname))
        return false;
    // Se hace la reserva y se retorna true.
    Usuario* p = m->getUsuario(nickname);
    vi->crearReserva(dynamic_cast<Pasajero*>(p), asientos);
    return true;
}

void ControladorViaje::eliminarViaje() {
    
}

void ControladorViaje::cancelarEliminarViaje() {

}