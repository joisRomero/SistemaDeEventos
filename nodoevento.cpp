#include "nodoevento.h"

NodoEvento::NodoEvento(){
    siguiente = NULL;
}

void NodoEvento::setEvento(const Evento& _datos){
    datos = _datos;
}

void NodoEvento::setSiguiente(NodoEvento * _siguiente){
    siguiente = _siguiente;
}
