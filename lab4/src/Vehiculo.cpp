#include "../include/Vehiculo.h"
#include "../include/Conductor.h"



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
        //return this->duenio->getNickname(); //falta que en conductor se incluya el usuario.h para que esto funcione
    }
    return "";
}

std::set<Viaje*> Vehiculo::getViajes(){
    return this->viajes;
}

bool Vehiculo::existeViaje(int codigo){
    for(Viaje* v: this->viajes){
        //if(v->getCodigo() == codigo) return true; FALTA QUE SE AÑADA EL MÉTODO EN VIAJE
    }
    return false;
}

Viaje* Vehiculo::getViaje(int codigo){
    for(Viaje* v: this->viajes){
        //if(v->getCodigo() == codigo) return v;
    }
    return nullptr;
}

DTConsultaViaje Vehiculo::obtenerDatosRelacionados(){//NO ESTOY SEGURA DE QUE ESE SEA EL TIPO DE RETORNO CORRECTO, PORQUE TENDRÍA QUE GUARDAR UNA ESPECIE DE ARRAY CON LOS DTOS MARCA,MODELO,NOMBRECOND Y CALIF.PROM.CONDUCTOR
//FALTA COMPLETAR
}

std::set<DTListarViaje> Vehiculo::obtenerDatosViaje(std::string nickname){
    std::set<DTListarViaje> viajesConductor;
    for(Viaje* v: this->viajes){
        //viajesConductor.insert(v->obtenerDatosViaje(nickname));
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
        //return this->duenio->hayViajesFechaConductor(fecha);//le preguntamos al dueño si tiene un viaje para esa fecha
    }
    return false;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(Viaje* v: this->viajes){
        //if(v->getFecha() == fecha) return true;
    }
    return false;
}

void Vehiculo::asociarViaje(Viaje* viaje){
    this->viajes.insert(viaje);
}

Vehiculo::~Vehiculo() {}
