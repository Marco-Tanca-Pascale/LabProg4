#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(string nickname, string nombre, string contrasena, string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena; 
    this->email = email;
    this->calificacionPromedio = 0.0;
}

Usuario::~Usuario() {}

//getters
string Usuario::getNickname(){
    return this->nickname;
}

string Usuario::getNombre(){
    return this->nombre;
}

void Usuario::setCalificacionPromedio(float nueva){
    this->calificacionPromedio = nueva;
}

float Usuario::getCalificacionPromedio(){
    return this->calificacionPromedio;
}
//calificacion
void Usuario::asociarRealiza(Calificacion* c){
    //añade la calificacion al contenedor de realizads
    this->calificacionesRealizadas.insert(c);
}

//añade la calificacion al contenedor de recibidas
void Usuario::asociarCalifica(Calificacion* c){
    this->calificacionesRecibidas.insert(c);
    this->ajustarCalificacion();
}


map<int, DTListarViaje> Usuario::obtenerViajes() {
    map<int, DTListarViaje> res;
    return res;
}

void Usuario::ajustarCalificacion(){
    int sumaCalif;
    int cantCalif = this->calificacionesRecibidas.size();
    for (Calificacion* c : this->calificacionesRecibidas){
        sumaCalif += c->getPuntaje();
    }
    this->setCalificacionPromedio(sumaCalif/cantCalif);
}

void Usuario::removerCalificacion(Calificacion* c){
    if (c->getUsuarioCalificador() == this){
        calificacionesRealizadas.erase(c);
    } else {
        calificacionesRecibidas.erase(c);
    }
}
