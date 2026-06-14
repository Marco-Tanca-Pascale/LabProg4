#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DTListarViaje.h"
#include "Calificacion.h"
#include <vector>
#include <set>
#include <map>
using namespace std;

//forward declaration
class Calificacion;
class Usuario {
protected:
    string nickname;
    string nombre;
    string contrasena;
    string email;
    float calificacionPromedio;
    vector<Calificacion*> calificacionesRealizadas;
    vector<Calificacion*> calificacionesRecibidas;

public:
    Usuario(string nickname, string nombre, string contrasena, string email);
    virtual ~Usuario();

    //Getters
    string getNickname();
    string getNombre();
    void setCalificacionPromedio(float nueva);
    float getCalificacionPromedio();

    // Metodos

    // Asocia este usuario como autor de una calificacion (la relacion es Realiza ->)

    // Representa el paso 1.7.2.1 del diagrama de com de calificarUsuario.
    // Vincula una calificación en la que este usuario actuó como el "calificador" (el que la realizó).
    void asociarRealiza(Calificacion *c);

    //Asocia este usuario como calificado (relacion Califica <-)
    // Representa el paso 1.7.2.2 del diagrama de com de calificarUsuario.
    // Vincula una calificación en la que este usuario fue el "calificado" (el que la recibió).
    void asociarCalifica(Calificacion* c);


    //obtenerViajes() depende de si Usuario es pasajero o conductor.
    //Lo ponemos virtual porque las clases hijas en este caso pasajero y conductor
    //pueden implementar el metodo de forma diferente 
    //devuelve un set de viajes ?
    virtual map<int, DTListarViaje> obtenerViajes();

    void ajustarCalificacion();

    void removerCalificacion(Calificacion* c);

};

#endif
