#include "../include/Conductor.h"
#include "../include/Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email, 0) {//faltaba un parametro
    this->libs = libs;
}

Conductor::~Conductor() {
    //cuando se elimina un conductor tambien tengo que poner aca adentro la eliminacion de vehiculo ?
}

//chequeo si el conductor tiene un vehiculo con la matricula indicada
bool Conductor::tieneVehiculo(string matricula){
    map<string,Vehiculo*>::iterator it= this->vehiculos.find(matricula);
    return it != this->vehiculos.end();
}

//chequeo si el conductor posee una libreta del tipo indicado 
bool Conductor::tieneLibreta(TipoLibreta tipo){
    set<TipoLibreta>::iterator it= this->libs.find(tipo);
    return it != this-> libs.end();
}

//asociacion de vehiculo con conductor 
void Conductor::agregarVehiculo(Vehiculo* vehiculo){
    this->vehiculos[vehiculo->getMatricula()] = vehiculo;
}

/*float Conductor::getCalificacionProm(){
    return this->calificacionPromedio;
}*/

bool Conductor::esConductorDe(int codigo) {
    // 1.2.1* [foreach] v := next()
    // Itero por el mapa de vehículos que tiene este conductor
    for (auto const& [matricula, vehiculo] : this->vehiculos) {
        if (vehiculo != nullptr) {
            //viajes := getViajes() -> exists(codigo)
            // uso metodo ded vehiculo.cpp existeViaje 
            if (vehiculo->existeViaje(codigo)) { 
                return true; // true = es el conductor de este viaje para dicho codigo indicado
            }
        }
    }
    return false; 
}

// Obtiene el viaje cuyo código se recibe como parámetro recorriendo sus vehículos
Viaje* Conductor::getViaje(int codigo) {
    //recorro 
    for (auto const& [matricula, vehiculo] : this->vehiculos) {
        if (vehiculo != nullptr && vehiculo->existeViaje(codigo)) {
            return vehiculo->getViaje(codigo); //  puntero al Viaje original
        }
    }
    return nullptr; // no se encuentra el viaje en ningun vehiculo.
}


void Conductor::listarVehiculos() {
    //recorro
    for (auto const& [matricula, vehiculo] : this->vehiculos) {
        if (vehiculo != nullptr) {
            DTVehiculosConductor dt = vehiculo->getDTVehiculoConductor();
            //imprimo los datos del DT ? 
            // cout .. ??
        }
    }
}

// Verifico si el conductor tiene viajes asociados en una fecha indicda.
bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    //recorro
    for (auto const& [matricula, vehiculo] : this->vehiculos) {
        if (vehiculo != nullptr) {
            // cada vehiculo -> tiene viajes en esa fecha indicada ? 
            if (vehiculo->hayViajesFecha(fecha)) {
                return true; 
            }
        }
    }
    return false;
}