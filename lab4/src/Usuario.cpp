#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(string nickname, string nombre, string contrasena, string email, float calificacionPromedio) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
    this->calificacionPromedio = calificacionPromedio;
}

Usuario::~Usuario() {}

//getters
string Usuario::getNickname(){
    return this->nickname;
}

string Usuario::getNombre(){
    return this->nombre;
}

float Usuario::getCalificacionPromedio(){
    return this->calificacionPromedio;
}
    //calificacion
    void Usuario::asociarRealiza(Calificacion* c){
        //añade la calificacion al contenedor de realizads
        this->calificacionesRealizadas.push_back(c);
    }

    //añade la calificacion al contenedor de recibidas
    void Usuario::asociarCalifica(Calificacion* c){
        this->calificacionesRecibidas.push_back(c);
    }

    
    //la implementacion de este metodo será distinta para Pasajero y para Conductor
    // utilicen set en vez de vector para este metodo porfa
    set<DTListarViaje> Usuario::obtenerViajes() {
    return set<DTListarViaje>();
    }


