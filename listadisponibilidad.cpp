#include "listadisponibilidad.h"
#include <QDebug>

ListaDisponibilidad::ListaDisponibilidad(){
    N = 0;
    Max = 0;
    datos = NULL;
}

ListaDisponibilidad::~ListaDisponibilidad(){
    delete []datos;
}

void ListaDisponibilidad::crece(){
    Disponibilidad **aux = new Disponibilidad *[Max+DELTA];
    for(int i = 0; i < N; i++){
        aux[i] = datos[i];
    }
    delete []datos;
    datos = aux;
    Max += DELTA;
}

void ListaDisponibilidad::inserta(Disponibilidad *D){
    if(N == Max){
        crece();
    }
    datos[N] = D;
    N++;
}

void ListaDisponibilidad::leerListaDisponibilidad(){
    qDebug()<<"s";
}
