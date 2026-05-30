#Laboratorio 4
CC = g++
CFLAGS = -Wall -g -std=c++11
OBJDIR = obj

OBJ = $(OBJDIR)/main.o $(OBJDIR)/Calificacion.o $(OBJDIR)/CargaDatos.o $(OBJDIR)/Conductor.o $(OBJDIR)/ControladorFechaActual.o $(OBJDIR)/DTConsultaViaje.o $(OBJDIR)/DTDetalleReserva.o $(OBJDIR)/DTDetalleVehiculo.o $(OBJDIR)/DTDetalleViaje.o $(OBJDIR)/DTFecha.o $(OBJDIR)/DTListarViaje.o $(OBJDIR)/DTUsuario.o $(OBJDIR)/DTUsuarioViaje.o $(OBJDIR)/DTVehiculosConductor.o $(OBJDIR)/Fabrica.o $(OBJDIR)/Menu.o $(OBJDIR)/Pasajero.o $(OBJDIR)/Reserva.o $(OBJDIR)/Usuario.o $(OBJDIR)/Vehiculo.o $(OBJDIR)/Viaje.o

all: principal

principal: $(OBJ) #como se va a llamar al programa a la hora de compilar y todos los archivos que usa
	$(CC) $(CFLAGS) $(OBJ) -o principal

#para que compile  cuando se cambia algo en el .cpp o el .h
$(OBJDIR)/main.o: src/main.cpp include/Menu.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Calificacion.o: src/Calificacion.cpp include/Calificacion.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Calificacion.cpp -o $(OBJDIR)/Calificacion.o

$(OBJDIR)/CargaDatos.o: src/CargaDatos.cpp include/CargaDatos.h | $(OBJDIR) 
	$(CC) $(CFLAGS) -c src/CargaDatos.cpp -o $(OBJDIR)/CargaDatos.o

$(OBJDIR)/Conductor.o: src/Conductor.cpp include/Conductor.h include/Usuario.h include/TipoLibreta.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Conductor.cpp -o $(OBJDIR)/Conductor.o

$(OBJDIR)/ControladorFechaActual.o: src/ControladorFechaActual.cpp include/ControladorFechaActual.h include/IControladorFechaActual.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/ControladorFechaActual.cpp -o $(OBJDIR)/ControladorFechaActual.o

$(OBJDIR)/DTConsultaViaje.o: src/DTConsultaViaje.cpp include/DTConsultaViaje.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTConsultaViaje.cpp -o $(OBJDIR)/DTConsultaViaje.o

$(OBJDIR)/DTDetalleReserva.o: src/DTDetalleReserva.cpp include/DTDetalleReserva.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTDetalleReserva.cpp -o $(OBJDIR)/DTDetalleReserva.o

$(OBJDIR)/DTDetalleVehiculo.o: src/DTDetalleVehiculo.cpp include/DTDetalleVehiculo.h include/TipoVehiculo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTDetalleVehiculo.cpp -o $(OBJDIR)/DTDetalleVehiculo.o

$(OBJDIR)/DTDetalleViaje.o: src/DTDetalleViaje.cpp include/DTDetalleViaje.h include/DTFecha.h include/DTDetalleVehiculo.h include/DTDetalleReserva.h |$(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTDetalleViaje.cpp -o $(OBJDIR)/DTDetalleViaje.o

$(OBJDIR)/DTFecha.o: src/DTFecha.cpp include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTFecha.cpp -o $(OBJDIR)/DTFecha.o

$(OBJDIR)/DTListarViaje.o: src/DTListarViaje.cpp include/DTListarViaje.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTListarViaje.cpp -o $(OBJDIR)/DTListarViaje.o

$(OBJDIR)/DTUsuario.o: src/DTUsuario.cpp include/DTUsuario.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTUsuario.cpp -o $(OBJDIR)/DTUsuario.o

$(OBJDIR)/DTUsuarioViaje.o: src/DTUsuarioViaje.cpp include/DTUsuarioViaje.h include/TipoUsuario.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTUsuarioViaje.cpp -o $(OBJDIR)/DTUsuarioViaje.o

$(OBJDIR)/DTVehiculosConductor.o: src/DTVehiculosConductor.cpp include/DTVehiculosConductor.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/DTVehiculosConductor.cpp -o $(OBJDIR)/DTVehiculosConductor.o

$(OBJDIR)/Fabrica.o: src/Fabrica.cpp include/Fabrica.h include/ControladorFechaActual.h include/IControladorFechaActual.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Fabrica.cpp -o $(OBJDIR)/Fabrica.o

$(OBJDIR)/Menu.o: src/Menu.cpp include/Menu.h include/Fabrica.h include/IControladorFechaActual.h include/CargaDatos.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Menu.cpp -o $(OBJDIR)/Menu.o

$(OBJDIR)/Pasajero.o: src/Pasajero.cpp include/Pasajero.h include/Usuario.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Pasajero.cpp -o $(OBJDIR)/Pasajero.o

$(OBJDIR)/Reserva.o: src/Reserva.cpp include/Reserva.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Reserva.cpp -o $(OBJDIR)/Reserva.o

$(OBJDIR)/Usuario.o: src/Usuario include/Usuario.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Usuario.cpp -o $(OBJDIR)/Usuario.o

$(OBJDIR)/Vehiculo.o: src/Vehiculo.cpp include/Vehiculo.h include/TipoVehiculo.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Vehiculo.cpp -o $(OBJDIR)/Vehiculo.o

$(OBJDIR)/Viaje.o: src/Viaje.cpp include/Viaje.h include/DTFecha.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/Viaje.cpp -o $(OBJDIR)/Viaje.o

clean: 
	rm -f $(OBJDIR)/*.o principal principal.exe
