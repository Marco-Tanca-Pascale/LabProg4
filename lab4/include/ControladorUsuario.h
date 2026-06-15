#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include "IControladorUsuario.h"
#include <set>
#include <map>
#include "TipoUsuario.h"
#include "Usuario.h"
#include "Viaje.h"
#include "Vehiculo.h"
#include "Conductor.h"
#include "Pasajero.h"


class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instancia;
    map<string, Usuario*> usuarios;
    //constructor privado para mantener el patrón singleton
    ControladorUsuario();
    string nick_memo;
    int cod_memo;
public:
    //devuelve la unica instancia del controlador para mantener el patrón singleton
    static ControladorUsuario* getInstance();

    //Metodos

    //alta de usuarios
    virtual bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci) override;
    virtual bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas) override;
    
    //genera una calificacion hacia el usuario
    virtual bool calificarUsuario(string nicknameCalificado, int calificacion) override;

    //listar
    virtual map<string, DTUsuario> listarUsuarios() override;
    virtual map<string, DTUsuarioViaje> listarUsuariosViaje(int codigo) override;
    virtual map<int, DTListarViaje> listarViajes(string nickname) override;

    //registra un vehiculo a nombre de cierto conductor
    virtual int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) override;
    
    //getters
    const map<string, Usuario*>& getUsuarios() const;
    Usuario* getUsuario(string nickname);
    void setUsuario(Usuario* u);
};

#endif