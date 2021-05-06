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
    NodoEvento* getCabecera(){return cabecera;}
    NodoEvento* getUltimo();

    void insertaListaEventos(const Evento&);
    void mostrarListaEventos();
};

#endif // LISTAEVENTOS_H
