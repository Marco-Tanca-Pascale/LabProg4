#ifndef DT_VEHICULOS_CONDUCTOR_H
#define DT_VEHICULOS_CONDUCTOR_H

#include <string>
#include <ostream>
using namespace std;

class DTVehiculosConductor {
private:
	string matricula;
	string modelo;
	int capacidad;
public:
	//constructores
  	DTVehiculosConductor(string matricula, string marca, int capacidad);
	
	//getters
  	string getMatricula() const;
  	string getModelo();
  	int getCapacidad();
	
	//operador de sobrecargado
    bool operator<(const DTVehiculosConductor& dtvc) const;
};

ostream& operator<<(ostream& o, const DTVehiculosConductor dtvc);

#endif
