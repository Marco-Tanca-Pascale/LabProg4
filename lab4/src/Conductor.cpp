#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/DTVehiculosConductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {//faltaba un parametro
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
// nahue: el metodo tendria que verificar si tienen la libreta de un TipoVehiculo
bool Conductor::tieneLibreta(TipoVehiculo tipo){
    // nahue:agregue este if
    set<TipoLibreta>::iterator it;
    if (tipo == TipoVehiculo::Auto && this->libs.find(TipoLibreta::AutoAmateur) != this->libs.end())
        return true;
    if (tipo == TipoVehiculo::Auto && this->libs.find(TipoLibreta::AutoProfesional) != this->libs.end())
        return true;
    if (tipo == TipoVehiculo::Moto && this->libs.find(TipoLibreta::MotoAmateur) != this->libs.end())
        return true;
    if (tipo == TipoVehiculo::Moto && this->libs.find(TipoLibreta::MotoProfesional) != this->libs.end())
        return true;
    return false;
}

//asociacion de vehiculo con conductor 
void Conductor::agregarVehiculo(Vehiculo* vehiculo){
    this->vehiculos[vehiculo->getMatricula()] = vehiculo;
    vehiculo->setDuenio(this);
}

float Conductor::getCalificacionProm(){
    return this->calificacionPromedio;
}

bool Conductor::esConductorDe(int codigo) {
    // 1.2.1* [foreach] v := next()
    // Itero por el mapa de vehículos que tiene este conductor
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
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
   for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr && vehiculo->existeViaje(codigo)) {
            return vehiculo->getViaje(codigo); //  puntero al Viaje original
        }
    }
    return nullptr; // no se encuentra el viaje en ningun vehiculo.
}


map<string, DTVehiculosConductor> Conductor::listarVehiculos() {
    map<string, DTVehiculosConductor> res;// marco: agregue esto solo para devolverlo, ademas cambie esta funcion de void a map<int, DTVehiculosConductor>, no tenia mucho sentido jaja.
    //recorro
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            DTVehiculosConductor dt = vehiculo->getDTVehiculoConductor();
            res.insert(pair<string, DTVehiculosConductor>(dt.getMatricula(), dt));
        }
    }
    return res; // marco: cambie esta funcion de void a set<DTVehiculosConductor>, no tenia mucho sentido jaja.
}

// Verifico si el conductor tiene viajes asociados en una fecha indicda.
bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    //recorro
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            // cada vehiculo -> tiene viajes en esa fecha indicada ? 
            if (vehiculo->hayViajesFecha(fecha)) {
                return true; 
            }
        }
    }
    return false;
}

// Implementación específica de Usuario para obtener los viajes del conductor.
map <int, DTListarViaje> Conductor::obtenerViajes(){
    map<int, DTListarViaje> res;

    //obtengo el nickname de este conductor
    string miNick = this->getNickname();

    //itero coleccion de vehiculos asociados a este conductor
    for(auto const& par : this->vehiculos){
        Vehiculo* v = par.second;
        if(v != nullptr){
            // le pido al vehiculo especifico la colec de DTListarViaje de sus viajes
            map<int, DTListarViaje> dtsVeh = v->obtenerDatosViaje(miNick);
            
            //agrego todos los elementos del subconjunto dtsVeh a la coleccion resultado res.
            res.insert(dtsVeh.begin(), dtsVeh.end());
        }
        // le retorno res al controlador
      
    }
    return res;
}

const map<string, Vehiculo*>& Conductor::getVehiculos() const {
    return this->vehiculos;
}

Vehiculo* Conductor::getVehiculo(string matricula){
    auto it = this->vehiculos.find(matricula);
    if (it == this->vehiculos.end())
        return nullptr;
    return it->second;
}