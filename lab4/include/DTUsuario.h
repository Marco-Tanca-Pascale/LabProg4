#ifndef DT_USUARIO_H
#define DT_USUARIO_H
#include <iostream>
#include <string>
using namespace std;

class DTUsuario {
private:
    string nickname;
    string nombre;
public:
    //constructores
    DTUsuario();
    DTUsuario(string nickname, string nombre);
    
    //getters
    string getNickname() const;
    string getNombre();

    //operador sobrecargado
    bool operator<(const DTUsuario& dtu) const;
};

//operador de flujo sobrecargado
ostream& operator<<(ostream& o, const DTUsuario dtu);

#endif
