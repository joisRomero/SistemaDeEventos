#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evento.h"
#include "listaeventos.h"
#include <QDebug>
#include <QMessageBox>
#include "vermas.h"
#include "ui_verMas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Titulos para la tabla en la pestania Alquilar
    QStringList titulosAlquilar;
    titulosAlquilar << "Nombre" << "Aforo" << "Precio";
    ui->tablaAlquilar->setColumnCount(3);
    ui->tablaAlquilar->setHorizontalHeaderLabels(titulosAlquilar);
    ui->tablaAlquilar->setColumnWidth(0, 465);
    ui->tablaAlquilar->setColumnWidth(1, 50);
    ui->tablaAlquilar->setColumnWidth(2, 50);

    //Titulos para la tabla en la pestania actualizar
    QStringList titulosActualizar;
    titulosActualizar << "Nombre";
    ui->tablaActualizar->setColumnCount(1);
    ui->tablaActualizar->setHorizontalHeaderLabels(titulosActualizar);
    ui->tablaActualizar->setColumnWidth(0, 580);

    //Titulos para la tabla en la pestania Eliminar
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

    //Hora y fecha alquilar
    ui->fechaAlquilar->setDate(QDate::currentDate());
    ui->horaAlquilar->setTime(QTime::currentTime());
}

MainWindow::~MainWindow()
{
    delete ui;
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
        listaEvento.inserta(eventoAux);
    } else {
        QMessageBox::warning(this, "", "Llene todos los campos");
    }

    ui->nombreAgregar->clear();
    ui->direccionAgregar->clear();
    ui->aforoAgregar->clear();
    ui->areaAgregar->clear();
    ui->pisoAgregar->clear();
    ui->precioAgregar->clear();
}

void MainWindow::on_btnBuscarEliminar_clicked()
{
    //Borrar todas las filas
    int cant = ui->tablaEliminar->rowCount();
    for (int y = cant - 1; y >= 0; y--) {
        ui->tablaEliminar->removeRow(y);
    }

    QString tipo = ui->tipoEventoEliminar->itemText(ui->tipoEventoEliminar->currentIndex());
    QStringList nombresAux = listaEvento.buscarPorTipo(tipo);

    if (nombresAux.length() > 0){
        for (int i = 0; i < nombresAux.length(); i++) {
            //Creo una fila al final de la tabla
            ui->tablaEliminar->insertRow(ui->tablaEliminar->rowCount());
            //inserto elementos en la fila creada
            ui->tablaEliminar->setItem(ui->tablaEliminar->rowCount() - 1, 0,
                                       new QTableWidgetItem(nombresAux[i]));
        }
    } else {
        QMessageBox::information(this, "", "No hay eventos de ese tipo registrados");
    }
}

void MainWindow::on_btnEliminar_clicked()
{
    //Obetengo un valor numero que me indica si una fila esta selecionada
    //Devuelve -1 si no hay nada seleccionado
    int seleccion = ui->tablaEliminar->currentRow();

    //Verifico si una fila esta seleccionada
    if ( seleccion > -1){
        if (QMessageBox::question(this, "", "¿Estás seguro de eliminar?") == QMessageBox::Yes){
            //obtengo el nombre de la fila ha eliminar
            QString nombre = ui->tablaEliminar->currentItem()->text();
            listaEvento.eliminarPorNombre(nombre);
            QMessageBox::information(this, "", "Eliminado con éxito");
        }

    } else {
        QMessageBox::warning(this, "", "Seleccione un evento");
    }

    //Borra todas las filas
    int cant = ui->tablaEliminar->rowCount();
    for (int y = cant - 1; y >= 0; y--) {
        ui->tablaEliminar->removeRow(y);
    }
}

void MainWindow::on_btnBuscarActualizar_clicked()
{
   //Borra todas las filas
   int cant = ui->tablaActualizar->rowCount();
   for (int y = cant - 1; y >= 0; y--) {
       ui->tablaActualizar->removeRow(y);
   }
   QString tipo = ui->tipoEventoActualizarBuscar->itemText(ui->tipoEventoActualizarBuscar->currentIndex());
   QStringList nombresAux = listaEvento.buscarPorTipo(tipo);

   if (nombresAux.length() > 0){
       for (int i = 0; i < nombresAux.length(); i++) {
       //Creo una fila al final de la tabla
       ui->tablaActualizar->insertRow(ui->tablaActualizar->rowCount());
       //inserto elementos en la fila creada
       ui->tablaActualizar->setItem(ui->tablaActualizar->rowCount() - 1, 0,
                                      new QTableWidgetItem(nombresAux[i]));
       }
   } else {
       QMessageBox::information(this, "", "No hay eventos de ese tipo registrados");
   }
}

