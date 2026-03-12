#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "Experiencia.h"

// Clase Evento Cultural que extiende la clase abstracta Experiencia.
// Posee una ubicacion y un booleano para indicar si se utiliza un cupon. Tiene la operación de calcular el costo, que se calcula a partir del precio base y la cantidad de lugares visitados.
class EventoCultural: public Experiencia{
    private:
        string ubicacion;
        bool usoCupon;

    public:
        EventoCultural();
        EventoCultural(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas, string ubicacion, bool usoCupon);
        float calcularCosto() override;
};

#endif