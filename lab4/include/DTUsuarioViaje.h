#ifndef DT_USUARIO_VIAJE_H
#define DT_USUARIO_VIAJE_H

#include "TipoUsuario.h"
#include <iostream>
#include <string>
using namespace std;

class DTUsuarioViaje {
private:
    string nickname;
    TipoUsuario tipo;
public:
    DTUsuarioViaje();
    DTUsuarioViaje(string nickname, TipoUsuario tipo);
    
    string getNickname() const;
    TipoUsuario getTipo();
    bool operator<(const DTUsuarioViaje& dtuv) const;
};

ostream& operator<<(ostream& os, DTUsuarioViaje dtuv);

#endif
