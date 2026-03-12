#include "../include/TourGuiado.h"


// Constructor por defecto.
TourGuiado::TourGuiado() : Experiencia(){};

// Constructor con parámetros.
// Llama al constructor de la clase padre Experiencia para inicializar los atributos heredados. Luego, se asignan los valores recibidos por parámetros.
TourGuiado::TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, string agencia, set<string> lugaresVisitados) :
Experiencia(codigoReserva, descripcion, precioBase,fecha){
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
};

// El costo se calcula como (precioBase + 2) * #lugares * #turistas.
float TourGuiado::calcularCosto(){
    return (precioBase + 2) * lugaresVisitados.size() * turistas.size();
};