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

void verMas::mostrarEvento(Evento evento){
    ui->labelAforo->setText(QString::number(evento.getAforo()));
    ui->labelArea->setText(QString::number(evento.getArea()));
    ui->labelPiso->setText(QString::number(evento.getPiso()));
    ui->labelCosto->setText(QString::number(evento.getCosto()));
    ui->labelDireccion->setText(evento.getDireccion());
    ui->labelNombre->setText(evento.getNombre());
    ui->labelTipo->setText(evento.getTipo());
}

void verMas::on_btnOk_clicked()
{
    this->close();
}
