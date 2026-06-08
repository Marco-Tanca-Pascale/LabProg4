#ifndef IVIAJE_H
#define IVIAJE_H

#include <set>
#include "DTFecha.h"
#include "DTVehiculosConductor.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
using namespace std;

class IControladorViaje {
public:
    virtual ~IControladorViaje() {}
    
    virtual set<DTVehiculosConductor> listarVehiculosConductor(string nickname) = 0;
    virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) = 0;
    virtual set<string> listarPasajeros() = 0;
    virtual set<DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) = 0;
    virtual set<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
};

#endif