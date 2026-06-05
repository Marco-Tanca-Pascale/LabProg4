#ifndef DT_FECHA_H
#define DT_FECHA_H

#include <iostream>
using namespace std;

class DTFecha {
private:
    int dia;
    int mes;
    int anio;
public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    bool operator==(DTFecha other);
};

ostream& operator<<(ostream& os, DTFecha f);

#endif
