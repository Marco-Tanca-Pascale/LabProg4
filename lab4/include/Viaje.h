#ifndef VIAJE_H
#define VIAJE_H

#include <string>
#include <set>

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"
#include "DTDetalleReserva.h"
#include "Pasajero.h"

class Vehiculo;
class Reserva;
class Usuario;

class Viaje
{
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    Vehiculo *vehiculo;
    std::set<Reserva *> reservas;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo *vehiculo);
    ~Viaje();

    //Metodos

    //getters
    int getCodigo();
    DTFecha getFecha();
    Reserva *getReserva(std::string nickname);
    int getAsientosPublicados();
    int getAsientosReservados();

    //crea una reserva de este viaje
    void crearReserva(Pasajero *pasajero, int asientos);

    //verifica si existe una reserva hecha por cierto usuario
    bool existeReserva(std::string nickname);

    //metodo sobrecargado
    //obtiene la info basica del viaje
    DTListarViaje obtenerDatosViaje();
    //obtiene la info de este viaje pero personalizada para ese usuario
    DTListarViaje obtenerDatosViaje(std::string nickname);

    //obtiene la info de este viaje en detalle
    DTDetalleViaje obtenerDetalleViaje();

    //obtiene la info en detalle de las reservas hechas sobre este viaje
    set<DTDetalleReserva> obtenerDetallesReservas();

    //obtiene el viaje que tenga tal origen, destino, fecha y asientos disponibles
    DTConsultaViaje* obtenerViajeValido(DTFecha fecha, std::string origen, std::string destino, int asientos);

    //destruye las relaciones atadas a este viaje
    void desvincularYDestruirRelaciones();

    
};

#endif
