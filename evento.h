#ifndef EVENTO_H
#define EVENTO_H

#include <QString>


class Evento{
    QString nombre;
    QString tipo;
    float area;
    QString direccion;
    int aforo;
    float costo;
    int piso;

public:
    Evento();
    Evento(QString, QString, QString, int, float, int, float);
    ~Evento(){}

    void mostrarEvento();

    QString getTipo(){return tipo;}
    QString getNombre(){return nombre;}
    float getArea(){return area;}
    QString getDireccion(){return direccion;}
    int getAforo(){return aforo;}
    float getCosto(){return costo;}
    int getPiso(){return piso;}
};

#endif // EVENTO_H
