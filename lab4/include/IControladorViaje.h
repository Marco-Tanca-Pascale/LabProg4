#ifndef IVIAJE_H
#define IVIAJE_H

#include <set>
#include <map>
#include "DTFecha.h"
#include "DTVehiculosConductor.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
using namespace std;

//forward declarations 
class Vehiculo;
class Viaje;
// ---- 
class IControladorViaje {
public:
    virtual ~IControladorViaje() {}
    
    virtual map<string, DTVehiculosConductor> listarVehiculosConductor(string nickname) = 0;
    virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) = 0;
    virtual set<string> listarPasajeros() = 0;
    virtual Vehiculo* getVehiculo(string matricula) = 0;
    virtual Viaje* crearViaje(Vehiculo* v, DTFecha fecha, string origen, string destino, int asientos, float precio) = 0;
    virtual map<int, DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) = 0;
    virtual set<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
    virtual bool generarReserva(string nickname, int codigo, int asientos) = 0;
};

#endif