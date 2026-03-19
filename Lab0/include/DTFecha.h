#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;
    bool esPosterior(DTFecha fecha); //operacion para comparar fechas
    
    ~DTFecha();
};

std::ostream& operator<<(std::ostream& o, const DTFecha& fecha);

#endif