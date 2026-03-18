#include <iostream>
#include <list>
#include <map>
#include "include/DTFecha.h"
#include "include/Alojamiento.h"
#include "include/TipoRegimen.h"
#include "include/TourGuiado.h"
#include "include/EventoCultural.h"
#include "include/DTExpe.h"
#include "include/Experiencia.h"
#include "include/Turista.h"


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
void parte_a(){
	//Crear los siguientes objetos de la clase Alojamiento

	DTFecha fecha_1(18,05,2020);
	Alojamiento alojamiento_1 = Alojamiento("ALX5489", "Hotel moderno", 30 , fecha_1, "Hotel Lindorf", Allinclusive, 5);

	DTFecha fecha_2(10,02,2025);
	Alojamiento alojamiento_2 = Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, fecha_2, "Hotel SeaView", MediaPension, 15);
}

//Avril
void parte_b(){
	//Crear los siguientes objetos de la clase TourGuiado
	DTFecha fecha_1(29,08,2024);
	TourGuiado tour_1 = TourGuiado("TGO4657", "Plazas de Montevideo", 10 , fecha_1 , {} , "Paseos SA", {"Plaza Independencia","Plaza Matriz"} );

	DTFecha fecha_2(29,08,2024);
	TourGuiado tour_2 = TourGuiado("TGR3257", "Puntos emblematicos", 5 ,fecha_2,{}, "Recorre", {"Puerta de la Ciudadela" , "Mausoleo", "Cabildo", "Palacio Salvo"} )
}

//Avril
void parte_c(){
	//Crear los siguientes objetos de la clase EventoCultural 
	DTFecha fecha(29,10,2025);
	EventoCultural evento_1 = EventoCultural("ECP1346", "Danza en el Solis", 10, fecha, {}, "Teatro Solis", true);
}

//Nahuel
void parte_d(){
	// recore la coleccion
	for (Experiencia *exp : experiencias)
	{
		std::cout << exp->getDT() << "\n";
	}
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
//obtengo a los tursitas de la coleccion
	Turista* vanesa = coleccion_getTurista("4.951.278-9");
	Turista* karen = coleccion_getTurista("1.535.442-0");

//obtengo a las experiencias
	Experiencia* hotelV1 = coleccion_getExperiencia("ALX5489");
	Experiencia* hotelV2 = coleccion_getExperiencia("ALJ4789");
	Experiencia* TourV1 = coleccion_getExperiencia("TGR3257");
	Experiencia* EventoV1 = coleccion_getExperiencia("ECP1346");

	Experiencia* TourK1 = coleccion_getExperiencia("TGO4657");
	Experiencia* TourK2 = coleccion_getExperiencia("TGR3257");

//Relaciono turista y experiencia
//Vinculo vanesa
	vanesa->agregarExperiencia(hotelV1);
	hotelV1->agregarTurista(vanesa);
	vanesa->agregarExperiencia(hotelV2);
	hotelV2->agregarTurista(vanesa);
	vanesa->agregarExperiencia(TourV1);
	TourV1->agregarTurista(vanesa);
	vanesa->agregarExperiencia(EventoV1);
	EventoV1->agregarTurista(vanesa);
//Vinculo karen
	karen->agregarExperiencia(TourK1);
	TourK1->agregarTurista(karen);
	karen->agregarExperiencia(TourK2);
	TourK2->agregarTurista(karen);
}

//Luisina
void parte_h(){
	//obtengo al objeto  vanesa 
	Turista *vanesa = coleccion_getTurista("4.951.278-9");

	DTFecha fecha(10,12,2023);
	std::list<std::string> resu = vanesa->listaExperiencias(fecha,0,1000);

	// imprimo el resultado en consola (un string por linea)
	//por cada string s de resu los imprimo 
	for(std::string s: resu){
		std::cout << s << std::endl;
	}

}

//Marco
void parte_i(){
	

}

//Luisina
void parte_j(){
}

//Joaquin
void parte_k(){
	//recore la coleccion
	for (Experiencia* exp : experiencias)
	{
		std::cout << exp->getDT() << "\n";
	}
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