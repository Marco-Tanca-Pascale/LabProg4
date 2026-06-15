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

Viaje::Viaje(int codigo, DTFecha fecha, string origen, string destino, int asientosPublicados, float precio, Vehiculo *vehiculo)
{
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = vehiculo;
}

//destructor vacio porque la limpieza de reservas se hace en el metodo de desvincularYDestruitRelaciones
Viaje::~Viaje() {}

//devuelve el codigo identificador del viaje
int Viaje::getCodigo()
{
    return this->codigo;
}

//devuelve la fecha programada para el viaje
DTFecha Viaje::getFecha()
{
    return this->fecha;
}

//chequea si algun pasajero con ese nickname ya tiene una reserva en este viaje
bool Viaje::existeReserva(string nickname)
{
    for (Reserva *r : this->reservas)
    {
        if (r->esDeUsuario(nickname))
        {
            return true; //encontro reserva de usuario
        }
    }
    return false; 
}

//Devuelve la cantidad maxima de asientos que se ofrecieron originalmente
int Viaje::getAsientosPublicados(){
    return this->asientosPublicados;
}

//devuelve el puntero a la reserva del pasajero segun nickname
Reserva *Viaje::getReserva(string nickname)
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

//crea una reserva, la guarda en el viaje y se la vincula al pasajero
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

//devuelve un DT con el nickname del conductor obtenido desde el vehiculo
DTListarViaje Viaje::obtenerDatosViaje(){
    DTListarViaje dtvi = DTListarViaje(this->codigo,this->fecha,this->origen,this->destino, this->vehiculo->getConductor()->getNickname());
    return dtvi;
}


//sobrecarga: devuelve el dt del viaje forzando el nickname pasado por parametro
DTListarViaje Viaje::obtenerDatosViaje(string nickname){
    DTListarViaje dtvi = DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,nickname);
    return dtvi;
}

//genera y devuelve un dt con el detalle del viaje,su vehiculo y todas sus reservas.
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


//verifica si el viaje coincide con la busqueda y si le quedan asientos disponibles para retornar el dt
DTConsultaViaje* Viaje:: obtenerViajeValido(DTFecha fecha, string origen, string destino, int asientos){
    if (!(this->fecha == fecha) || this->origen != origen || this->destino != destino)
        return nullptr;
    //se cuentan cuantos asientos hay ocupados
    int asientosYaReservados = 0;
    for (Reserva *r : this->reservas)
        if (r != nullptr)
            asientosYaReservados += r->getAsientosReservados();
    //si no encuentro asientos pedidos por el usuario entonces se descarta        
    if (asientosYaReservados + asientos > this->asientosPublicados)
        return nullptr;

    //obtengo info del vehiculo y del conductor    
    Vehiculo* v = this->vehiculo;
    string marcaVehiculo = v->getMarca();
    string modeloVehiculo = v->getModelo();
    string nombreCond = v->getNicknameConductor();
    Conductor* c = this->vehiculo->getConductor();
    float califCond = c->getCalificacionPromedio();

    DTConsultaViaje *dtcv = new DTConsultaViaje(this->codigo, marcaVehiculo, modeloVehiculo, nombreCond, califCond, this->precio );

    return dtcv;
}

//suma y devuelve la cantidad total de asientos reservados que tiene el viaje
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

//rompe todos los vincculos del viaje con el vehiculo y borra todas sus reservas asociadas de la memoria
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