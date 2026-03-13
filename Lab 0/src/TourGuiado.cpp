#include "../include/TourGuiado.h"


// Constructor por defecto.
TourGuiado::TourGuiado() : Experiencia(){};

// Constructor con parámetros.
// Llama al constructor de la clase padre Experiencia para inicializar los atributos heredados. Luego, se asignan los valores recibidos por parámetros.
TourGuiado::TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas, string agencia, set<string> lugaresVisitados) :
Experiencia(codigoReserva, descripcion, precioBase,fecha, turistas){
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
};

// El costo se calcula como (precioBase + 2) * #lugares * #turistas.
float TourGuiado::calcularCosto(){
    int cantLugares = (int) this->lugaresVisitados.size();
    int cantTuristas = (int) this->getTuristas().size();
    return (float)((this->getPrecioBase() + 2) * cantLugares * cantTuristas);
};