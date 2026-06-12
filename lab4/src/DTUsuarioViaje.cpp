#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje()
{
    this->nickname = "";
    this->tipo = TipoUsuario::Pasajero; // no compila porque no tiene constructor vacio, uso pasajero como 0, joaco XD
}

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->tipo = tipo;
}

std::string DTUsuarioViaje::getNickname() const { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() { return tipo; }

bool DTUsuarioViaje::operator<(const DTUsuarioViaje& dtuv) const {
    return this->getNickname() < dtuv.getNickname();
}

ostream& operator<<(ostream& os, DTUsuarioViaje dtuv) {
    os << "> Nickname: " << dtuv.getNickname() << ", Tipo: " << (dtuv.getTipo() == TipoUsuario::Conductor ? "Conductor" : "Pasajero");
    return os;
}
