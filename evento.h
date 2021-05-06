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
};

#endif // EVENTO_H
