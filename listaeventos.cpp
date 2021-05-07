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

QStringList ListaEventos::buscarPorTipo(QString tipo){
    NodoEvento *aux = cabecera;
    QStringList nombres;
    while(aux != NULL){
        if (aux->getEvento().getTipo() == tipo){
            nombres << aux->getEvento().getNombre();
        }
        aux =  aux->getSiguiente();
    }

    return nombres;
}

void ListaEventos::eliminarPorNombre(QString nombre){
    NodoEvento *aux = cabecera;
    NodoEvento *anterior = NULL;

    while(aux != NULL && aux->getEvento().getNombre() != nombre){
        anterior = aux;
        aux = aux->getSiguiente();
    }

    if(aux == NULL){
    } else {
        if (anterior == NULL){
            cabecera = aux->getSiguiente();
            delete aux;
        } else {
            anterior->setSiguiente(aux->getSiguiente());
            delete aux;
        }
        total--;
    }
}