void MainWindow::on_btnBuscarAlquilar_clicked()
{
    //Borra todas las filas
    int cant = ui->tablaAlquilar->rowCount();
    for (int y = cant - 1; y >= 0; y--) {
        ui->tablaAlquilar->removeRow(y);
    }

    ListaEventos listaAux;

    //Obtengo los datos de la interfaz Alquilar
    QString tipo = ui->tipoEventoAlquilar->itemText(ui->tipoEventoAlquilar->currentIndex());
    QDate fecha = ui->fechaAlquilar->date();
    QTime horaInicio = ui->horaAlquilar->time();
    int horas = ui->tiempoAlquilar->text().toInt();
    QTime horaFin = horaInicio.addSecs(horas*3600);

    //Compruebo si todos los campos estan llenos
    if (ui->tiempoAlquilar->text() == ""){
        QMessageBox::warning(this, "", "Llene todos los campos");
    }else if (fecha < QDate::currentDate()){
        QMessageBox::warning(this, "", "Ingrese una fecha mayor a la actual");
    } else {
        Disponibilidad auxDis(fecha, horaInicio, horaFin, horas);
        listaAux = listaEvento.buscarDisponibilidad(tipo,auxDis);
        if(listaAux.getTotal() == 0){
            QMessageBox::warning(this, "", "No se encontraron Eventos");
        } else {
            NodoEvento *aux = listaAux.getCabecera();
            while(aux != NULL){
                //Creo una fila al final de la tabla
                ui->tablaAlquilar->insertRow(ui->tablaAlquilar->rowCount());
                //inserto elementos en la fila creada
                ui->tablaAlquilar->setItem(ui->tablaAlquilar->rowCount() - 1, 0,
                                           new QTableWidgetItem(aux->getEvento().getNombre()));
                ui->tablaAlquilar->setItem(ui->tablaAlquilar->rowCount() - 1, 1,
                                           new QTableWidgetItem(QString::number(aux->getEvento().getAforo())));
                ui->tablaAlquilar->setItem(ui->tablaAlquilar->rowCount() - 1, 2,
                                           new QTableWidgetItem(QString::number(aux->getEvento().getCosto())));
                aux =  aux->getSiguiente();
            }
        }
    }

}

void MainWindow::on_btnVerMasAlquilar_clicked()
{
    int i = ui->tablaAlquilar->currentRow();
    Evento evento;
    NodoEvento *aux;
    if ( i > -1){
        verMas *ventana = new verMas;
        ventana->setModal(true);
        ventana->show();
        QString nombre = ui->tablaAlquilar->currentItem()->text();

        evento = listaEvento.getEventoPorNombre(nombre);

        aux = listaEvento.getNodoEvento(nombre);
        ventana->mostrarEvento(aux);
    }
}


void MainWindow::on_btnAlquilar_clicked()
{
    int i = ui->tablaAlquilar->currentRow();

    if ( i > -1){
        //Obtengo los datos de la interfaz Alquilar
        QString tipo = ui->tipoEventoAlquilar->itemText(ui->tipoEventoAlquilar->currentIndex());
        QDate fecha = ui->fechaAlquilar->date();
        QTime horaInicio = ui->horaAlquilar->time();
        int horas = ui->tiempoAlquilar->text().toInt();
        QTime horaFin = horaInicio.addSecs(horas*3600);

        Disponibilidad disponibilidad(fecha, horaInicio, horaFin, horas);

        QString nombre = ui->tablaAlquilar->currentItem()->text();
        listaEvento.insertarDisponibilidad(nombre, disponibilidad);

        QMessageBox::information(this, "", "Operacion terminada con exito");

        //Borra todas las filas
        int cant = ui->tablaAlquilar->rowCount();
        for (int y = cant - 1; y >= 0; y--) {
            ui->tablaAlquilar->removeRow(y);
        }

    }
}

void MainWindow::on_btnSeleccionarActualizar_clicked()
{
    int seleccion = ui->tablaActualizar->currentRow();
    if ( seleccion > -1){
        //obtengo el nombre de la fila ha actualizar
        NodoEvento *aux = listaEvento.getCabecera();
        QString nombre = ui->tablaActualizar->currentItem()->text();
        QString direccion, tipo;
        int aforo,piso;
        float area,costo;
        while(aux != NULL){
            if (aux->getEvento().getNombre() == nombre){
                area=aux->getEvento().getArea();
                direccion=aux->getEvento().getDireccion();
                aforo=aux->getEvento().getAforo();
                costo=aux->getEvento().getCosto();
                piso=aux->getEvento().getPiso();
                tipo=aux->getEvento().getTipo();
            }
            aux =  aux->getSiguiente();
        }
        nombreAux = nombre;
        ui->direccionActualizar->setText(direccion);
        ui->aforoActualizar->setText(QString::number(aforo));
        ui->nombreActualizar->setText(nombre);
        ui->costoActualizar->setText(QString::number(costo));
        ui->pisoActualizar->setText(QString::number(piso));
        ui->areaActualizar->setText(QString::number(area));
        ui->tipoEventoActualizar->setCurrentText(tipo);

        ui->tipoEventoActualizar->setEnabled(true);
        ui->direccionActualizar->setEnabled(true);
        ui->aforoActualizar->setEnabled(true);
        ui->nombreActualizar->setEnabled(true);
        ui->costoActualizar->setEnabled(true);
        ui->pisoActualizar->setEnabled(true);
        ui->areaActualizar->setEnabled(true);
        ui->btnActualizar->setEnabled(true);

    }else {
        QMessageBox::warning(this, "", "Seleccione un evento");
   }
}

void MainWindow::on_btnActualizar_clicked()
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
       QString nombres = ui->tablaActualizar->currentItem()->text();
       listaEvento.actualizarDatos(nombres, eventoAux);
       QMessageBox::information(this, "", "Actualizado con éxito");

   } else {
       QMessageBox::warning(this, "", "Llene todos los campos");
   }

   ui->nombreActualizar->clear();
   ui->direccionActualizar->clear();
   ui->aforoActualizar->clear();
   ui->areaActualizar->clear();
   ui->pisoActualizar->clear();
   ui->costoActualizar->clear();

   ui->tipoEventoActualizar->setEnabled(false);
   ui->direccionActualizar->setEnabled(false);
   ui->aforoActualizar->setEnabled(false);
   ui->nombreActualizar->setEnabled(false);
   ui->costoActualizar->setEnabled(false);
   ui->pisoActualizar->setEnabled(false);
   ui->areaActualizar->setEnabled(false);
   ui->btnActualizar->setEnabled(false);

   //Borra todas las filas
   int cant = ui->tablaActualizar->rowCount();
   for (int y = cant - 1; y >= 0; y--) {
       ui->tablaActualizar->removeRow(y);
   }
}
