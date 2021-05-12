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

void verMas::mostrarEvento(NodoEvento *nodoEvento){
    ui->labelAforo->setText(QString::number(nodoEvento->getEvento().getAforo()));
    ui->labelArea->setText(QString::number(nodoEvento->getEvento().getArea()));
    ui->labelPiso->setText(QString::number(nodoEvento->getEvento().getPiso()));
    ui->labelCosto->setText(QString::number(nodoEvento->getEvento().getCosto()));
    ui->labelDireccion->setText(nodoEvento->getEvento().getDireccion());
    ui->labelNombre->setText(nodoEvento->getEvento().getNombre());
    ui->labelTipo->setText(nodoEvento->getEvento().getTipo());
}

void verMas::on_btnOk_clicked()
{
    this->close();
}
