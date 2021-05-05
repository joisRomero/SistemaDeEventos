#include "disponibilidad.h"

Disponibilidad::Disponibilidad(){
    horas = 0;
}

void Disponibilidad::setFechaEvento(QDate _fechaEvento){
    fechaEvento = _fechaEvento;
}

void Disponibilidad::setHoraInicioEvento(QTime _horaInicioEvento){
    horaInicioEvento = _horaInicioEvento;
}
