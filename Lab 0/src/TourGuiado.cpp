#include "../include/TourGuiado.h"


// Constructor por defecto y constructor con parametros.

TourGuiado::TourGuiado() : Experiencia(){};

// Llama al constructor de la clase base Experiencia para inicializar los atributos heredados. Luego, se asignan los valores recibidos por parámetros.
TourGuiado::TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, string agencia, set<string> lugaresVisitados) :
Experiencia(codigoReserva, descripcion, precioBase,fecha){
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
};

//
float TourGuiado::calcularCosto(){
    float costo = (precioBase + 2) * lugaresVisitados.size() /* * los turistas */ ;
    return costo;
};