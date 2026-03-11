#include "../include/Turista.h"

//Constructor de Turista
Turista::Turista(string ci, string nombre, string email) {
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

//Devuelve un string de la forma ci->nombre/email
string Turista::toString() {
    return this->ci + '->' + this->nombre + '/' + this->email;
}
    
//De la clase Turista obtiene el código de reserva de todas sus experiencias cuya fecha sea posterior al parámetro desde y costo sea mayor o igual que min y menor igual que max. 
set<String> Turista::listarExperiencias(DTFecha desde, float min, float max) {

}

//Destructor de Turista
Turista::~Turista() {}