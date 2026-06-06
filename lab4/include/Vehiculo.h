#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h" // puede ser forward declaration, depende de las otras implementaciones
#include "DTVehiculosConductor.h"
#include "Viaje.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
class Conductor;
#include <set>
#include <vector>
#include <string>


class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    //puesto que es una relacion bidireccional necesitamos poder acceder al conductor y por otra parte a los viajes
    Conductor* duenio;
    std::set<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    std::string getNicknameConductor();
    std::set<Viaje*> getViajes();
    bool existeViaje(int codigo);
    Viaje* getViaje(int codigo);
    DTConsultaViaje obtenerDatosRelacionados();//PREGUNTA: ESTA BIEN USAR ESE DT AUNQUE LE FALTEN DATOS POR ASIGNAR(QUE SE LE ASIGNARAN LUEGO)? O DEBO CREAR UN NUEVO DATATYPE?? O DEBO USAR UNA COLECCION GENÉRICA??
    std::vector<DTListarViaje> obtenerDatosViaje(std::string nickname);
    DTVehiculosConductor getDTVehiculoConductor();
    int getCapacidad();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje(Viaje* viaje);
    ~Vehiculo();
};

#endif
