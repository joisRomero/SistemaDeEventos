#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evento.h"
#include "listaeventos.h"
#include <QDebug>
#include <QMessageBox>

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

    //items
    QStringList items;
    items << "Auditorio" << "Cancha deportiva" << "Centro de esparcimiento"
          << "Estadio" << "Laboratorio" << "Sala de conferencia" << "Sala de cómputo"
          << "Salón de baile" << "Salón multimedia";

    ui->tipoEventoAgregar->addItems(items);
    ui->tipoEventoAlquilar->addItems(items);
    ui->tipoEventoActualizar->addItems(items);
    ui->tipoEventoEliminar->addItems(items);
    ui->tipoEventoActualizarBuscar->addItems(items);

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

void MainWindow::on_btnGuardarAgregar_clicked()
{
    //obtengo los datos de la interfas agregar
    QString tipo = ui->tipoEventoAgregar->itemText(ui->tipoEventoAgregar->currentIndex());
    QString nombre = ui->nombreAgregar->text();
    QString direccion = ui->direccionAgregar->text();
    int aforo = ui->aforoAgregar->text().toInt();
    float area = ui->areaAgregar->text().toFloat();
    int piso = ui->pisoAgregar->text().toInt();
    float costo = ui->precioAgregar->text().toInt();

    //compruebo si todos los campos estan llenos
    if (ui->nombreAgregar->text() != "" && ui->direccionAgregar->text() != ""
        && ui->aforoAgregar->text() != "" && ui->areaAgregar->text() != ""
        && ui->pisoAgregar->text() != "" && ui->precioAgregar->text() != ""){
        Evento eventoAux(tipo, nombre, direccion, aforo, area, piso, costo);
        listaEvento.insertaListaEventos(eventoAux);
    } else {
        QMessageBox::critical(this, "ERROR", "Llene todos los campos");
    }

    listaEvento.mostrarListaEventos();
    ui->nombreAgregar->clear();
    ui->direccionAgregar->clear();
    ui->aforoAgregar->clear();
    ui->areaAgregar->clear();
    ui->pisoAgregar->clear();
    ui->precioAgregar->clear();
}
