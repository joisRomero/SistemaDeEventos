#include "listadisponibilidad.h"
#include <QDebug>

ListaDisponibilidad::ListaDisponibilidad(){
    N = 0;
    Max = 0;
    datos = NULL;
}

void ListaDisponibilidad::crece(){
    Disponibilidad *aux = new Disponibilidad [Max+DELTA];
    for(int i = 0; i < N; i++){
        aux[i] = datos[i];
    }
    delete datos;
    datos = aux;
    Max += DELTA;
}

void ListaDisponibilidad::inserta(Disponibilidad D){
    if(N == Max){
        crece();
    }
    datos[N] = D;
    N++;
}

bool ListaDisponibilidad::buscarDisponibilidad(Disponibilidad disponibilidad){
    bool band = 0;
    bool encontreFecha = 0;
    if (N == 0){
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (datos[i].getFechaEvento() == disponibilidad.getFechaEvento()){
            encontreFecha = 1;
            if (datos[i].getHoraFinEvento() < disponibilidad.getHoraInicioEvento()
                    || datos[i].getHoraInicioEvento() > disponibilidad.getHoraFinEvento()){
                band = 1;
            } else {
                band = 0;
            }
        }
    }

    if (encontreFecha == 0){
        return true;
    }

    if (band == 1){
        return true;
    }

    return false;
}

void ListaDisponibilidad::mostrarListaDisponibilidad(){
    for (int i = 0; i < N; i++){
        qDebug() << "*" << datos[i].getFechaEvento();
        qDebug() << "*" << datos[i].getHoraInicioEvento();
        qDebug() << "*" << datos[i].getHoraFinEvento();
    }
}
