#include "../include/Viaje.h"
#include "../include/Vehiculo.h"
#include "../include/Conductor.h"
#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Conductor.h"
#include "../include/DTConsultaViaje.h"
#include "../include/DTVehiculosConductor.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Conductor.h"
#include "../include/DTDetalleViaje.h"
#include "../include/Calificacion.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo *vehiculo)
{
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = vehiculo;
}

Viaje::~Viaje() {}

int Viaje::getCodigo()
{
    return this->codigo;
}

DTFecha Viaje::getFecha()
{
    return this->fecha;
}

bool Viaje::existeReserva(std::string nickname)
{
    for (Reserva *r : this->reservas)
    {
        if (r->esDeUsuario(nickname))
        {
            return true;
        }
    }
    return false; 
}

int Viaje::getAsientosPublicados(){
    return this->asientosPublicados;
}

Reserva *Viaje::getReserva(std::string nickname)
{
    for (Reserva *r : this->reservas)
    {
        if (r->esDeUsuario(nickname))
        {
            return r; 
        }
    }
    return nullptr;
}

void Viaje::crearReserva(Pasajero *pasajero, int asientos)
{
    ControladorFechaActual* cfa = ControladorFechaActual::getInstance();
    DTFecha fechaActual = cfa->getFecha();
    Reserva *nuevaReserva = new Reserva(asientos, fechaActual, this, pasajero);
    this->reservas.insert(nuevaReserva);
    if (pasajero != nullptr)
    {
        pasajero->vincularReserva(nuevaReserva);
    }
}

DTListarViaje Viaje::obtenerDatosViaje(){
    DTListarViaje dtvi = DTListarViaje(this->codigo,this->fecha,this->origen,this->destino, this->vehiculo->getConductor()->getNickname());
    return dtvi;
}

DTListarViaje Viaje::obtenerDatosViaje(std::string nickname){
    DTListarViaje dtvi = DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,nickname);
    return dtvi;
}

DTDetalleViaje Viaje::obtenerDetalleViaje(){
    DTDetalleViaje dtdv = DTDetalleViaje(this->codigo, this->fecha, this->origen, this->destino, this->asientosPublicados, this->precio, this->vehiculo->getDTDetalleVehiculo(), this->obtenerDetallesReservas());
    return dtdv;
};

set<DTDetalleReserva> Viaje::obtenerDetallesReservas(){
    set<DTDetalleReserva> res;
    for (Reserva *r : this->reservas){
        DTDetalleReserva dtr = DTDetalleReserva(r->getAsientosReservados(), r->getFecha(), r->getPasajero()->getNickname());
        res.insert(dtr);
    }
    return res;
}



DTConsultaViaje* Viaje:: obtenerViajeValido(DTFecha fecha, std::string origen, std::string destino, int asientos){
    if (!(this->fecha == fecha) || this->origen != origen || this->destino != destino)
        return nullptr;

    int asientosYaReservados = 0;
    for (Reserva *r : this->reservas)
        if (r != nullptr)
            asientosYaReservados += r->getAsientosReservados();
    if (asientosYaReservados + asientos > this->asientosPublicados)
        return nullptr;

    Vehiculo* v = this->vehiculo;
    std::string marcaVehiculo = v->getMarca();
    std::string modeloVehiculo = v->getModelo();
    std::string nombreCond = v->getNicknameConductor();
    Conductor* c = this->vehiculo->getConductor();
    float califCond = c->getCalificacionPromedio();

    DTConsultaViaje *dtcv = new DTConsultaViaje(this->codigo, marcaVehiculo, modeloVehiculo, nombreCond, califCond, this->precio );

    return dtcv;
}

int Viaje::getAsientosReservados() {
    int asientosYaReservados = 0;
    for (auto it=this->reservas.begin(); it!=this->reservas.end(); ++it)
    {
        Reserva* r = *it;
        if (r != nullptr)
        {
            asientosYaReservados += r->getAsientosReservados();
        }
    }
    return asientosYaReservados;
}

void Viaje::desvincularYDestruirRelaciones(){
    if(this->vehiculo != nullptr){
        this->vehiculo->eliminarViaje(this);
        this->vehiculo = nullptr;
    }

    for(Reserva* res: this->reservas ){
        if(res != nullptr && res->getPasajero() != nullptr){
            res->destruirCalificaciones();
            res->getPasajero()->eliminarReserva(res); 
        }
    }

    for(Reserva* res: this->reservas){
        if(res != nullptr){
            delete res;
        }
    }
    
    this->reservas.clear();
}