#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include <set>
#include <iostream>
#include "./DTFecha.h"

using namespace std;

class DTExpe
{
private:
    string codigoReserva;
    string descripcion;
    DTFecha fecha;
    set<string> turistas;
public:
    DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string> turistas);

    string getCodigoReserva() const;
    string getDescripcion() const;
    DTFecha getFecha() const;
    set<string> getTuristas() const;
    
    ~DTExpe();
};

ostream &operator<<(ostream &o, const DTExpe &exp);

#endif