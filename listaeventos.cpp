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

void ListaEventos::setTotal(int total){
    this->total = total;
}

NodoEvento* ListaEventos::getUltimo(){
    NodoEvento *ultimo = cabecera;
    while(ultimo->getSiguiente() != NULL){
        ultimo = ultimo->getSiguiente();
    }
    return ultimo;
}

void ListaEventos::inserta(const Evento& _evento){
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
        aux->getEvento().mostrarEvento();
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

ListaEventos ListaEventos::buscarDisponibilidad(QString tipo, Disponibilidad disponibilidad){
    ListaEventos listaAux;
    NodoEvento *aux = cabecera;
    while(aux != NULL){
        if (aux->getEvento().getTipo() == tipo){
            if(aux->getListaDisponibilidad().buscarDisponibilidad(disponibilidad)){
                 listaAux.inserta(aux->getEvento());
            }
        }
        aux =  aux->getSiguiente();
    }
    return listaAux;
}

void ListaEventos::operator=(ListaEventos listaEventos){
    NodoEvento *aux = listaEventos.getCabecera();
    while(aux != NULL){
        this->inserta(aux->getEvento());
        aux =  aux->getSiguiente();
    }
}

Evento ListaEventos::getEventoPorNombre(QString nombre){
    NodoEvento *aux = cabecera;
    Evento eventoAux;
    while(aux != NULL){
        if (aux->getEvento().getNombre() == nombre){
            eventoAux = aux->getEvento();
        }
        aux =  aux->getSiguiente();
    }
    return eventoAux;
}

void ListaEventos::insertarDisponibilidad(QString nombre, Disponibilidad disponibilidad){
    NodoEvento *aux = cabecera;
    while(aux != NULL){
        if (aux->getEvento().getNombre() == nombre){
            aux->setListaDisponibilidad(disponibilidad);
        }
        aux =  aux->getSiguiente();
    }
}

void ListaEventos::actualizarDatos(QString nombre, Evento evento){
    NodoEvento *aux = cabecera;
    while(aux != NULL){
        if (aux->getEvento().getNombre() == nombre){
            aux->setEvento(evento);
        }
        aux = aux->getSiguiente();
    }
}

NodoEvento* ListaEventos::getNodoEvento(QString nombre){
    NodoEvento *aux = cabecera;
    NodoEvento *aux2;
    while(aux != NULL){
        if(aux->getEvento().getNombre() == nombre){
            aux2 = aux;
        }
        aux = aux->getSiguiente();
    }
    return aux2;
}
