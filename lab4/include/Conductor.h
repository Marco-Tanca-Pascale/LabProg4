#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "Viaje.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTVehiculosConductor.h"
#include <set>
#include <map>

//fwd declarations
class Vehiculo; 
class Viaje;

using namespace std;

class Conductor : public Usuario {
private:
    set<TipoLibreta> libs;
    map<string, Vehiculo*> vehiculos;

public:
    Conductor(string nickname, string nombre, string contrasena,string email, set<TipoLibreta> libs);
    ~Conductor();

    //Metodos 
    
    //verifica si el conductor posee un vehiculo con la matricula indicada
    bool tieneVehiculo(string matricula);

    //verifica si el conductor posee una libreta del tipo indicado
    bool tieneLibreta(TipoVehiculo tipo);

    //asocia un vehiculo al conductor
    void agregarVehiculo(Vehiculo* vehiculo);

    //verifica si el conductor es responsable del viaje identificado por el codigo
    bool esConductorDe(int codigo);

    //lista los vehiculos registrados por el conductor
    map<string, DTVehiculosConductor> listarVehiculos();

    //verifica si el conductor tiene viajes asociados en una fecha determinada
    bool hayViajesFechaConductor(DTFecha fecha);

    //implementación específica de Usuario para obtener los viajes del conductor.
    map<int, DTListarViaje> obtenerViajes() override;

    //getters
    const map<string, Vehiculo*>& getVehiculos() const;
    Viaje* getViaje(int codigo);
    Vehiculo* getVehiculo(string matricula);
    float getCalificacionPromedio(); 
};
#endif
