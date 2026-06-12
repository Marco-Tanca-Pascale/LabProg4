#ifndef CONTROLADOR_VIAJE_H
#define CONTROLADOR_VIAJE_H

//agrego : 
#include "Viaje.h"
#include "Vehiculo.h"
//--
#include <map>
#include "IControladorViaje.h"

//agrego : 
class Vehiculo;
class Viaje;

class ControladorViaje : public IControladorViaje {
private:
    static ControladorViaje* instancia;
    int codigo_memo;

    map<int, Viaje*> viajes;
    map<string, Vehiculo*> vehiculos;

    ControladorViaje();

public:
    static ControladorViaje* getInstance();

    virtual map<string, DTVehiculosConductor> listarVehiculosConductor(string nickname) override;
    virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) override;
    virtual set<string> listarPasajeros() override;
    virtual map<int, DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) override;
    virtual Vehiculo* getVehiculo(string matricula) override;
    virtual Viaje* crearViaje(Vehiculo* v, DTFecha fecha, string origen, string destino, int asientos, float precio) override;
    virtual set<DTListarViaje> listarViajes() override;
    virtual DTDetalleViaje detalleViaje(int codigo) override;
    virtual void eliminarViaje() override;
    virtual void cancelarEliminarViaje() override;
    virtual bool generarReserva(string nickname, int codigo, int asientos) override;

    const map<int, Viaje*>& getViaje() const;
    const map<string, Vehiculo*>& getVehiculo() const;
};

#endif
