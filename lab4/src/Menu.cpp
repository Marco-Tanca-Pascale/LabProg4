#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/IControladorUsuario.h"
#include "../include/IControladorViaje.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

Fabrica* fabrica = Fabrica::getInstance();

void Menu::altaUsuario() {
    IControladorUsuario* controller = fabrica->getIUsuario();
    int tipoUsuario;
    cout << "1. Alta Pasajero\n";
    cout << "2. Alta Conductor\n";
    cout << "Seleccione: ";
    cin >> tipoUsuario;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        cout << "Opcion invalida.\n";
        return;
    }

    string nickname, nombre, contrasena, email;
    cout << "Ingrese nickname: "; getline(cin, nickname);
    cout << "Ingrese nombre: "; getline(cin, nombre);
    cout << "Ingrese contrasena: "; getline(cin, contrasena);
    cout << "Ingrese email: "; getline(cin, email);


    bool usuarioOk = false;

    if (tipoUsuario == 1) {
        string ci;
        cout << "Ingrese CI: "; getline(cin, ci);
        usuarioOk = controller->altaPasajero(nickname, nombre, contrasena, email, ci);
    } else if (tipoUsuario == 2) {
        set<TipoLibreta> libretas = tomarLibretas();
        usuarioOk = controller->altaConductor(nickname, nombre, contrasena, email, libretas);
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            string matricula, marca, modelo;
            int capacidad, tipo;
            cout << "\n=== Registrar Vehiculo ===\n";
            cout << "Ingrese matricula: "; getline(cin, matricula);
            cout << "Ingrese capacidad: "; cin >> capacidad;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese marca: "; getline(cin, marca);
            cout << "Ingrese modelo: "; getline(cin, modelo);
            cout << "Ingrese tipo (0: Auto, 1: Moto): "; cin >> tipo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;
            resultadoRegistrarVehiculo = controller->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo ? TipoVehiculo::Moto : TipoVehiculo::Auto);
            if (resultadoRegistrarVehiculo == -1) {
                cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                cout << "Vehiculo registrado exitosamente.\n";
            }
            cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            cin >> agregarVehiculo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

