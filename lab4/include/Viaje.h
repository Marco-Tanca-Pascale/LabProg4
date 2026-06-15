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
using namespace std;

class Vehiculo;
class Reserva;
class Usuario;

class Viaje
{
private:
    int codigo;
    DTFecha fecha;
    string origen;
    string destino;
    int asientosPublicados;
    float precio;

    Vehiculo *vehiculo;
    set<Reserva *> reservas;

public:
    Viaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio, Vehiculo *vehiculo);

    ~Viaje();

    //Metodos

    //getters
    int getCodigo();
    DTFecha getFecha();

    Reserva *getReserva(string nickname);

    int getAsientosPublicados();
    int getAsientosReservados();

    bool existeReserva(string nickname);

    //metodo sobrecargado
    //obtiene la info basica del viaje
    DTListarViaje obtenerDatosViaje();
    //me da la info de este viaje pero personalizada para ese usuario
    DTListarViaje obtenerDatosViaje(string nickname);

    //obtiene la info de este viaje en detalle
    DTDetalleViaje obtenerDetalleViaje();

    //obtiene la info en detalle de las reservas hechas sobre este viaje
    set<DTDetalleReserva> obtenerDetallesReservas();

    DTConsultaViaje *obtenerViajeValido(DTFecha fecha, string origen, string destino, int asientos);

    //destruye las relaciones atadas a este viaje
    void desvincularYDestruirRelaciones();

    //crea una Reserva y la vincula a un pasajero
    void crearReserva(Pasajero *pasajero, int asientos);

    
};

#endif
