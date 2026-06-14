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

class Vehiculo; //forward declaration
class Viaje;
using namespace std;

class Conductor : public Usuario {
private:
    set<TipoLibreta> libs;
    //relacion con vehiculo de 1 a muchos
    //uso map porque la matricula es unica
    map<string, Vehiculo*> vehiculos;

public:
    Conductor(string nickname, string nombre, string contrasena,string email, set<TipoLibreta> libs);
    ~Conductor();

    //Metodos 
    
    //verifica si el conductor posee n vehiculo con la matricula indicada
    bool tieneVehiculo(string matricula);

    //verifica si el conductor posee una libreta del tipo indicado
    bool tieneLibreta(TipoVehiculo tipo);

    //Asocia un vehiculo al conductor
    void agregarVehiculo(Vehiculo* vehiculo);

    //obtiee el promedio de calificaciones del conductor
    float getCalificacionProm(); 

    //verifica si el conductor es responsable del viaje identificado por el codigo
    bool esConductorDe(int codigo);

    //obtiene el viaje cuyo codigo se reciibe como parametro 
    Viaje* getViaje(int codigo);

    //lista los vehiculos registrados por el conductor
    map<string, DTVehiculosConductor> listarVehiculos();

    //verifica si el conductor tiene viajes asociados en una fecha determinada
    bool hayViajesFechaConductor(DTFecha fecha);

    // Implementación específica de Usuario para obtener los viajes del conductor.
    map<int, DTListarViaje> obtenerViajes() override;

    const map<string, Vehiculo*>& getVehiculos() const;

    Vehiculo* getVehiculo(string matricula);
};
#endif
