#include "../include/Turista.h"
#include "../include/Experiencia.h"
#include "../include/DTExpe.h"
#include "../include/DTFecha.h"

//Constructor de Turista
Turista::Turista(string ci, string nombre, string email) {
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}

//Devuelve un string de la forma ci->nombre/email
string Turista::toString() {
    return this->ci + "->" + this->nombre + "/" + this->email;
}


//De la clase Turista obtiene el código de reserva de todas sus experiencias cuya fecha sea posterior al parámetro desde y costo sea mayor o igual que min y menor igual que max. 
set<string> Turista::listarExperiencias(DTFecha desde, float min, float max) {
    set<string> resultado;
    set<Experiencia*>::iterator it;

    for (it = experiencias.begin(); it != experiencias.end(); ++it) {
        Experiencia* exp = *it;
        
        DTExpe dt = exp->getDT();//para tener el código de reserva, la descripción y la fecha del objeto
        float costo = exp->calcularCosto();

        if(dt.getFecha().esPosterior(desde) && costo >= min && costo <= max){
            resultado.insert(dt.getCodigoReserva());
        }        
    }

    return resultado;
}

//agrega una experiencia a un turista
void Turista::agregarExperiencia(Experiencia *e)
{
    experiencias.insert(e);
}

string Turista::getCi() {
    return this->ci;
}

string Turista::getNombre() {
    return this->nombre;
}

void Turista::removerExperiencia(Experiencia *e) {
    if (e != NULL) {
        this->experiencias.erase(e); 
    }
}

//Destructor de Turista
Turista::~Turista() {}