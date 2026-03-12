#include "../include/EventoCultural.h"


// Constructor por defecto.
EventoCultural::EventoCultural() : Experiencia(){};

// Constructor con parametros.
// Llama al constructor de la clase padre Experiencia para inicializar los atributos heredados. Luego se asignan los valores recibidos por parámetros.
EventoCultural::EventoCultural(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, string ubicacion, boolean usoCupon) :
Experiencia(codigoReserva, descripcion, precioBase,fecha){
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
};

// El costo se calcula como #turistas * precioBase. Si se utiliza cupón, se descuenta 5 del precio base.
float EventoCultural::calcularCosto(){
    return turistas.size() * (this->usoCupon ? precioBase - 5 : precioBase);
};