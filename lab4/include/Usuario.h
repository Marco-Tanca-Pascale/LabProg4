#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DTListarViaje.h"
#include "Calificacion.h"
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
    set<Calificacion*> calificacionesRealizadas;
    set<Calificacion*> calificacionesRecibidas;

public:
    Usuario(string nickname, string nombre, string contrasena, string email);
    virtual ~Usuario();

    //Metodos

    //getters
    string getNickname();
    string getNombre();
    void setCalificacionPromedio(float nueva);
    float getCalificacionPromedio();

    //asocia este usuario como autor de una calificacion
    void asociarRealiza(Calificacion *c);

    //asocia este usuario como calificado
    void asociarCalifica(Calificacion* c);


    //obtenerViajes() depende de si Usuario es pasajero o conductor, pero en ambos casos devuelve un map con los viajes relacionados a dicho usuario
    virtual map<int, DTListarViaje> obtenerViajes();

    //reemplaza el puntaje de la calificacion por otro
    void ajustarCalificacion();

    //remueve la calificacion
    void removerCalificacion(Calificacion* c);

};

#endif
