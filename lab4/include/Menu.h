#ifndef MENU_H
#define MENU_H

#include <set>
#include "TipoLibreta.h"

class Menu {
private:
    //para que compile, no se si se podia modificar el menu. joaco XD
    std::set<TipoLibreta> tomarLibretas();
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
