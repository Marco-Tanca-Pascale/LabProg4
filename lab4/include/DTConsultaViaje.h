#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <iostream>
#include <string>

using namespace std;

class DTConsultaViaje {
private:
    int codigo;
    string marca;
    string modelo;
    string conductor;
    float calificacionProm;
    float precioTotal;

public:
    //constructores
    DTConsultaViaje();
    DTConsultaViaje(int codigo, string marca, string modelo, string conductor, float calificacionProm, float precioTotal);

    //getters
    int getCodigo() const;
    string getMarca();
    string getModelo();
    string getConductor();
    float getCalificacionPromedio();
    float getPrecioTotal();
    
    //operador sobrecargado
    bool operator<(const DTConsultaViaje& dtcv) const;
};





ostream& operator<<(ostream& o, const DTConsultaViaje dtcv);

#endif
