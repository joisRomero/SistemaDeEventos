#ifndef NODOEVENTO_H
#define NODOEVENTO_H

#include "evento.h"


class NodoEvento{
    Evento datos;
    NodoEvento *siguiente;
    ListaDisponibilidad listaDisponibilidad;

public:
    NodoEvento();
    ~NodoEvento(){}

    void setEvento(const Evento&);
    void setSiguiente(NodoEvento*);
    Evento getEvento(){return datos;}
    NodoEvento* getSiguiente(){return siguiente;}

    ListaDisponibilidad getListaDisponibilidad() {return listaDisponibilidad;}
    void setListaDisponibilidad(Disponibilidad disponibilidad);

};

#endif // NODOEVENTO_H
