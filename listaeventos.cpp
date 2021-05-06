#include "listaeventos.h"
#include <QDebug>

ListaEventos::ListaEventos(){
    cabecera = NULL;
    total = 0;
}

ListaEventos::~ListaEventos(){
    NodoEvento *aux = cabecera;
    while(aux != NULL){
        cabecera = aux->getSiguiente();
        delete aux;
        aux = cabecera;
    }
}

void ListaEventos::setCabecera(NodoEvento *_cabecera){
    cabecera = _cabecera;
}

NodoEvento* ListaEventos::getUltimo(){
    NodoEvento *ultimo = cabecera;
    while(ultimo->getSiguiente() != NULL){
        ultimo = ultimo->getSiguiente();
    }
    return ultimo;
}

void ListaEventos::insertaListaEventos(const Evento& _evento){
    NodoEvento *aux = new NodoEvento;
    aux->setEvento(_evento);

    if(cabecera == NULL){
        aux->setSiguiente(cabecera);
        cabecera = aux;
    }else{
        aux->setSiguiente(getUltimo()->getSiguiente());
        getUltimo()->setSiguiente(aux);
    }
    total++;
}

void ListaEventos::mostrarListaEventos(){
    NodoEvento *aux = cabecera;

    while(aux != NULL){
        qDebug()<< "--------";
        aux->getEvento().mostrarEvento();
        qDebug()<< "--------";
        aux =  aux->getSiguiente();
    }
}
