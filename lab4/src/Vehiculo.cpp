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

//devuelve la matricula del vehiculo
string Vehiculo::getMatricula(){
    return this->matricula;
}

//devuelve la marca del vehiculo 
string Vehiculo::getMarca(){
    return this->marca;
}

//devuelve el modelo del vehiculo
string Vehiculo::getModelo(){
    return this->modelo;
}

//devuelve el puntero al conductor dueño del vehiculo
Conductor* Vehiculo::getConductor(){
    return this->duenio;
}

//devuelve el nickname del conductor
string Vehiculo::getNicknameConductor(){
    if(this->duenio != nullptr){
        return this->duenio->getNickname();
    }
    return "";
}

//devuelve el map con todos los viajes asociados al vehiculo
map<int, Viaje*> Vehiculo::getViajes(){
    return this->viajes;
}

//asigna un conductor como dueño del vehiculo
void Vehiculo::setDuenio(Conductor* c){
    this->duenio = c;
}

//chequea si el viaje ya esta registrado en el map usando su codigo
bool Vehiculo::existeViaje(int codigo){
    return this->viajes.find(codigo) != this->viajes.end();
}

//busca un viaje especifico por codigo y lo devuelve, si no existe entonces retorna nullptr
Viaje* Vehiculo::getViaje(int codigo){
    auto it = this->viajes.find(codigo);
    if(it != this->viajes.end()){
      return it->second;  
    }
    return nullptr;
}

//
DTConsultaViaje Vehiculo::obtenerDatosRelacionados(){
    return DTConsultaViaje(0, this->marca, this->modelo, this->duenio->getNickname(), this->duenio->getCalificacionProm(), 0);
}

//recorre los viajes del vehiculo y arma un map con sus Dt filtrados por el nickname del conductor
map<int, DTListarViaje> Vehiculo::obtenerDatosViaje(string nickname)
{
    map<int, DTListarViaje> viajesConductor;
    for(auto const& par: this->viajes){ 
        Viaje* viaje = par.second;
        DTListarViaje dt = viaje->obtenerDatosViaje(nickname);
        viajesConductor[dt.getCodigo()] = dt;
    }
    return viajesConductor;
}


DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    return DTVehiculosConductor(this->matricula,this->modelo,this->capacidad);
}

//devuelve un dt con las especificaciones detalladas de vehiculo
DTDetalleVehiculo Vehiculo::getDTDetalleVehiculo(){
    return DTDetalleVehiculo(this->matricula, this->capacidad, this->marca, this->modelo, this->tipo);
}

//devuelve la capacidad maxima de asientos del vehiculo
int Vehiculo::getCapacidad(){
    return this->capacidad;
}

//delega al conductor dueño el chequear si tiene viajes en esa fecha
bool Vehiculo::hayViajesConductor(DTFecha fecha){
    if(this->duenio != nullptr){
        return this->duenio->hayViajesFechaConductor(fecha);
    }
    return false;
}

//chequea si el vehiculo tiene algun viaje programado para la fecha pasada por parametro
bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(auto const& par : this->viajes){
        Viaje* viaje = par.second;
        if(viaje->getFecha() == fecha) return true;
    }
    return false;
}

//agrega un nuevo viaje al map de viajes del vehiculo usando el codigo como clave
void Vehiculo::asociarViaje(Viaje* viaje){
    if(viaje != nullptr){
        this->viajes[viaje->getCodigo()] = viaje;
    }
}


//quita el viaje del mapa del vehiculo sin destruirlo de la memoria (asosiacion)
void Vehiculo::eliminarViaje(Viaje* viaje){
    if(viaje != nullptr){
        this->viajes.erase(viaje->getCodigo());
    }
}

Vehiculo::~Vehiculo() {}