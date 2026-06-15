#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/IControladorUsuario.h"
#include "../include/IControladorViaje.h"
#include <iostream>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

// Devuelve una instancia de CargaDatos
CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

// Este metodo carga todos los datos al programa.
void CargaDatos::cargarDatos() {
    if (datosCargados) {
        cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    cout << "Cargando datos harcodeados del sistema...\n";
    IControladorUsuario* ICUsuario = Fabrica::getInstance()->getIUsuario();
    IControladorViaje* ICViaje = Fabrica::getInstance()->getIViaje();
    //CARGA DE LOS PASAJEROS
    ICUsuario->altaPasajero("santi_90","Santiago Acosta","sacosta90","santiago.acosta@gmail.com", "1.492.304-2");
    ICUsuario->altaPasajero("mari_b","Maria Noel Barreto","maribarreto6","mari.barreto@outlook.com", "4.103.859-1");
    ICUsuario->altaPasajero("nacho_f","Ignacio Figueroa","ifigueroa26","ignacio.figueroa@fing.edu.uy","3.847.112-5");
    ICUsuario->altaPasajero("valen_uy","Valentina Mendez","vmendezQ2","valen.mendez@fing.edu.uy","2.956.403-0");
    ICUsuario->altaPasajero("joaco_r","Joaquin Rivero","jrivero99x","joaquin_rivero@hotmail.com","5.021.784-3");

    //CARGA DE LOS CONDUCTORES Y SUS RESPECTIVOS VEHICULOS
    //conductor 1
    set<TipoLibreta> libretasC1;
    libretasC1.insert(TipoLibreta::AutoAmateur);
    ICUsuario->altaConductor("matil92","Matias Lopez","m4t14s92","matias.lopez.92@gmail.com",libretasC1);
    ICUsuario->registrarVehiculo("matil92","ABJ4586",4,"Chevrolet","Onix",TipoVehiculo::Auto);
    ICUsuario->registrarVehiculo("matil92","ACM4455",6,"Toyota","Rush",TipoVehiculo::Auto);
    //conductor 2
    set<TipoLibreta> libretasC2;
    libretasC2.insert(TipoLibreta::AutoProfesional);
    ICUsuario->altaConductor("ana_silva","Ana Silva","asilva2026","anasilva.m@outlook.com",libretasC2);
    ICUsuario->registrarVehiculo("ana_silva","BAS7895",4,"Fiat","Argo",TipoVehiculo::Auto);
    ICUsuario->registrarVehiculo("ana_silva","BCS4105",9,"Hyundai","H1",TipoVehiculo::Auto);
    //conductor 3
    set<TipoLibreta> libretasC3;
    libretasC3.insert(TipoLibreta::MotoAmateur);
    ICUsuario->altaConductor("greg_m","Diego Rodriguez","drodriguez88","diegorodriguez@fing.edu.uy",libretasC3);
    ICUsuario->registrarVehiculo("greg_m","LDA4875",1,"Honda","CB Twist", TipoVehiculo::Moto);
    //conductor 4
    set<TipoLibreta> libretasC4;
    libretasC4.insert(TipoLibreta::MotoProfesional);
    ICUsuario->altaConductor("lau_vaz","Laura Vazquez","lvazquezQ7","laura.vazquez@fing.edu.uy",libretasC4);
    ICUsuario->registrarVehiculo("lau_vaz","PDB1205",1,"Yumbo","Max 110",TipoVehiculo::Moto);
    //conductor 5
    set<TipoLibreta> libretasC5;
    libretasC5.insert(TipoLibreta::AutoProfesional);
    libretasC5.insert(TipoLibreta::MotoAmateur);
    ICUsuario->altaConductor("carlos_r","Carlos Rossi","crossi99x","carlos.rossi.uy@gmail.com",libretasC5);
    ICUsuario->registrarVehiculo("carlos_r","SBJ4874",4,"Volkswagen","Gol", TipoVehiculo::Auto);
    ICUsuario->registrarVehiculo("carlos_r","SCF2469",1,"Yamaha","FZ S", TipoVehiculo::Moto);
    
    //CARGA DE LOS VIAJES
    ICViaje->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200.0f);
    ICViaje->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250.0f);
    ICViaje->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200.0f);
    ICViaje->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200.0f);
    ICViaje->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300.0f);
    ICViaje->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350.0f);
    ICViaje->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260.0f);
    ICViaje->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150.0f);
    ICViaje->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140.0f);
    ICViaje->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180.0f);    
    ICViaje->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100.0f);
    ICViaje->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600.0f);
    ICViaje->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250.0f);

    //CARGA DE LAS RESERVAS
    ICViaje->generarReserva("santi_90",9,2);
    ICViaje->generarReserva("mari_b",9,1);
    ICViaje->generarReserva("nacho_f",10,5);
    ICViaje->generarReserva("valen_uy",10,3);
    ICViaje->generarReserva("joaco_r",10,1);
    ICViaje->generarReserva("mari_b",12,1);
    ICViaje->generarReserva("nacho_f",12,1);
    ICViaje->generarReserva("mari_b",1,2);
    ICViaje->generarReserva("nacho_f",9,1);

    //CARGA DE LAS CALIFICACIONES
    ICUsuario->calificarUsuario("matil92",4);
    ICUsuario->calificarUsuario("matil92",4);
    ICUsuario->calificarUsuario("mari_b",3);
    ICUsuario->calificarUsuario("valen_uy",5);
    ICUsuario->calificarUsuario("joaco_r",5);
    ICUsuario->calificarUsuario("carlos_r",5);
    ICUsuario->calificarUsuario("nacho_f",5);
    
    datosCargados = true;
    cout << "Datos cargados exitosamente.\n";
}
