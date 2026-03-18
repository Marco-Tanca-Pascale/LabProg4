#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "Experiencia.h"

// Clase Tour Guiado que extiende la clase abstracta Experiencia.
// Posee una agencia y un conjunto de lugares visitados. Tiene la operación de calcular el costo, que se calcula a partir del precio base, la cantidad de turistas y lugares visitados.
class TourGuiado: public Experiencia{
    private:
        string agencia;
        set<string> lugaresVisitados;

    public:
        TourGuiado();
        TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas, string agencia, set<string> lugaresVisitados);
        float calcularCosto();
};

#endif