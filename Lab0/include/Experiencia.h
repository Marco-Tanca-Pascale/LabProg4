#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

//incluyo librerias 
//string no existe en el lenguaje base en C++
#include <set>
#include <string>
#include "DTFecha.h"
#include "DTExpe.h"

using namespace std;

class Turista;

//clase abstracta no podemos crear objetos de ella
class Experiencia{
    private:
        string codigoReserva;
        string descripcion;
        int precioBase;
        DTFecha fecha;
        set<Turista*> turistas;
        
    public:
        // constructores y destructor
        Experiencia();
        Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha fecha, set<Turista*> turistas);
        virtual ~Experiencia();

        // agrega un elemento a una coleccion
        void agregarTurista(Turista *t);

        // getters
        float getPrecioBase();
        set<Turista*> getTuristas();
        DTExpe getDT();

        virtual float calcularCosto() = 0;
};

#endif 