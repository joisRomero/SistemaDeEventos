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

public:
    Evento();
};

#endif // EVENTO_H
