#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(string nickname, string nombre, string contrasena, string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena; 
    this->email = email;
    this->calificacionPromedio = 0.0;
}

//destructor
Usuario::~Usuario() {}

//getters
//devuelve el nickname unico del usuario
string Usuario::getNickname(){
    return this->nickname;
}

//devuelve el nombre del usuario
string Usuario::getNombre(){
    return this->nombre;
}


//cambia el valor del promedio de las calificacioones por uno nuevo
void Usuario::setCalificacionPromedio(float nueva){
    this->calificacionPromedio = nueva;
}

//devuelve el promedio de calificaciones actual del usuario 
float Usuario::getCalificacionPromedio(){
    return this->calificacionPromedio;
}

//guarda una calificacion en el conjunto de las que este usuario le realizo a otros
void Usuario::asociarRealiza(Calificacion* c){
    //añade la calificacion al contenedor de realizads
    this->calificacionesRealizadas.insert(c);
}

//guarda una calificacion recibida y a su vez recalcula el promedio del usuario 
void Usuario::asociarCalifica(Calificacion* c){
    this->calificacionesRecibidas.insert(c);
    this->ajustarCalificacion();
}

//metodo virtual que devuelven las clases hijas de Usuario (Pasajero / Conductor)
map<int, DTListarViaje> Usuario::obtenerViajes() {
    map<int, DTListarViaje> res;
    return res;
}

//recore las calificaciones recibidas, suma los puntajes y actualiza el promedio
void Usuario::ajustarCalificacion(){
    int sumaCalif;
    int cantCalif = this->calificacionesRecibidas.size();
    for (Calificacion* c : this->calificacionesRecibidas){
        sumaCalif += c->getPuntaje();
    }
    this->setCalificacionPromedio(sumaCalif/cantCalif);
}

//chequea si la calificacion la hizo o la recibio este usuario y la quita del coonjunto que corresponda
void Usuario::removerCalificacion(Calificacion* c){
    if (c->getUsuarioCalificador() == this){
        calificacionesRealizadas.erase(c);
    } else {
        calificacionesRecibidas.erase(c);
    }
}