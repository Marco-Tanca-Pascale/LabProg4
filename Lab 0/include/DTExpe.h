#include <string>
#include <set>
#include <iostream>
#include "DTFecha.h"

class DTExpe
{
private:
    std::string codigoReserva;
    std::string descripcion;
    DTFecha fecha;
    std::set<std::string> turistas;
public:
    DTExpe(std::string, std::string, DTFecha, std::set<std::string>)

    std::string getCodigoReserva();
    std::string getDescripcion();
    DTFecha getFecha();
    std::set<std::string> getTuristas()
    
    ~DTExpe();
};
