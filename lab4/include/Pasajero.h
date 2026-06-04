#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>

using namespace std;
class Pasajero : public Usuario {
private:
    string ci;
    //coleccion de Reservas vinculadas a pasajero ?
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
   // void vincularReserva() me falta parametro de Reserva

    // Implementación específica de Usuario para obtener los viajes del pasajero.
   void obtenerViajes() override; //

};

#endif
