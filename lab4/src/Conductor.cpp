#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/DTVehiculosConductor.h"

// Constructor de la clase Conductor.
Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {//faltaba un parametro
    this->libs = libs;
}

//Destructor de la clase Conductor.
Conductor::~Conductor() {
    // Recorremos el mapa destruyendo cada vehículo creado dinámicamente
  /*   for (auto const& par : this->vehiculos) {
        if (par.second != nullptr) {
            delete par.second;
        }
    }
    this->vehiculos.clear(); // Limpia el mapa de punteros
*/
    }


// Este metodo devuelve true sii en el map vehiculos existe un elemento con su string igual a matricula.
bool Conductor::tieneVehiculo(string matricula){
    map<string,Vehiculo*>::iterator it= this->vehiculos.find(matricula);
    return it != this->vehiculos.end();
}

// Este metodo devuelve true cuando el Usuario tiene la libreta adecuada para el TipoVehiculo tipo.
bool Conductor::tieneLibreta(TipoVehiculo tipo){
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

// Este metodo asocia un Vehiculo con un Coductor.
void Conductor::agregarVehiculo(Vehiculo* vehiculo){
    this->vehiculos[vehiculo->getMatricula()] = vehiculo;
    vehiculo->setDuenio(this);
}

// Este metodo devuelve la calificacion promedio del Usuario
float Conductor::getCalificacionProm(){
    return this->calificacionPromedio;
}

// Este metodo devuelve true sii existe un vehiculo asociado al Coductor para el cual existe un viaje con codigo igual al pasado.
bool Conductor::esConductorDe(int codigo) {
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            if (vehiculo->existeViaje(codigo)) { 
                return true;
            }
        }
    }
    return false; 
}

// Este metodo devuelve el viaje cuyo código es igual al que se recibe como parámetro, lo busca recorriendo los vehículos del conductor.
Viaje* Conductor::getViaje(int codigo) {
   for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr && vehiculo->existeViaje(codigo)) {
            return vehiculo->getViaje(codigo);
        }
    }
    return nullptr; 
}

// Este metodo devuelve un map con los vehiculos del conductor
map<string, DTVehiculosConductor> Conductor::listarVehiculos() {
    map<string, DTVehiculosConductor> res;
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            DTVehiculosConductor dt = vehiculo->getDTVehiculoConductor();
            res.insert(pair<string, DTVehiculosConductor>(dt.getMatricula(), dt));
        }
    }
    return res;
}

// Este metodo devuelve true sii el conductor tiene viajes asociados para la fecha indicda.
bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for (auto const& par : this->vehiculos) {
        Vehiculo* vehiculo = par.second;
        if (vehiculo != nullptr) {
            if (vehiculo->hayViajesFecha(fecha)) {
                return true; 
            }
        }
    }
    return false;
}

// Este metodo devuelve un map los viajes del conductor.
map <int, DTListarViaje> Conductor::obtenerViajes(){
    map<int, DTListarViaje> res;

    string miNick = this->getNickname();

    for(auto const& par : this->vehiculos){
        Vehiculo* v = par.second;
        if(v != nullptr){
            map<int, DTListarViaje> dtsVeh = v->obtenerDatosViaje(miNick);
            
            res.insert(dtsVeh.begin(), dtsVeh.end());
        }
      
    }
    return res;
}

// Este metodo devuelve un map de los vehiculos del conductor.
const map<string, Vehiculo*>& Conductor::getVehiculos() const {
    return this->vehiculos;
}

// Este metodo devuelve el vheiculo del conductor con la matricula pasada por parametro(si existe).
Vehiculo* Conductor::getVehiculo(string matricula){
    auto it = this->vehiculos.find(matricula);
    if (it == this->vehiculos.end())
        return nullptr;
    return it->second;
}