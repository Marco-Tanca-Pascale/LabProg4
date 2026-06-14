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
    this->calificacionesRealizadas.push_back(c);
}

//añade la calificacion al contenedor de recibidas
void Usuario::asociarCalifica(Calificacion* c){
    this->calificacionesRecibidas.push_back(c);
    this->ajustarCalificacion();
}


//la implementacion de este metodo será distinta para Pasajero y para Conductor
// utilicen map en vez de vector para este metodo porfa
map<int, DTListarViaje> Usuario::obtenerViajes() {
    map<int, DTListarViaje> res;
    //...
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
    //si podemos cambiar el vector<Calificacion*> calificacionesRealizadas; por un set sería mucho mas facil el borrado

    //removemos el vector de las calificaciones realizadas
    for(auto it = this->calificacionesRealizadas.begin(); it != this->calificacionesRealizadas.end(); it++){
        if(*it == c){
            this->calificacionesRealizadas.erase(it);
            break;
        }
    }

    //removemos el vector de calificaciones recibidas
    for(auto it = this->calificacionesRecibidas.begin(); it != this->calificacionesRecibidas.end(); it++){
        if(*it == c){
            this->calificacionesRecibidas.erase(it);
            break;
        }
    }
}
