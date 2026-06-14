#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include "Reserva.h"
#include "DTListarViaje.h"
#include <string>
#include <map>

using namespace std;
class Pasajero : public Usuario {
private:
    string ci;
    //reservas indexadas por codigo
    map<int,Reserva*> reservas;

public:
    Pasajero(string nickname, string nombre, string contrasena, string email, string ci);
    ~Pasajero();

    //Metodos 

    //getters
    //obtiene la reserva asociada al codigo indicado
    Reserva* getReserva(int codigo); 

    //verifica si el pasasjero tiene una reserva para el viaje para el codigo indicado
    bool reservoViaje(int codigo);

    //asociacion entre pasajero y una Reserva reserva
    void vincularReserva(Reserva* reserva);

    // Implementación específica de Usuario para obtener los viajes del pasajero.
    std::map<int, DTListarViaje> obtenerViajes() override;

    void eliminarReserva(Reserva* res);

};

#endif
