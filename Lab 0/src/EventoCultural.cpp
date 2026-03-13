#include "../include/EventoCultural.h"


// Constructor por defecto.
EventoCultural::EventoCultural() : Experiencia(){};

// Constructor con parametros.
// Llama al constructor de la clase padre Experiencia para inicializar los atributos heredados. Luego se asignan los valores recibidos por parámetros.
EventoCultural::EventoCultural(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas, string ubicacion, bool usoCupon) :
Experiencia(codigoReserva, descripcion, precioBase,fecha, turistas){
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
};

// El costo se calcula como #turistas * precioBase. Si se utiliza cupón, se descuenta 5 del precio base.
float EventoCultural::calcularCosto(){
    int cantTuristas = (int) this->getTuristas().size();
    return (float)(cantTuristas * (this->usoCupon ? this->getPrecioBase() - 5 : this->getPrecioBase()));
};