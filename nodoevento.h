#ifndef NODOEVENTO_H
#define NODOEVENTO_H

#include "evento.h"
#include "listadisponibilidad.h"

class NodoEvento{
    Evento datos;
    NodoEvento *siguiente;
    ListaDisponibilidad disponibilidad;

public:
    NodoEvento();
    ~NodoEvento(){}

    void setEvento(const Evento&);
    void setSiguiente(NodoEvento*);
    Evento getEvento(){return datos;}
    NodoEvento* getSiguiente(){return siguiente;}
};

#endif // NODOEVENTO_H
