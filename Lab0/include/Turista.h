#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"

class Experiencia;

using namespace std;

class Turista
{
private:
    string ci, nombre, email;
    set<Experiencia*> experiencias; // conjunto de experiencias de un turista
public:
    Turista(string, string, string);
    
    string toString();
    set<string> listarExperiencias(DTFecha desde, float min, float max);

    //Agrega un elemento a una coleccion
    void agregarExperiencia(Experiencia *e);

    //Elimina una elemento de la coleccion
    void removerExperiencia(Experiencia *e);

    string getCi();
    string getNombre();

    ~Turista();
};

#endif