std::set<TipoLibreta> Menu::tomarLibretas()
{
    bool tieneMotoProfesional = false;
    bool tieneMotoAmateur = false;
    bool tieneAutoProfesional = false;
    bool tieneAutoAmateur = false;

    int cantLibretas = 0;
    int agregarLibreta = 1;

    while (agregarLibreta == 1 && cantLibretas < 4) {
        int tipoLibreta;
        cout << "\n=== Registrar Libreta ===\n";
        cout << "0. Moto (Profesional)\n";
        cout << "1. Moto (Amateur)\n";
        cout << "2. Auto (Profesional)\n";
        cout << "3. Auto (Amateur)\n";
        cout << "Seleccione el tipo de libreta: ";
        cin >> tipoLibreta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool yaExiste = false;
        if (tipoLibreta == 0) {
            if (tieneMotoProfesional) {
                yaExiste = true;
            } else {
                tieneMotoProfesional = true;
                cantLibretas++;
            }
        } else if (tipoLibreta == 1) {
            if (tieneMotoAmateur) {
                yaExiste = true;
            } else {
                tieneMotoAmateur = true;
                cantLibretas++;
            }
        } else if (tipoLibreta == 2) {
            if (tieneAutoProfesional) {
                yaExiste = true;
            } else {
                tieneAutoProfesional = true;
                cantLibretas++;
            }
        } else if (tipoLibreta == 3) {
            if (tieneAutoAmateur) {
                yaExiste = true;
            } else {
                tieneAutoAmateur = true;
                cantLibretas++;
            }
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        if (yaExiste) {
            cout << "Esa libreta ya fue ingresada.\n";
        } else {
            cout << "Libreta agregada.\n";
        }

        if (cantLibretas < 4) {
            cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
            cin >> agregarLibreta;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Se ha alcanzado el limite maximo de libretas.\n";
        }
    }

    if (cantLibretas == 0) {
        cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
        return std::set<TipoLibreta>();
    }

    set<TipoLibreta> r;
    if (tieneMotoProfesional) {
        r.insert(TipoLibreta::MotoProfesional);
    }
    if (tieneMotoAmateur) {
        r.insert(TipoLibreta::MotoAmateur);
    }
    if (tieneAutoProfesional) {
        r.insert(TipoLibreta::AutoProfesional);
    }
    if (tieneAutoAmateur) {
        r.insert(TipoLibreta::AutoAmateur);
    }
    return r;
}

void Menu::altaViaje() {
    // Tiene que solucionarse lo de IViaje en fabrica
    IControladorViaje* controller = fabrica->getIViaje();
    string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;

    cout << "Ingrese nickname del conductor: "; getline(cin, nickname);
    map<string, DTVehiculosConductor> lv = controller->listarVehiculosConductor(nickname);
    for (map<string, DTVehiculosConductor>::iterator it=lv.begin(); it!=lv.end(); ++it){
        cout << ' ' << it->second;
    }

    cout << "Ingrese matricula del vehiculo a utilizar: "; getline(cin, matricula);
    bool matriculaValida = !(lv.find(nickname) == lv.end());
    if (!matriculaValida) {
        cout << "Matricula invalida.\n";
        return;
    }

    cout << "Ingrese fecha del viaje (dia mes anio): "; cin >> dia >> mes >> anio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese origen: "; getline(cin, origen);
    cout << "Ingrese destino: "; getline(cin, destino);
    cout << "Ingrese cantidad de asientos: "; cin >> asientos;
    cout << "Ingrese precio por asiento: "; cin >> precio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool viajeOk = controller->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) {
        cout << "Viaje registrado exitosamente.\n";
    } else {
        cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    IControladorViaje* controller = fabrica->getIViaje();
    set<string> lp = controller->listarPasajeros();
    for (set<string>::iterator it=lp.begin(); it!=lp.end(); ++it){
        cout << "> " << *it << '\n';
    }
    string nickname;
    cout << "Ingrese nickname del pasajero: "; getline(cin, nickname);
    bool nicknameValido = lp.find(nickname) != lp.end();
    if (!nicknameValido) {
        cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    string origen, destino;
    cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; cin >> dia >> mes >> anio;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese origen: "; getline(cin, origen);
    cout << "Ingrese destino: "; getline(cin, destino);
    cout << "Ingrese cantidad de asientos a reservar: "; cin >> asientos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    map<int, DTConsultaViaje> lcv = controller->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);
    for (map<int, DTConsultaViaje>::iterator it=lcv.begin(); it!=lcv.end(); ++it){
        cout << "> " << it->second << '\n';
    }

    bool hayViajes = lcv.empty();
    if (!hayViajes) {
        cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    cout << "Ingrese codigo del viaje a reservar: "; cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool codigoValido = !(lp.find(nickname) == lp.end());
    if (!codigoValido) {
        cout << "Codigo invalido.\n";
        return;
    }
    bool reservaOk = controller->generarReserva(nickname, codigo, asientos);
    if (reservaOk) {
        cout << "Reserva realizada exitosamente.\n";
    } else {
        cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    IControladorUsuario* controller = fabrica->getIUsuario();
    map<string, DTUsuario> lu = controller->listarUsuarios();
    for (map<string, DTUsuario>::iterator it=lu.begin(); it!=lu.end(); ++it){
        cout << "> " << it->second << '\n';
    }
    string nickname;
    cout << "Ingrese su nickname: "; getline(cin, nickname);
    bool nicknameValido = lu.find(nickname) != lu.end();
    if (!nicknameValido) {
        cout << "Nickname invalido.\n";
        return;
    }

    map<int, DTListarViaje> lv = controller->listarViajes(nickname);
    for (map<int, DTListarViaje>::iterator it=lv.begin(); it!=lv.end(); ++it){
        cout << "> " << it->second << '\n';
    }
    int codigo;
    cout << "Ingrese codigo del viaje: "; cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool codigoValido = lv.find(codigo) != lv.end();
    if (!codigoValido) {
        cout << "Codigo invalido.\n";
        return;
    }

    map<string, DTUsuarioViaje> luv = controller->listarUsuariosViaje(codigo);
    for (map<string, DTUsuarioViaje>::iterator it=luv.begin(); it!=luv.end(); ++it){
        cout << "> " << it->second << '\n';
    }
    string nicknameCalificado;
    int calificacion;
    cout << "Ingrese nickname del usuario a calificar: "; getline(cin, nicknameCalificado);
    cout << "Ingrese calificacion (1-5): "; cin >> calificacion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool nicknameCalificadoValido = luv.find(nickname) != luv.end();
    if (!nicknameCalificadoValido) {
        cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = controller->calificarUsuario(nicknameCalificado, calificacion);
    if (calificacionOk) {
        cout << "Calificacion exitosa.\n";
    } else {
        cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    IControladorViaje* controller = fabrica->getIViaje();
    //obtenemos la coleccion de viajes
    std::set<DTListarViaje> viajes = controller->listarViajes();
    //verificamos que la coleccion no sea vacia
    if(viajes.empty()){
        cout << "No hay viajes registrados en el sistema.\n";
        return;
    }
    //recorremos la coleccion
    for(DTListarViaje dt : viajes){
        DTFecha fecha = dt.getFecha();

        cout << "> Codigo: " <<dt.getCodigo() << "Fecha: " << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() <<  "Origen: " << dt.getOrigen() << "Destino: " << dt.getDestino() <<  "Conductor: " << dt.getConductor()<< "\n";
    }


    int codigo;
    cout << "Ingrese codigo del viaje a eliminar: "; cin >> codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool codigoValido = false;
    //Validamos el codigo en listado
    for(DTListarViaje dt : viajes){
        if(dt.getCodigo() == codigo){
            codigoValido = true;
            break;
        }
    }

    if (!codigoValido) {
        cout << "Codigo invalido.\n";
        return;
    }

    //conseguimos el detalle del viaje mediante el código
    DTDetalleViaje viajeDetalle = controller->detalleViaje(codigo);
    DTFecha fechaViaje = viajeDetalle.getFecha();
    //TODO: Mostrar detalle del viaje siguiendo el formato
    //>> Viaje <<
    //--- Matrícula: aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Capacidad: bbb, Precio por asiento: qqq //la capacidad del viaje son los asientos publicados?
    //>> Vehiculo <<
    //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
    //>> Reservas <<
    //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa

    cout<< "\n>> Viaje <<\n";
    cout<< "--- Matrícula: "<< viajeDetalle.getVehiculo().getMatricula() <<"Fecha: "<< fechaViaje.getDia() << "/" << fechaViaje.getMes() << "/" << fechaViaje.getAnio() <<"Origen: "<< viajeDetalle.getOrigen() <<"Destino: "<< viajeDetalle.getDestino() << "Capacidad: "<< viajeDetalle.getAsientosPublicados() << "Precio por asiento: "<< viajeDetalle.getPrecio()<< "\n";

    cout<< "\n>> Vehiculo <<\n";
    cout<< "--- Matrícula: "<< viajeDetalle.getVehiculo().getMatricula() <<"Capacidad: "<< viajeDetalle.getVehiculo().getCapacidad() << "Marca: " << viajeDetalle.getVehiculo().getMarca() << "Modelo: " << viajeDetalle.getVehiculo().getModelo() << "Tipo: " << viajeDetalle.getVehiculo().getTipo() <<"\n"; //hay que sobreescribir el operador << paraDTDetalleVehiculo
    
    cout<< "\n>> Reservas <<\n";
    //recorro cada reserva para mostrar sus datos
    std::set<DTDetalleReserva> reservasViaje = viajeDetalle.getReservas();
    //nos aseguramos de que no esté vacío el set
    if(reservasViaje.empty()){
        cout << "---No hay reservas para este viaje. \n";
    }else{
        for(DTDetalleReserva res : reservasViaje){
            DTFecha fechaRes = res.getFecha();
            cout<< "--- AsientosReservados: " << res.getAsientosReservados() << "Fecha: " << fechaRes.getDia() << "/" << fechaRes.getMes() << "/" << fechaRes.getAnio() << "Pasajero: " << res.getPasajero() << "\n";
        }
    }

    int confirmar;
    cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; cin >> confirmar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (confirmar == 1) {
        controller->eliminarViaje();
        cout << "Viaje eliminado exitosamente.\n";
    } else {
        controller->cancelarEliminarViaje();
        cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    cout << "1. Ver fecha actual\n";
    cout << "2. Modificar fecha actual\n";
    cout << "Seleccione: ";
    cin >> opFecha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        cout << "Ingrese dia: "; cin >> dia;
        cout << "Ingrese mes: "; cin >> mes;
        cout << "Ingrese anio: "; cin >> anio;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Alta de Usuario\n";
        cout << "2. Alta de Viaje\n";
        cout << "3. Generar Reserva\n";
        cout << "4. Calificar Usuario\n";
        cout << "5. Eliminar Viaje\n";
        cout << "6. Administrar Fecha Actual\n";
        cout << "7. Cargar Datos\n";
        cout << "8. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }
}
