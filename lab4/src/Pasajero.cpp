#include "../include/Pasajero.h"
#include "../include/Viaje.h"


using namespace std;

Pasajero::Pasajero(string nickname, string nombre, string contrasena, string email, string ci)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = ci;
}

//destructor 
Pasajero::~Pasajero() {
    // Luego limpio el map
    this->reservas.clear();
}

//busca una reserva por su codigo y la devuelve , si no la encuentra entonces se devuelve nullptr
Reserva* Pasajero::getReserva(int codigo){ 
    if (reservas.find(codigo) != reservas.end()) {
        return reservas[codigo];
    }

    return nullptr;
}

//se fija si el pasajero tiene una reserva registrada para el codigo del viaje pasado por parametro
bool Pasajero::reservoViaje(int codigo) {
    if (reservas.find(codigo) != reservas.end()) {
        return true;
    }
    return false;
}

//Asociacion entre pasajero y una reserva
//se vincula una reserva al pasajero usando el codigo del viaje como clave
void Pasajero::vincularReserva(Reserva* reserva) {
    int codigo = reserva->getViaje()->getCodigo();

    reservas[codigo] = reserva;
}

//Implementacion de obtenerViajes si Usuario = Pasajero.
//recorre todas las reservas del pasajero para armar y devolver un DT de c/viaje
map<int, DTListarViaje> Pasajero::obtenerViajes()
{
    map<int, DTListarViaje> res;
    map<int, Reserva*>::iterator it;

    //recorro el map de reservas
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it) {
        // it->second da el puntero a la Reserva (r)
        Reserva* r = it->second;
        
        //pido los datos del viaje a la reserva
        DTListarViaje dtvi = r->obtenerDatosViaje();
        
        //inserto el viaje individual en el conjunto de viajes.
        res[dtvi.getCodigo()] = dtvi;
    }

    return res;
};

//quita la reserva del map del pasajero usando el codigo del viaje.
void Pasajero::eliminarReserva(Reserva* res){
    this->reservas.erase(res->getViaje()->getCodigo());
}