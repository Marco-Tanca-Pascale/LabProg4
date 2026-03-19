#Laboratorio 0
CC = g++
CFLAGS = -Wall -g -std=c++98
OBJDIR = obj

OBJ = $(OBJDIR)/main.o $(OBJDIR)/Alojamiento.o $(OBJDIR)/DTExpe.o $(OBJDIR)/DTFecha.o $(OBJDIR)/EventoCultural.o $(OBJDIR)/Experiencia.o $(OBJDIR)/TourGuiado.o $(OBJDIR)/Turista.o # para no tener que escribir todas las dependecias todo el tiempo

all: principal #para que make construya principal porque al hacer make se va a buscar all y all depende de principal

principal: $(OBJ) #como se va a llamar al programa a la hora de compilar y todos los archivos que usa
	$(CC) $(CFLAGS) $(OBJ) -o principal 

#para que compile cuando se cambia algo en el .cpp o el .h (justo en este caso main no tiene .h)
$(OBJDIR)/main.o: main.cpp include/Alojamiento.h include/EventoCultural.h include/TourGuiado.h include/Turista.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Alojamiento.o: src/Alojamiento.cpp include/Alojamiento.h include/Experiencia.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Alojamiento.cpp -o $(OBJDIR)/Alojamiento.o

$(OBJDIR)/DTExpe.o: src/DTExpe.cpp include/DTExpe.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTExpe.cpp -o $(OBJDIR)/DTExpe.o

$(OBJDIR)/DTFecha.o: src/DTFecha.cpp include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTFecha.cpp -o $(OBJDIR)/DTFecha.o

$(OBJDIR)/EventoCultural.o: src/EventoCultural.cpp include/EventoCultural.h include/Experiencia.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/EventoCultural.cpp -o $(OBJDIR)/EventoCultural.o

$(OBJDIR)/Experiencia.o: src/Experiencia.cpp include/Experiencia.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Experiencia.cpp -o $(OBJDIR)/Experiencia.o

$(OBJDIR)/TourGuiado.o: src/TourGuiado.cpp include/TourGuiado.h include/Experiencia.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/TourGuiado.cpp -o $(OBJDIR)/TourGuiado.o

$(OBJDIR)/Turista.o: src/Turista.cpp include/Turista.h include/Experiencia.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Turista.cpp -o $(OBJDIR)/Turista.o

#para borrar todos los .o y el ejecutable, o sea limpia el proyecto (para hacer make clean)
clean:
	rm -f $(OBJDIR)/*.o principal principal.exe

# info: g++(lee el .cpp lo traduce y crea el ejecutable), -Wall -g(todo junto hace que te muestre los errores/cosas raras en caso de haber) ,-c (le dice al g++ que solo compile, pero que no cree el ejecutable)