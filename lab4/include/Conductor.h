#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "Vehiculo.h"
#include <set>
#include <map>

using namespace std;
class Conductor : public Usuario {
private:
    set<TipoLibreta> libs;
    //relacion con vehiculo 
    map<std::string,Vehiculo*> vehiculos;

public:
    Conductor(string nickname, string nombre, string contrasena,string email, set<TipoLibreta> libs);
    ~Conductor();

    //Metodos 
    
    //verifica si el conductor posee n vehiculo con la matricula indicada
    bool tieneVehiculo(string matricula);

    //verifica si el conductor posee una libreta del tipo indicado
    bool tieneLibreta(TipoLibreta tipo);

    //Asocia un vehiculo al conductor
    void agregarVehiculo(Vehiculo* vehiculo);

    //obtiee el promedio de calificaciones del conductor
    float getCalificacionProm(); //aviso que cambie el int por el float porque lo decia en el DCD y porque lo necesitaba para el DTConsultaViaje ;) :avi

    //verifica si el conductor es responsable del viaje identificado por el codigo
    bool esConductorDe(string codigo);

    //obtiene el viaje cuyo codigo se reciibe como parametro 
    Viaje* getViaje(string codigo);

    //lista los vehiculos registrados por el conductor
    void listarVehiculos();

    //verifica si el conductor tiene viajes asociados en una fecha determinada
    bool hayViajesFechaConductor(DTFecha fecha);

    // Implementación específica de Usuario para obtener los viajes del conductor.
    void obtenerViajes() override;
};

#endif
