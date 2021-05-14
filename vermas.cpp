#include "vermas.h"
#include "ui_vermas.h"
#include "evento.h"

verMas::verMas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verMas)
{
    ui->setupUi(this);
}

verMas::~verMas()
{
    delete ui;
}

void verMas::mostrarEvento(NodoEvento *auxNodoEvento){
    ui->labelAforo->setText(QString::number(auxNodoEvento->getEvento().getAforo()));
    ui->labelArea->setText(QString::number(auxNodoEvento->getEvento().getArea()));
    ui->labelPiso->setText(QString::number(auxNodoEvento->getEvento().getPiso()));
    ui->labelCosto->setText(QString::number(auxNodoEvento->getEvento().getCosto()));
    ui->labelDireccion->setText(auxNodoEvento->getEvento().getDireccion());
    ui->labelNombre->setText(auxNodoEvento->getEvento().getNombre());
    ui->labelTipo->setText(auxNodoEvento->getEvento().getTipo());

    //Group Box Derecha: EVENTOS
    //Borra todas las filas
    int filas = ui->tablaEventosVerMas->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaEventosVerMas->removeRow(i);
    }

    QString dia, mes, anio, horaInicio, minutosInicio, horaFin, minutosFin;
    QString fecha;
    QString horaCompletaInicio;
    QString horaCompletaFin;

    for(int i = 0; i < auxNodoEvento->getListaDisponibilidad().getN(); i++){
        dia = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getFechaEvento().day());
        mes = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getFechaEvento().month());
        anio = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getFechaEvento().year());
        fecha = dia + "/" + mes + "/"+ anio;

        horaInicio = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoraInicioEvento().hour());
        minutosInicio = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoraInicioEvento().minute());
        horaCompletaInicio = horaInicio + ":" + minutosInicio;

        horaFin = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoraFinEvento().hour());
        minutosFin = QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoraFinEvento().minute());
        horaCompletaFin = horaFin+ ":" + minutosFin;

        //Creo una fila al final de la tabla
        ui->tablaEventosVerMas->insertRow(ui->tablaEventosVerMas->rowCount());
        //inserto elementos en la fila creada
        ui->tablaEventosVerMas->setItem(ui->tablaEventosVerMas->rowCount() -1, 0, new QTableWidgetItem(fecha));
        ui->tablaEventosVerMas->setItem(ui->tablaEventosVerMas->rowCount() -1, 1, new QTableWidgetItem(horaCompletaInicio));
        ui->tablaEventosVerMas->setItem(ui->tablaEventosVerMas->rowCount() -1, 2, new QTableWidgetItem(horaCompletaFin));
        ui->tablaEventosVerMas->setItem(ui->tablaEventosVerMas->rowCount() -1, 3,
                                        new QTableWidgetItem(QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoras())));
    }
}

void verMas::on_btnOk_clicked()
{
    this->close();
}
