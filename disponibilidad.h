#ifndef DISPONIBILIDAD_H
#define DISPONIBILIDAD_H

#include "QDateTime"
class Disponibilidad{
    QDate fechaEvento; //(año, mes, dia)
    QTime horaInicioEvento; //(hora, minuto, segundo)
    QTime horaFinEvento;
    int horas;

public:
    Disponibilidad();
    Disponibilidad(QDate, QTime, QTime, int);
    ~Disponibilidad(){}
    QDate getFechaEvento(){return fechaEvento;}
    QTime getHoraInicioEvento(){return horaInicioEvento;}
    QTime getHoraFinEvento(){return horaFinEvento;}
    void setFechaEvento(QDate _fechaEvento);
    void setHoraInicioEvento(QTime _horaInicioEvento);
    void setHoraFinEvento(QTime _horaFinEvento);
};

#endif // DISPONIBILIDAD_H
