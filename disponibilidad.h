#ifndef DISPONIBILIDAD_H
#define DISPONIBILIDAD_H

#include "QDateTime"
class Disponibilidad{
    QDate fechaEvento;
    QTime horaInicioEvento;
    QTime horaFinEvento;
    int horas;

public:
    Disponibilidad();
    Disponibilidad(QDate, QTime, QTime, int);
    QDate getFechaEvento(){return fechaEvento;}
    QTime getHoraInicioEvento(){return horaInicioEvento;}
    QTime getHoraFinEvento(){return horaFinEvento;}
    void setFechaEvento(QDate _fechaEvento);
    void setHoraInicioEvento(QTime _horaInicioEvento);
    void setHoraFinEvento(QTime _horaFinEvento);
    int getHoras() const;
    void setHoras(int value);
};

#endif // DISPONIBILIDAD_H
