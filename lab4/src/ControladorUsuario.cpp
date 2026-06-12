#include "../include/ControladorUsuario.h"
#include "../include/ControladorFechaActual.h"

ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario() {
    nick_memo.clear();
    cod_memo = 0;
}

ControladorUsuario* ControladorUsuario::getInstance() {
    // Si no hay una instancia inicializada, lo hace.
    if (instancia == nullptr) {
        instancia = new ControladorUsuario();
    }
    // Retorna la instancia guardada para mantener el patron singleton.
    return instancia;
}

const map<string, Usuario*>& ControladorUsuario::getUsuarios() const {
    return this->usuarios;
}

Usuario* ControladorUsuario::getUsuario(string nickname) {
    // Encuentra y retorna el usuario relacionado a nickname.
    auto it = this->usuarios.find(nickname);
    if (it == this->usuarios.end()) {
        return nullptr;
    }
    return it->second;
}

void ControladorUsuario::setUsuario(Usuario* u){
    // Agrega al usuario u a la lista de usuarios.
    this->usuarios[u->getNickname()] = u;
}

bool ControladorUsuario::altaConductor(string nickname, string nombre, string contrasena, string email, set<TipoLibreta> libretas){
    if (this->getUsuario(nickname) != nullptr) return false;
    // Crea un nuevo conductor casteado como Usuario para facilitar su storage.
    Usuario* c = new Conductor(nickname, nombre, contrasena, email, libretas);
    this->setUsuario(c);
    return true;
}

bool ControladorUsuario::altaPasajero(string nickname, string nombre, string contrasena, string email, string ci){
    if (this->getUsuario(nickname) != nullptr) return false;
    // Crea un nuevo pasajero casteado como Usuario para facilitar su storage.
    Usuario* p = new Pasajero(nickname, nombre, contrasena, email, ci);
    this->setUsuario(p);
    return true;
}

bool ControladorUsuario::calificarUsuario(string nicknameCalificado, int calificacion) {
    // Obtiene el usuario relacionado al nickname guardado en la memoria.
    Usuario* u = this->getUsuario(this->nick_memo);
    // Obtiene el usuario relacionado al nickname pasado por parámetro.
    Usuario* u_calificado = this->getUsuario(nicknameCalificado);

    Reserva* r = nullptr;
    if (dynamic_cast<Conductor*>(u) != nullptr){
        // Si el usuario es Conductor, busca la reserva por los viajes relacionados a sus vehiculos.
        Viaje* vi = dynamic_cast<Conductor*>(u)->getViaje(this->cod_memo);
        r = vi != nullptr ? vi->getReserva(nicknameCalificado) : nullptr;
    } else {
        // Si el usuario es Pasajero, busca la reserva directamenet.
        r = dynamic_cast<Pasajero*>(u)->getReserva(this->cod_memo);
    }
    if (r != nullptr && !r->existeCalificacion(this->nick_memo, nicknameCalificado)) {
        // Si la reserva fue encontrada y no tiene una calificacion de u a u_calificado, se crea la calificacion, se limpia la memoria y se retorna true.
        ControladorFechaActual* cfecha = ControladorFechaActual::getInstance();
        r->crearCalificacion(calificacion, cfecha->getFecha(), u, u_calificado);
        this->cod_memo = 0;
        this->nick_memo.clear();
        return true;
    } else {
        // De otra manera se limpia la memoria y se retorna false.
        this->cod_memo = 0;
        this->nick_memo.clear();
        return false;
    }
}

map<string, DTUsuario> ControladorUsuario::listarUsuarios(){
    const map<string, Usuario*>& l = this->getUsuarios();
    map<string, DTUsuario> res;
    for (auto it=l.begin(); it!=l.end(); ++it){
        string nick = it->first;
        string nom = it->second->getNombre();
        DTUsuario dtu(nick, nom);
        res[dtu.getNickname()] = dtu;
    }
    return res;
}

map<string, DTUsuarioViaje> ControladorUsuario::listarUsuariosViaje(int codigo){
    const map<string, Usuario*>& l = this->getUsuarios();
    map<string, DTUsuarioViaje> res;
    for (auto it=l.begin(); it!=l.end(); ++it){
        string nickname = it->first;
        Usuario* u = it->second;
        // Si el nickname es el guardado por memoria, lo saltea.
        if (nickname == this->nick_memo)
            continue;
        if (dynamic_cast<Pasajero*>(u) != nullptr && dynamic_cast<Pasajero*>(u)->reservoViaje(codigo)){
            // Si logra castear a pasajero, busca si una de sus reservas corresponde al viaje. Si es asi, lo agrega a la lista.
            DTUsuarioViaje dtuv(nickname, TipoUsuario::Pasajero);
            res[nickname] = dtuv;
        } else if (dynamic_cast<Conductor*>(u) != nullptr && dynamic_cast<Conductor*>(u)->esConductorDe(codigo)) {
            // Si no logra el casteo pero u es conductor del viaje, lo agrega a la lista.
            DTUsuarioViaje dtuv(nickname, TipoUsuario::Conductor);
            res[nickname] = dtuv;
        }
    }
    // Guarda en memoria el codigo y retorna la coleccion de dtuv.
    this->cod_memo = codigo;
    return res;
}

map<int, DTListarViaje> ControladorUsuario::listarViajes(string nickname){
    Usuario* u = this->getUsuario(nickname);
    map<int, DTListarViaje> res = u->obtenerViajes();
    // Guarda en memoria el nickname y retorna la coleccion de dtlv.
    this->nick_memo = nickname;
    return res;
}

int ControladorUsuario::registrarVehiculo(string nickname, string matricula, int capacidad, string marca, string modelo, TipoVehiculo tipo){
    const map<string, Usuario*>& l = this->getUsuarios();
    Conductor* c;
    for (auto it=l.begin(); it!=l.end(); ++it){
        Conductor* r = dynamic_cast<Conductor*>(it->second);
        if (r != nullptr && r->tieneVehiculo(matricula))
            return -1;
        if (it->first == nickname)
            c = r;
    }
    if (!c->tieneLibreta(tipo))
        return -2;
    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    c->agregarVehiculo(v);
    return 0;
}


