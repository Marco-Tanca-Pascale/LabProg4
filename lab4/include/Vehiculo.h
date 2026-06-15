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
    string getMatricula();
    string getMarca();
    string getModelo();
    Conductor* getConductor();
    string getNicknameConductor();
    map<int, Viaje*> getViajes();
    bool existeViaje(int codigo);
    Viaje* getViaje(int codigo);
    void setDuenio(Conductor* c);
    DTConsultaViaje obtenerDatosRelacionados();
    map<int, DTListarViaje> obtenerDatosViaje(string nickname);
    DTVehiculosConductor getDTVehiculoConductor();
    int getCapacidad();
    DTDetalleVehiculo getDTDetalleVehiculo();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    void asociarViaje(Viaje* viaje);
    void eliminarViaje(Viaje* viaje);
    ~Vehiculo();
};

#endif
