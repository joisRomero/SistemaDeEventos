#include "acercade.h"
#include "ui_acercade.h"

AcercaDe::AcercaDe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AcercaDe)
{
    ui->setupUi(this);
    ui->link->setText("<a href='https://github.com/joisRomero/SistemaDeEventos'>https://github.com/joisRomero/SistemaDeEventos</a>");
    ui->link->setOpenExternalLinks(true);
}

AcercaDe::~AcercaDe()
{
    delete ui;
}

void AcercaDe::on_pushButton_clicked()
{
    this->close();
}
