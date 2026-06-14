#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"


Vehiculo::Vehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->duenio = nullptr;
}

string Vehiculo::getMatricula(){
    return this->matricula;
}

string Vehiculo::getMarca(){
    return this->marca;
}

string Vehiculo::getModelo(){
    return this->modelo;
}

Conductor* Vehiculo::getConductor(){
    return this->duenio;
}

string Vehiculo::getNicknameConductor(){
    if(this->duenio != nullptr){
        return this->duenio->getNickname();
    }
    return "";
}

map<int, Viaje*> Vehiculo::getViajes(){
    return this->viajes;
}

void Vehiculo::setDuenio(Conductor* c){
    this->duenio = c;
}

bool Vehiculo::existeViaje(int codigo){
    return this->viajes.find(codigo) != this->viajes.end();
}

Viaje* Vehiculo::getViaje(int codigo){
    auto it = this->viajes.find(codigo);
    if(it != this->viajes.end()){// si it != viajes.end() es porque se detuvo en el medio, o sea que encontró el viaje con dicho código
      return it->second;  
    }
    return nullptr;
}

DTConsultaViaje Vehiculo::obtenerDatosRelacionados(){
    return DTConsultaViaje(0, this->marca, this->modelo, this->duenio->getNickname(), this->duenio->getCalificacionProm(), 0);
    //MANDA 2 PARAMETROS EN 0 PARA SOBREESCRIBIRLOS LUEGO
}

std::map<int, DTListarViaje> Vehiculo::obtenerDatosViaje(string nickname)
{
    map<int, DTListarViaje> viajesConductor;
    for(auto const& par: this->viajes){ //par tiene un elemento first y uno second, donde el first tiene el código y el second tiene la info que necesito, en este caso el puntero al viaje
        Viaje* viaje = par.second;
        DTListarViaje dt = viaje->obtenerDatosViaje(nickname);
        viajesConductor[dt.getCodigo()] = dt;
    }
    return viajesConductor;
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    return DTVehiculosConductor(this->matricula,this->modelo,this->capacidad);
}

DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    return DTDetalleVehiculo(this->matricula, this->capacidad, this->marca, this->modelo, this->tipo);
}

int Vehiculo::getCapacidad(){
    return this->capacidad;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha){
    if(this->duenio != nullptr){
        return this->duenio->hayViajesFechaConductor(fecha);//le preguntamos al dueño si tiene un viaje para esa fecha
    }
    return false;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(auto const& par : this->viajes){
        Viaje* viaje = par.second;
        if(viaje->getFecha() == fecha) return true;
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* viaje){
    if(viaje != nullptr){
        this->viajes[viaje->getCodigo()] = viaje;
    }
}

void Vehiculo::eliminarViaje(Viaje* viaje){
    if(viaje != nullptr){
        this->viajes.erase(viaje->getCodigo());
    }
}

Vehiculo::~Vehiculo() {}
