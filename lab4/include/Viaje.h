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

    int getCodigo();

    DTFecha getFecha();

    Reserva *getReserva(string nickname);

    int getAsientosPublicados();

    void crearReserva(Pasajero *pasajero, int asientos);

    int getAsientosReservados();

    bool existeReserva(string nickname);

    //sobrecargo metodo
    //me da la info basica del viaje
    DTListarViaje obtenerDatosViaje();
    //me da la info de este viaje pero personalizada para ese usuario
    DTListarViaje obtenerDatosViaje(string nickname);

    DTDetalleViaje obtenerDetalleViaje();

    set<DTDetalleReserva> obtenerDetallesReservas();

    DTConsultaViaje *obtenerViajeValido(DTFecha fecha, string origen, string destino, int asientos);

    //para eliminarViaje()
    void desvincularYDestruirRelaciones(); //falta implementar

    
};

#endif
