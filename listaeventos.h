#ifndef LISTAEVENTOS_H
#define LISTAEVENTOS_H

#include "nodoevento.h"

class ListaEventos{
    NodoEvento *cabecera;
    int total;
public:
    ListaEventos();
    ~ListaEventos();

    void setCabecera(NodoEvento*);
    void setTotal(int);
    NodoEvento* getCabecera(){return cabecera;}
    int getTotal(){return total;}
    NodoEvento* getUltimo();
    Evento getEventoPorNombre(QString nombre);

    void inserta(const Evento&);
    void mostrarListaEventos();
    QStringList buscarPorTipo(QString tipo);
    void eliminarPorNombre(QString nombre);
    ListaEventos buscarDisponibilidad(QString tipo, Disponibilidad disponibilidad);
    void operator = (ListaEventos listaEventos);
    void insertarDisponibilidad(QString nombre, Disponibilidad disponibilidad);
    void actualizarDatos(QString nombre, Evento evento);

};

#endif // LISTAEVENTOS_H
