#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Titulos para la tamba en la pestania Alquilar
    QStringList titulosAlquilar;
    titulosAlquilar << "Nombre" << "Aforo" << "Precio";
    ui->tablaAlquilar->setColumnCount(3);
    ui->tablaAlquilar->setHorizontalHeaderLabels(titulosAlquilar);
    ui->tablaAlquilar->setColumnWidth(0, 465);
    ui->tablaAlquilar->setColumnWidth(1, 50);
    ui->tablaAlquilar->setColumnWidth(2, 50);

    //Titulos para la tamba en la pestania Alquilar
    QStringList titulosActualizar;
    titulosActualizar << "Nombre";
    ui->tablaActualizar->setColumnCount(1);
    ui->tablaActualizar->setHorizontalHeaderLabels(titulosActualizar);
    ui->tablaActualizar->setColumnWidth(0, 580);

    //Titulos para la tamba en la pestania Eliminar
    QStringList titulosEliminar;
    titulosEliminar << "Nombre";
    ui->tablaEliminar->setColumnCount(1);
    ui->tablaEliminar->setHorizontalHeaderLabels(titulosEliminar);
    ui->tablaEliminar->setColumnWidth(0, 580);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnVerMasAlquilar_clicked()
{
    int i = ui->tablaAlquilar->currentRow();

    if ( i > -1){
        qDebug()<< "lo he seleccionado";
    }
}
