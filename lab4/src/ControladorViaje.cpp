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

    Usuario* u = m->getUsuario(nickname);
    Conductor* c = dynamic_cast<Conductor*>(u);
    map<string, DTVehiculosConductor> listaVehiculos;
    if (c != nullptr){
        listaVehiculos = c->listarVehiculos();
    }
    
    return listaVehiculos;
}

bool ControladorViaje::altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precio) {
    ControladorUsuario* m = ControladorUsuario::getInstance();
    map<string, Usuario*> usuarios = m->getUsuarios();
    Conductor* c;
    Vehiculo* v = nullptr;
    for (auto it=usuarios.begin(); it!=usuarios.end(); ++it) {
        c = dynamic_cast<Conductor*>(it->second);
        if (c != nullptr) {
            v = c->getVehiculo(matricula);
            if (v != nullptr)
                break;
        }
    }
    if (v == nullptr) return false;
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

Viaje* ControladorViaje::crearViaje(Vehiculo* v, DTFecha fecha, string origen, string destino, int asientos, float precio){
    int cod = this->viajes.size() > 0 ? this->viajes.rbegin()->first + 1 : 1;

    Viaje* vi = new Viaje(cod, fecha, origen, destino, asientos, precio, v);
    
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
            delete dtcv; // borro el puntero al DT para poder pasarlo de manera prolija a la interfaz.
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
    if (vi == nullptr) return false;
    int reservados = vi->getAsientosReservados();
    int publicados = vi->getAsientosPublicados();
    // Si no hay espacio para los asientos reservados o ya se hizo una reserva con ese usuario, se retorna false.
    if (asientos + reservados > publicados || vi->existeReserva(nickname))
        return false;
    // Se hace la reserva y se retorna true.
    Usuario* p = m->getUsuario(nickname);
    vi->crearReserva(dynamic_cast<Pasajero*>(p), asientos);
    return true;
}

//Para eliminar un viaje y toda la informacion relacionada al mismo.
void ControladorViaje::eliminarViaje() {
    //se obtiene el viaje asociado al codigo recordado
    auto it = this->viajes.find(this->codigo_memo);
    if(it == this->viajes.end()){ //en caso de que no encuentre el viaje
        return;
    }

    Viaje* viajeCodigo = it->second;
    //se va hacia adentro en el viaje limpiando y desconectando todo a lo que esté relacionado (Vehiculo,calificaciones,reserva, usuarios,etc)
    viajeCodigo->desvincularYDestruirRelaciones();

    //una vez que esté toda la memoria limpia borramos el viaje de la coleccion de viajes del controlador
    this->viajes.erase(it);

    //borramos el viaje y el código
    delete viajeCodigo;
    this->codigo_memo = -1;//asumiendo que el -1 es como darle un valor inefectivo al código 

}

void ControladorViaje::cancelarEliminarViaje() {
    //tenemos que eliminar el código de la memoria
    this->codigo_memo = -1;
}