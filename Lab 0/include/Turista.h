#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"


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
