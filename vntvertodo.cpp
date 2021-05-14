#include "vntvertodo.h"
#include "ui_vntvertodo.h"

VntVerTodo::VntVerTodo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VntVerTodo)
{
    ui->setupUi(this);
}

VntVerTodo::~VntVerTodo()
{
    delete ui;
}

void VntVerTodo::mostrarEvento(NodoEvento *auxNodoEvento){
    ui->labelAforo_2->setText(QString::number(auxNodoEvento->getEvento().getAforo()));
    ui->labelArea_2->setText(QString::number(auxNodoEvento->getEvento().getArea()));
    ui->labelPiso_2->setText(QString::number(auxNodoEvento->getEvento().getPiso()));
    ui->labelCosto_2->setText(QString::number(auxNodoEvento->getEvento().getCosto()));
    ui->labelDireccion_2->setText(auxNodoEvento->getEvento().getDireccion());
    ui->labelNombre_2->setText(auxNodoEvento->getEvento().getNombre());
    ui->labelTipo_2->setText(auxNodoEvento->getEvento().getTipo());

    //Group Box Derecha: EVENTOS
    //Borra todas las filas
    int filas = ui->tablaEventosVerMas_2->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaEventosVerMas_2->removeRow(i);
    }

    QString dia, mes, anio, horaInicio, minutosInicio, horaFin, minutosFin;
    QString fecha;
    QString horaCompletaInicio;
    QString horaCompletaFin;

    int totalHoras = 0;
    int dineroRecaudado = 0;

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
        ui->tablaEventosVerMas_2->insertRow(ui->tablaEventosVerMas_2->rowCount());
        //inserto elementos en la fila creada
        ui->tablaEventosVerMas_2->setItem(ui->tablaEventosVerMas_2->rowCount() -1, 0, new QTableWidgetItem(fecha));
        ui->tablaEventosVerMas_2->setItem(ui->tablaEventosVerMas_2->rowCount() -1, 1, new QTableWidgetItem(horaCompletaInicio));
        ui->tablaEventosVerMas_2->setItem(ui->tablaEventosVerMas_2->rowCount() -1, 2, new QTableWidgetItem(horaCompletaFin));
        ui->tablaEventosVerMas_2->setItem(ui->tablaEventosVerMas_2->rowCount() -1, 3,
                                        new QTableWidgetItem(QString::number(auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoras())));

        totalHoras += auxNodoEvento->getListaDisponibilidad().getDisponibilidad()[i].getHoras();
    }

    dineroRecaudado = totalHoras * auxNodoEvento->getEvento().getCosto();
    ui->labelDineroRecaudado->setText(QString::number(dineroRecaudado));
    ui->labelTotalHoras->setText(QString::number(totalHoras));
}

void VntVerTodo::on_btnOk_clicked()
{
    this->close();
}
