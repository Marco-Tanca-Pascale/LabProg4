#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include <map>
#include "TipoUsuario.h"
#include "IControladorUsuario.h"
#include "Usuario.h"

class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instancia;
    map<string, Usuario*> usuarios;
    ControladorUsuario();
    string nick_memo;
    int cod_memo;
public:
    static ControladorUsuario* getInstance();
    virtual bool altaPasajero(string nickname, string nombre, string contrasena, string email, string ci) override;
    virtual bool altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas) override;
    virtual bool calificarUsuario(string nicknameCalificado, int calificacion) override;
    virtual set<DTUsuario> listarUsuarios() override;
    virtual set<DTUsuarioViaje> listarUsuariosViaje(int codigo) override;
    virtual set<DTListarViaje> listarViajes(string nickname) override;
    virtual int registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo) override;
    const map<string, Usuario*>& getUsuarios() const;
    Usuario* getUsuario(string nickname);
    void setUsuario(Usuario* u);
};

#endif