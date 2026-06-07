#ifndef VIAJE_H
#define VIAJE_H

#include <string>
#include <set>

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include "DTListarViaje.h"

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
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);

    ~Viaje();

    int getCodigo();

    DTFecha getFecha();

    Reserva *getReserva(std::string nickname);

    int getAsientosPublicados();

    void crearReserva(Usuario *usuario, int asientos);

    int asientosReservados();

    bool existeReserva(std::string nickname);

    DTListarViaje obtenerDatosViaje(std::string nickname);

    DTConsultaViaje obtenerViajeValido(DTFecha fecha, std::string origen, std::string destino, int asientos);

    int obtenerCodigo();

    
};

#endif
