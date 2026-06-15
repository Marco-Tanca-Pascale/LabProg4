#ifndef CONTROLADOR_VIAJE_H
#define CONTROLADOR_VIAJE_H

#include "Viaje.h"
#include "Vehiculo.h"
#include <map>
using namespace std;
#include "IControladorViaje.h"

//fwd declarations
class Vehiculo;
class Viaje;

class ControladorViaje : public IControladorViaje {
private:
    static ControladorViaje* instancia;
    int codigo_memo;

    map<int, Viaje*> viajes;

    //constructor privado para mantener el patrón singleton
    ControladorViaje();

public:
    //devuelve la unica instancia del controlador para mantener el patrón singleton
    static ControladorViaje* getInstance();

    //Metodos

    //listar
    virtual map<string, DTVehiculosConductor> listarVehiculosConductor(string nickname) override;
    virtual set<string> listarPasajeros() override;
    virtual set<DTListarViaje> listarViajes() override;

    //alta a viaje
    virtual bool altaViaje(string matricula, DTFecha fecha, string origen, string destino, int asientos, float precios) override;

    //consulta los viajes disponibles
    virtual map<int, DTConsultaViaje> consultarViajes(DTFecha fecha, string origen, string destino, int asientos) override;

    //crea un viaje
    virtual Viaje* crearViaje(Vehiculo* v, DTFecha fecha, string origen, string destino, int asientos, float precio) override;

    //devuelve los datos de un viaje en detalle
    virtual DTDetalleViaje detalleViaje(int codigo) override;

    //referidas a eliminar un viaje
    virtual void eliminarViaje() override;
    virtual void cancelarEliminarViaje() override;

    //crea una reserva a nombre de cierto usuario para el viaje con este codigo
    virtual bool generarReserva(string nickname, int codigo, int asientos) override;

    //getter
    const map<int, Viaje*>& getViaje() const;
};

#endif
