#include "../include/Experiencia.h"
#include "../include/Turista.h"

using namespace std;
//implementacion 

//implemento constructores y destructor
Experiencia::Experiencia(){

};

Experiencia::Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas){
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
    // pseudoatributo para representar la asociacion con clase turista
    this->turistas = turistas;
}

Experiencia::~Experiencia(){
}

//agrega un turista a una experiencia
void Experiencia::agregarTurista(Turista *t)
{
    turistas.insert(t);
}

//implemento funciones
DTExpe Experiencia::getDT() {
    std::set<std::string> nombresTuristas;

    std::set<Turista*>::const_iterator it;
    for (it = this->turistas.begin(); it != this->turistas.end(); ++it) {
        Turista* t = *it;
        
        nombresTuristas.insert(t->getNombre());
    }

    DTExpe dt(this->codigoReserva, this->descripcion, this->fecha, nombresTuristas);

    return dt;
}

float Experiencia::getPrecioBase(){
    return this->precioBase;
}

set<Turista*> Experiencia::getTuristas(){
    return this->turistas;
}

string Experiencia::getCodigoReserva(){
    return this->codigoReserva;
}



