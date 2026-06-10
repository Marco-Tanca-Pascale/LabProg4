#include "../include/Pasajero.h"
#include "../include/Viaje.h"


using namespace std;

Pasajero::Pasajero(string nickname, string nombre, string contrasena, string email, string ci)
    : Usuario(nickname, nombre, contrasena, email, 0) {
    this->ci = ci;
}

Pasajero::~Pasajero() {
    //cuando se destruye el pasajero las reservas tambien ?
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
    //en el map de reservas, asocia la clavr del codigo a la reserva.

    reservas[codigo] = reserva;
}

//Implementacion de obtenerViajes si Usuario = Pasajero.
//nahue: cambie de vector a set
set<DTListarViaje> Pasajero::obtenerViajes(){
    set<DTListarViaje> res;
    //   _ *[for each r] recorro el map de reservas
    map<int, Reserva*>::iterator it;

    //recorro el map 
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it) {
        // it->second nos da el puntero a la Reserva (r)
        Reserva* r = it->second;
        
        // 1.2.2 dtvi := obtenerDatosViaje()
        DTListarViaje dtvi = r->obtenerDatosViaje();
        
        //inserto el viaje individual en el conjunto de viajes.
        res.insert(dtvi);
    }

    return res;

};


