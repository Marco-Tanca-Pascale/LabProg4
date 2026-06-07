#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
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

