#include "vntactualizar.h"
#include "ui_vntactualizar.h"
#include "evento.h"
#include "nodoevento.h"
#include <QMessageBox>

VntActualizar::VntActualizar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VntActualizar)
{
    ui->setupUi(this);
    QStringList items;
    items << "Auditorio" << "Cancha deportiva" << "Centro de esparcimiento"
          << "Estadio" << "Laboratorio" << "Sala de conferencia" << "Sala de cómputo"
          << "Salón de baile" << "Salón multimedia";
    ui->tipoEventoActualizar->addItems(items);
}

VntActualizar::~VntActualizar()
{
    delete ui;
}

void VntActualizar::mostrar(Evento evento){

    ui->direccionActualizar->setText(evento.getDireccion());
    ui->aforoActualizar->setText(QString::number(evento.getAforo()));
    ui->nombreActualizar->setText(evento.getNombre());
    ui->costoActualizar->setText(QString::number(evento.getCosto()));
    ui->pisoActualizar->setText(QString::number(evento.getPiso()));
    ui->areaActualizar->setText(QString::number(evento.getArea()));
    ui->tipoEventoActualizar->setCurrentText(evento.getTipo());

}

void VntActualizar::on_btnActualizar_clicked()
{
    //obtengo los datos de la interfas actualizar
    QString tipo = ui->tipoEventoActualizar->itemText(ui->tipoEventoActualizar->currentIndex());
    QString nombre = ui->nombreActualizar->text();
    QString direccion = ui->direccionActualizar->text();
    int aforo = ui->aforoActualizar->text().toInt();
    float area = ui->areaActualizar->text().toFloat();
    int piso = ui->pisoActualizar->text().toInt();
    float costo = ui->costoActualizar->text().toInt();


    //compruebo si todos los campos estan llenos
    if (ui->nombreActualizar->text() != "" && ui->direccionActualizar->text() != ""
       && ui->aforoActualizar->text() != "" && ui->areaActualizar->text() != ""
       && ui->pisoActualizar->text() != "" && ui->costoActualizar->text() != ""){

       Evento eventoAux(tipo, nombre, direccion, aforo, area, piso, costo);

       if (eventoAux.getAforo() <= 0 || eventoAux.getArea() <= 0 ||
               eventoAux.getCosto() <= 0 || eventoAux.getPiso() <= 0 ||
               eventoAux.getPiso() >= 10){
           QMessageBox::warning(this, "", "Ingrese un número válido");
       } else {
           evento = eventoAux;
           this->close();
           ui->nombreActualizar->clear();
           ui->direccionActualizar->clear();
           ui->aforoActualizar->clear();
           ui->areaActualizar->clear();
           ui->pisoActualizar->clear();
           ui->costoActualizar->clear();
       }

    } else {
       QMessageBox::warning(this, "", "Llene todos los campos");
    }

}
