#include "../include/DTUsuario.h"

// agregue esto para que compile joaco XD
DTUsuario::DTUsuario()
{
    this->nickname = "";
    this->nombre = "";
}

DTUsuario::DTUsuario(string nickname, string nombre)
    {
    this->nickname = nickname;
    this->nombre = nombre;
}

string DTUsuario::getNickname() const { return nickname; }
string DTUsuario::getNombre() { return nombre; }

bool DTUsuario::operator<(const DTUsuario& dtu) const {
    return this->getNickname() < dtu.getNickname();
}

ostream& operator<<(ostream& os, DTUsuario dtu) {
    os << "> Nickname: " << dtu.getNickname() << ", Nombre: " << dtu.getNombre();
    return os;
}