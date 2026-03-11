#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"

using namespace std;

class DTExpe
{
private:
    string codigoReserva;
    string descripcion;
    DTFecha fecha;
    set<string> turistas;
public:
    DTExpe(string, string, DTFecha, set<string>)

    string getCodigoReserva();
    string getDescripcion();
    DTFecha getFecha();
    set<string> getTuristas()
    
    ~DTExpe();
};
