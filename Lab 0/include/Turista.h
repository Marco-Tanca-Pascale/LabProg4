#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"
#include "Experiencia.h"


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

    ~Turista();
};

#endif