#ifndef MENU_H
#define MENU_H

#include <set>
using namespace std;
#include "TipoLibreta.h"

class Menu {
private:
    set<TipoLibreta> tomarLibretas();
    void altaUsuario();
    void altaViaje();
    void generarReserva();
    void calificarUsuario();
    void eliminarViaje();
    void administrarFechaActual();
    void cargarDatos();

public:
    void mostrarMenu();
};

#endif
