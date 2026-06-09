#include "../include/DTUsuarioViaje.h"

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
