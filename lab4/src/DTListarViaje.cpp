#include "../include/DTListarViaje.h"
DTListarViaje::DTListarViaje()
{
    this->codigo = 0;
    this->fecha = DTFecha();
    this->origen = "";
    this->destino = "";
    this->conductor = "";
}
DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->conductor = conductor;
}

int DTListarViaje::getCodigo() const { return codigo; }
DTFecha DTListarViaje::getFecha() { return fecha; }
std::string DTListarViaje::getOrigen() { return origen; }
std::string DTListarViaje::getDestino() { return destino; }
std::string DTListarViaje::getConductor() { return conductor; }

bool DTListarViaje::operator<(const DTListarViaje& dtlv) const {
    return this->getCodigo() < dtlv.getCodigo();
}

ostream& operator<<(ostream& os, DTListarViaje dtlv) {
    os << "> Codigo: " << dtlv.getCodigo() << ", Fecha: " << dtlv.getFecha() << ", Origen: " << dtlv.getOrigen() << ", Destino: " << dtlv.getDestino() << ", Conductor: " << dtlv.getConductor();
    return os;
}
