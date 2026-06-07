#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Viaje.h"





Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->duenio = nullptr;
}

std::string Vehiculo::getNicknameConductor(){
    if(this->duenio != nullptr){
        return this->duenio->getNickname(); //falta que en conductor se incluya el usuario.h para que esto funcione
    }
    return "";
}

std::set<Viaje*> Vehiculo::getViajes(){
    return this->viajes;
}

bool Vehiculo::existeViaje(int codigo){
    for(Viaje* v: this->viajes){
        if(v->getCodigo() == codigo) return true; 
    }
    return false;
}

Viaje* Vehiculo::getViaje(int codigo){
    for(Viaje* v: this->viajes){
        if(v->getCodigo() == codigo) return v;
    }
    return nullptr;
}

DTConsultaViaje Vehiculo::obtenerDatosRelacionados(){
    return DTConsultaViaje(0, this->marca, this->modelo, this->duenio->getNickname(), this->duenio->getCalificacionProm(), 0);
    //MANDA 2 PARAMETROS EN 0 PARA SOBREESCRIBIRLOS LUEGO
}

std::vector<DTListarViaje> Vehiculo::obtenerDatosViaje(std::string nickname){
    std::vector<DTListarViaje> viajesConductor;
    for(Viaje* v: this->viajes){
        DTListarViaje dt = v->obtenerDatosViaje(nickname);
        viajesConductor.push_back(dt);
    }
    return viajesConductor;
}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    return DTVehiculosConductor(this->matricula,this->modelo,this->capacidad);
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
    for(Viaje* v: this->viajes){
        if(v->getFecha() == fecha) return true;
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* viaje){
    this->viajes.insert(viaje);
}

Vehiculo::~Vehiculo() {}
