#include "disponibilidad.h"

Disponibilidad::Disponibilidad(){
    horas = 0;
}

Disponibilidad::Disponibilidad(QDate fechaEvento, QTime horaInicioEvento, QTime horaFinEvento, int horas){
    this->fechaEvento = fechaEvento;
    this->horaInicioEvento = horaInicioEvento;
    this->horaFinEvento = horaFinEvento;
    this->horas = horas;
}

void Disponibilidad::setFechaEvento(QDate _fechaEvento){
    fechaEvento = _fechaEvento;
}

void Disponibilidad::setHoraInicioEvento(QTime _horaInicioEvento){
    horaInicioEvento = _horaInicioEvento;
}

void Disponibilidad::leerDisponibilidad(){

}

void Disponibilidad::mostrarDisponibilidad(){

}
