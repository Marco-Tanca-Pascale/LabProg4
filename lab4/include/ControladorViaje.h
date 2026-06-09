#ifndef CONTROLADOR_VIAJE_H
#define CONTROLADOR_VIAJE_H

#include <map>
#include "IControladorViaje.h"

class ControladorViaje : public IControladorViaje {
private:
    static ControladorViaje* instancia;
    map<int, ControladorViaje*> viajes;

    ControladorViaje();

public:
    static ControladorViaje* getInstance();

    virtual set<DTVehiculosConductor> listarVehiculosConductor(string nickname) override;
    virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) override;
    virtual set<string> listarPasajeros() override;
    virtual set<DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) override;
    virtual set<DTListarViaje> listarViajes() override;
    virtual DTDetalleViaje detalleViaje(int codigo) override;
    virtual void eliminarViaje() override;
    virtual void cancelarEliminarViaje() override;

    const map<string, ControladorViaje*>& getViaje() const;
};

#endif