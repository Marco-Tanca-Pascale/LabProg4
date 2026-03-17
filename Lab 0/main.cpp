#include <iostream>
#include <list>
#include <map>
#include "include/*"

std::list<Experiencia*> experiencias;
std::map<std::string, Experiencia*> map_experiencias;

std::list<Turista*> turistas;
std::map<std::string, Turista*> map_turistas;

void coleccion_guardarExperiencia(Experiencia* exp){
	experiencias.push_back(exp);
	std::pair<std::string, Experiencia*> entry(exp->getCodigoReserva(), exp);
    map_experiencias.insert(entry);
}
void coleccion_eliminarExperiencia(Experiencia* exp){
	experiencias.remove(exp);
	map_experiencias.erase(exp->getCodigoReserva());
}

void coleccion_guardarTurista(Turista* tur){
	turistas.push_back(tur);
	std::pair<std::string, Turista*> entry(tur->getCi(), tur);
    map_turistas.insert(entry);
}

Turista* coleccion_getTurista(std::string ci){
	return map_turistas[ci];
}

Experiencia* coleccion_getExperiencia(std::string codigoReserva){
	return map_experiencias[codigoReserva];
}

//Avril
Alojamiento parte_a(){
}

//Avril
Alojamiento parte_b(){
}

//Avril
TourGuiado parte_c(){
}

//Nahuel
void parte_d(){
}

//Marco
void parte_e(){
	//Creo los objetos turistaVanesa y turistaKaren.
	Turista* turistaVanesa = new Turista("4.951.278-9", "Vanesa Castro", "vcastro.uy@servidor.net");
	Turista* turistaKaren = new Turista("1.535.442-0", "Karen Santos", "karen.s89@internet.uy");
	
	//Guardo cada objeto en la coleccion.
	coleccion_guardarTurista(turistaVanesa);
	coleccion_guardarTurista(turistaKaren);
}

//Nahuel
void parte_f(){
}

//Joaquin
void parte_g(){
}

//Luisina
void parte_h(){
}

//Marco
void parte_i(){
}

//Luisina
void parte_j(){
}

//Joaquin
void parte_k(){
}

//Marco
void cleanUp(){
}

int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}