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
    //constructores
    DTUsuarioViaje();
    DTUsuarioViaje(string nickname, TipoUsuario tipo);
    
    //getters
    string getNickname() const;
    TipoUsuario getTipo();

    //operador sobrecargado
    bool operator<(const DTUsuarioViaje& dtuv) const;
};

//operador de flujo sobrecargado
ostream& operator<<(ostream& os, DTUsuarioViaje dtuv);

#endif
