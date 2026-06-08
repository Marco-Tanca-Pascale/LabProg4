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
    //calificacion
    ///asociar califica ????? 

    //realiza califica ????????????? 
    //la implementacion de este metodo será distinta para Pasajero y para Conductor
    vector<DTListarViaje> Usuario::obtenerViajes() {
    return vector<DTListarViaje>();
    }


