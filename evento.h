#ifndef EVENTO_H
#define EVENTO_H

#include <QString>
#include "listadisponibilidad.h"


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

    void mostrarEvento();

    QString getTipo(){return tipo;}
    QString getNombre(){return nombre;}
    int getAforo(){return aforo;}
    float getCosto(){return costo;}
    float getArea(){return area;}
    QString getDireccion(){return direccion;}
    int getPiso(){return piso;}

    void setTipo(QString tipo){this->tipo = tipo;}
    void setNombre(QString nombre){this->nombre = nombre;}
    void setAforo(int aforo){this->aforo = aforo;}
    void setCosto(float costo){this->costo = costo;}
    void setArea(float area){this->area = area;}
    void setDireccion(QString direccion){this->direccion = direccion;}
    void setPiso(int piso){this->piso = piso;}

};

#endif // EVENTO_H
