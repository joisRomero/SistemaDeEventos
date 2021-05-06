#ifndef LISTADISPONIBILIDAD_H
#define LISTADISPONIBILIDAD_H

#include "disponibilidad.h"
#define DELTA 20

class ListaDisponibilidad{
    int N, Max;
    Disponibilidad **datos;

public:
    ListaDisponibilidad();
    ~ListaDisponibilidad();

    void crece();
    void inserta(Disponibilidad *D);

    void leerListaDisponibilidad();
    void mostrarListaDisponibilidad();
};

#endif // LISTADISPONIBILIDAD_H
