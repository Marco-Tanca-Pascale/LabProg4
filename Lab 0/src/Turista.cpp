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
set<string> Turista::listarExperiencias(DTFecha desde, float min, float max) {
    set<string> resultado;

    for (experiencia* exp: experiencias){//por cada experiencia del conjunto experiencias va a evaluar lo necesario
        DTExpe dt = exp->getDT();//para tener el código de reserva, la descripción y la fecha del objeto
        float costo = exp->calcularCosto();
        bool posterior = dt.//falta arreglar/consultar

        if( && costo >= min && costo <= max){//FALTA UNA CONDICIÓN POR AGREGAR
            resultado.insert(dt.getCodigoReserva());
        }        
    }
}

//Destructor de Turista
Turista::~Turista() {}