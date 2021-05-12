#ifndef LISTADISPONIBILIDAD_H
#define LISTADISPONIBILIDAD_H

#include "disponibilidad.h"
#define DELTA 4

class ListaDisponibilidad{
    int N, Max;
    Disponibilidad *datos;
public:
    ListaDisponibilidad();

    void crece();
    void inserta(Disponibilidad);

    void leerListaDisponibilidad();
    void mostrarListaDisponibilidad();

    bool buscarDisponibilidad(Disponibilidad disponibilidad);
    friend class Evento;
};

#endif // LISTADISPONIBILIDAD_H
