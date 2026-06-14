#include "../include/Pasajero.h"
#include "../include/Viaje.h"


using namespace std;

Pasajero::Pasajero(string nickname, string nombre, string contrasena, string email, string ci)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = ci;
}

Pasajero::~Pasajero() {
    this->reservas.clear();
}

Reserva* Pasajero::getReserva(int codigo){ 
    if (reservas.find(codigo) != reservas.end()) {
        return reservas[codigo];
    }

    return nullptr;
}

bool Pasajero::reservoViaje(int codigo) {
    if (reservas.find(codigo) != reservas.end()) {
        return true;
    }
    return false;
}

//asociacion entre pasajero y una reserva
void Pasajero::vincularReserva(Reserva* reserva) {
    int codigo = reserva->getViaje()->getCodigo();

    reservas[codigo] = reserva;
}

//Implementacion de obtenerViajes si Usuario = Pasajero.
std::map<int, DTListarViaje> Pasajero::obtenerViajes()
{
    std::map<int, DTListarViaje> res;
    map<int, Reserva*>::iterator it;

    //recorro el map 
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it) {
        // it->second nos da el puntero a la Reserva (r)
        Reserva* r = it->second;
        
        DTListarViaje dtvi = r->obtenerDatosViaje();
        
        //inserto el viaje individual en el conjunto de viajes.
        res[dtvi.getCodigo()] = dtvi;
    }

    return res;
};

void Pasajero::eliminarReserva(Reserva* res){
    this->reservas.erase(res->getViaje()->getCodigo());
}