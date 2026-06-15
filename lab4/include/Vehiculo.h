#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"
#include "DTDetalleVehiculo.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
class Viaje;
class Conductor;
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Vehiculo {
private:
    string matricula;
    int capacidad;
    string marca;
    string modelo;
    TipoVehiculo tipo;
    //puesto que es una relacion bidireccional necesitamos poder acceder al conductor y por otra parte a los viajes
    Conductor* duenio;
    map<int, Viaje*> viajes;

public:
    Vehiculo(string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo);

    //getters
    string getMatricula();
    string getMarca();
    string getModelo();
    Conductor* getConductor();
    string getNicknameConductor();
    map<int, Viaje*> getViajes();
    Viaje* getViaje(int codigo);
    DTVehiculosConductor getDTVehiculoConductor();
    int getCapacidad();
    DTDetalleVehiculo getDTDetalleVehiculo();

    //setters
    void setDuenio(Conductor* c);

    //devuelve true si existe un viaje realizado por este vehículo con ese codigo
    bool existeViaje(int codigo);

    //obtiene los datos relacionados al vehiculo para formar el DTConsultaViaje.
    DTConsultaViaje obtenerDatosRelacionados();

    //obtiene los datos relacionados a los viajes relacionados a este vehiculo
    std::map<int, DTListarViaje> obtenerDatosViaje(string nickname);
    
    //verifica que hayan viajes con dicho conductor en cierta fecha
    bool hayViajesConductor(DTFecha fecha);

    //verifica que hayan viajes con este vehiculo en cierta fecha
    bool hayViajesFecha(DTFecha fecha);

    //asocia otro viaje a este vehiculo
    void asociarViaje(Viaje* viaje);

    //elimina un viaje asociado a este vehiculo
    void eliminarViaje(Viaje* viaje);
    ~Vehiculo();
};

#endif
