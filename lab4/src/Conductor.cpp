#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/DTVehiculosConductor.h"

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
// nahue: el metodo tendria que verificar si tienen la libreta de un TipoVehiculo
bool Conductor::tieneLibreta(TipoVehiculo tipo){
    // nahue:agregue este if
    set<TipoLibreta>::iterator it;
    if (tipo == TipoVehiculo::Auto) {
        it= this->libs.find(TipoLibreta::AutoAmateur);
        it= this->libs.find(TipoLibreta::AutoProfesional);
    } else {
        it= this->libs.find(TipoLibreta::MotoAmateur);
        it= this->libs.find(TipoLibreta::MotoProfesional);
    }
    return it != this->libs.end();
}

//asociacion de vehiculo con conductor 
void Conductor::agregarVehiculo(Vehiculo* vehiculo){
    this->vehiculos[vehiculo->getMatricula()] = vehiculo;
}

<<<<<<< HEAD
float Conductor::getCalificacionProm(){ 
=======
float Conductor::getCalificacionProm(){
>>>>>>> refs/remotes/origin/main
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


set<DTVehiculosConductor> Conductor::listarVehiculos() {
    set<DTVehiculosConductor> res;// marco: agregue esto solo para devolverlo, ademas cambie esta funcion de void a set<DTVehiculosConductor>, no tenia mucho sentido jaja.
    //recorro
   for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            DTVehiculosConductor dt = vehiculo->getDTVehiculoConductor();
            //imprimo los datos del DT ? 
            // cout .. ??

            
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
  // nahue: vector en vez de set :)
set <DTListarViaje> Conductor::obtenerViajes(){
    set<DTListarViaje> res;

    //obtengo el nickname de este conductor
    string miNick = this->getNickname();

    //itero coleccion de vehiculos asociados a este conductor
    for(auto const& par : this->vehiculos){
        Vehiculo* v = par.second;
        if(v != nullptr){
            // le pido al vehiculo especifico la colec de DTListarViaje de sus viajes
            set<DTListarViaje> dtsVeh = v->obtenerDatosViaje(miNick);
            
            //agrego todos los elementos del subconjunto dtsVeh a la coleccion resultado res.
            res.insert(dtsVeh.begin(), dtsVeh.end());
        }
        // le retorno res al controlador
      
    }
      return res;
}