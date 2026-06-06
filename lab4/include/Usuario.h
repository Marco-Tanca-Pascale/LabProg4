#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nickname;
    string nombre;
    string contrasena;
    string email;
    float calificacionPromedio;

public:
    Usuario(string nickname, string nombre, string contrasena, string email,float calificacionPromedio);
    virtual ~Usuario();

    //Getters
    string getNickname();
    string getNombre();

    //Metodos 

    
    //Asocia este usuario como autor de una calificacion (la relacion es Realiza ->)
    //Paso calificacion como puntero ?
    void asociarRealiza(Calificacion* calificacion);

    //Asocia este usuario como calificado (relacion Califica <-)
    void asociarCalifica(Calificacion* calificacion);


    //obtenerViajes() depende de si Usuario es pasajero o conductor.
    //Lo ponemos virtual porque las clases hijas en este caso pasajero y conductor
    //pueden implementar el metodo de forma diferente 
    //devuelve un set de viajes ?
    virtual void obtenerViajes();

    
};

#endif
