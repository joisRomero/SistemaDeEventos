#include "evento.h"
#include <QDebug>

Evento::Evento(){
    nombre = "";
    tipo = "";
    area = 0;
    direccion = "";
    aforo = 0;
    costo = 0.0;
    piso = 0;
}

Evento::Evento(QString tipo, QString nombre, QString direccion, int aforo, float area, int piso, float costo){
    this->tipo = tipo;
    this->nombre = nombre;
    this->direccion = direccion;
    this->aforo = aforo;
    this->area = area;
    this->piso = piso;
    this->costo = costo;
}

void Evento::mostrarEvento(){
    qDebug()<< "," << tipo;
    qDebug()<< "," << nombre;
    qDebug()<< "," << direccion;
    qDebug()<< "," << aforo;
    qDebug()<< "," << area;
    qDebug()<< "," << piso;
    qDebug()<< "," << costo;
}
