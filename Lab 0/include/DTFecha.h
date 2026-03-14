#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    DTFecha(int, int, int);

    int getDia();
    int getMes();
    int getAnio();
    bool esPosterior(DTFecha fecha); //operacion para comparar fechas

    ~DTFecha();
};

#endif