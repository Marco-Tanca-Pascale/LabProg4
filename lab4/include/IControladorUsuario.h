#ifndef ICONTROLADOR_USUARIO_H
#define ICONTROLADOR_USUARIO_H

#include <string>
#include <set>
#include "TipoVehiculo.h"
#include "TipoLibreta.h"
#include "DTUsuario.h"
#include "DTUsuarioViaje.h"
#include "DTListarViaje.h"

using namespace std;

class IControladorUsuario {
public:
    virtual ~IControladorUsuario() {}
    virtual bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci) = 0;
    virtual bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas) = 0;
    virtual bool calificarUsuario(string nicknameCalificado, int calificacion) = 0;
    virtual set<DTUsuario> listarUsuarios() = 0;
    virtual set<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;
    virtual set<DTListarViaje> listarViajes(string nickname) = 0;
    virtual int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) = 0;
};

#endif
