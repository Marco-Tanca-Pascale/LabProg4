#Laboratorio 0
OBJ = main.o Alojamiento.o DTExpe.o DTFecha.o EventoCultural.o Experiencia.o TourGuiado.o Turista.o # para no tener que escribir todas las dependecias todo el tiempo
all: principal #para que make construya principal porque al hacer make se va a buscar all y all depende de principal

principal: $(OBJ) #como se va a llamar al programa a la hora de compilar y todos los archivos que usa
		g++ $(OBJ) -o principal 

main.o: Lab0/main.cpp  #para que compile cuando se cambia algo en el .cpp o el .h (justo en este caso main no tiene .h)
		g++ -Wall -g -c Lab0/main.cpp -o main.o

Alojamiento.o: Lab0/src/Alojamiento.cpp include/Alojamiento.h
		g++ -Wall -g -c Lab0/src/Alojamiento.cpp -o Alojamiento.o 

DTExpe.o: Lab0/src/DTExpe.cpp include/DTExpe.h
		g++ -Wall -g -c Lab0/src/DTExpe.cpp -o DTExpe.o

DTFecha.o: Lab0/src/DTFecha.cpp include/DTFecha.h
		g++ -Wall -g -c Lab0/src/DTFecha.cpp -o DTFecha.o

EventoCultural.o: Lab0/src/EventoCultural.cpp include/EventoCultural.h
		g++ -Wall -g -c Lab0/src/EventoCultural.cpp -o EventoCultural.o

Experiencia.o: Lab0/src/Experiencia.cpp include/Experiencia.h
		g++ -Wall -g -c Lab0/src/Experiencia.cpp -o Experiencia.o

TourGuiado.o: Lab0/src/TourGuiado.cpp include/TourGuiado.h
		g++ -Wall -g -c Lab0/src/TourGuiado.cpp -o TourGuiado.o
	
Turista.o: Lab0/src/Turista.cpp include/Turista.h
		g++ -Wall -g -c Lab0/src/Turista.cpp -o Turista.o

#para borrar todos los .o y el ejecutable, o sea limpia el proyecto (para hacer make clean)
clean:
		rm -f *.o principal 

# info: g++(lee el .cpp lo traduce y crea el ejecutable), -Wall -g(todo junto hace que te muestre los errores/cosas raras en caso de haber) ,-c (le dice al g++ que solo compile, pero que no cree el ejecutable)