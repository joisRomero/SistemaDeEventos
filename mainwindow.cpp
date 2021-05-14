/*
    INTEGRANTES:
        Romero Olivera José Luis
        Gonzales Bocanegra José David
        Chávez Alvites Jairo
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evento.h"
#include "listaeventos.h"
#include <QDebug>
#include <QMessageBox>
#include "vermas.h"
#include "ui_verMas.h"
#include "vntactualizar.h"
#include "vtnagregaritems.h"
#include "acercade.h"
#include "vntvertodo.h"
#include <stdio.h>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Titulos para la tabla en la pestania Alquilar
    QStringList titulosAlquilar;
    titulosAlquilar << "Nombre" << "Aforo" << "Precio" << "Estado";
    ui->tablaAlquilar->setColumnCount(4);
    ui->tablaAlquilar->setHorizontalHeaderLabels(titulosAlquilar);
    ui->tablaAlquilar->setColumnWidth(0, 360);
    ui->tablaAlquilar->setColumnWidth(1, 50);
    ui->tablaAlquilar->setColumnWidth(2, 50);
    ui->tablaAlquilar->setColumnWidth(3, 90);

    //Titulos para la tabla en la pestania Procesos
    QStringList titulosProcesos;
    titulosProcesos << "Nombre";
    ui->tablaProceso->setColumnCount(1);
    ui->tablaProceso->setHorizontalHeaderLabels(titulosProcesos);
    ui->tablaProceso->setColumnWidth(0, 500);

    //items
    QStringList items;
    items << "Auditorio" << "Cancha_deportiva" << "Centro_de_esparcimiento"
          << "Estadio" << "Laboratorio" << "Sala_de_conferencia" << "Sala_de_cómputo"
          << "Salón_de_baile" << "Salón_multimedia";
    ui->tipoEventoAgregar->addItems(items);
    ui->tipoEventoAlquilar->addItems(items);
    ui->tipoEventoProceso->addItems(items);
    ui->tipoEventoReporte->addItems(items);

    //Hora y fecha alquilar
    ui->fechaAlquilar->setDate(QDate::currentDate());
    ui->horaAlquilar->setTime(QTime::currentTime());

    //fecha reportes
    ui->fechaReportes->setDate(QDate::currentDate());

    //cargo el archivos
    cargarArchivo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//--------MODULO GUARDAR-----------------
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
        if (listaEvento.buscarPorNombre(eventoAux.getNombre())){
            QMessageBox::warning(this, "", "El nombre ingresado ya está en uso");
        } else if (eventoAux.getAforo() <= 0 || eventoAux.getArea() <= 0 ||
                   eventoAux.getCosto() <= 0 || eventoAux.getPiso() <= 0 ||
                   eventoAux.getPiso() >= 10){
            QMessageBox::warning(this, "", "Ingrese un número válido");
        }else {
            listaEvento.inserta(eventoAux);
        }

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

//--------MODULO ACTUALIZAR/ELIMINAR-----------------
void MainWindow::on_btnBuscarProceso_clicked()
{
    //Borrar todas las filas
    int filas = ui->tablaProceso->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaProceso->removeRow(i);
    }

    QString tipo = ui->tipoEventoProceso->itemText(ui->tipoEventoProceso->currentIndex());
    QStringList nombresAux = listaEvento.buscarPorTipo(tipo);

    if (nombresAux.length() > 0){
        for (int i = 0; i < nombresAux.length(); i++) {
            //Creo una fila al final de la tabla
            ui->tablaProceso->insertRow(ui->tablaProceso->rowCount());
            //inserto elementos en la fila creada
            ui->tablaProceso->setItem(ui->tablaProceso->rowCount() - 1, 0,
                                       new QTableWidgetItem(nombresAux[i]));
        }
    } else {
        QMessageBox::information(this, "", "No hay eventos de ese tipo registrados");
    }

}
//--------PROCESO ELIMINAR-----------------


void MainWindow::on_btnEliminar_clicked()
{
    //Obetengo un valor numero que me indica si una fila esta selecionada
    //Devuelve -1 si no hay nada seleccionado
    int seleccion = ui->tablaProceso->currentRow();

    //Verifico si una fila esta seleccionada
    if ( seleccion > -1){
        if (QMessageBox::question(this, "", "¿Estás seguro de eliminar?") == QMessageBox::Yes){
            //obtengo el nombre de la fila ha eliminar
            int fila = ui->tablaProceso->currentRow();
            QString nombre = ui->tablaProceso->item(fila,0)->text();
            listaEvento.eliminarPorNombre(nombre);
            QMessageBox::information(this, "", "Eliminado con éxito");
        }

    } else {
        QMessageBox::warning(this, "", "Seleccione un evento");
    }

    //Borra todas las filas
    int filas = ui->tablaProceso->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaProceso->removeRow(i);
    }
}

//--------MODULO ACTUALIZAR-----------------

void MainWindow::on_btnActualizar_clicked()
{
    int seleccion = ui->tablaProceso->currentRow();
    Evento evento;
    if ( seleccion > -1){
        int fila = ui->tablaProceso->currentRow();
        QString nombre = ui->tablaProceso->item(fila,0)->text();
        evento = listaEvento.getEventoPorNombre(nombre);
        VntActualizar ventana(this);
        ventana.mostrar(evento);
        ventana.exec();
        evento = ventana.getEvento();
        if (evento.getNombre() == "" || evento.getAforo() == 0 || evento.getArea() == 0
                || evento.getCosto() == 0 || evento.getDireccion() == "" || evento.getPiso() == 0)
            return;
        listaEvento.actualizarDatos(nombre, evento);
        QMessageBox::information(this, "", "Se actualizaron los datos");
    }else {
        QMessageBox::warning(this, "", "Seleccione un evento");
    }
    //Borra todas las filas
    int filas = ui->tablaProceso->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaProceso->removeRow(i);
    }
}

//--------MODULO ALQUILAR-----------------
void MainWindow::on_btnBuscarAlquilar_clicked()
{
    //Borra todas las filas
    int filas = ui->tablaAlquilar->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaAlquilar->removeRow(i);
    }

    ListaEventos listaAux;
    ListaEventos listaAux2;

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
        listaAux2 = listaEvento.buscarNoDisponibilidad(tipo,auxDis);
        if(listaAux.getTotal() == 0 && listaAux2.getTotal() == 0){
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
                ui->tablaAlquilar->setItem(ui->tablaAlquilar->rowCount() - 1, 3,
                                           new QTableWidgetItem("Disponible"));
                aux =  aux->getSiguiente();
            }

            aux = listaAux2.getCabecera();
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
                ui->tablaAlquilar->setItem(ui->tablaAlquilar->rowCount() - 1, 3,
                                           new QTableWidgetItem("No disponible"));
                aux =  aux->getSiguiente();
            }
        }
    }
}

void MainWindow::on_btnVerMasAlquilar_clicked()
{
    int seleccion = ui->tablaAlquilar->currentRow();
    NodoEvento *auxNodoEvento;
    if ( seleccion > -1){
        verMas *ventana = new verMas;
        ventana->setModal(true);
        ventana->show();
        int fila = ui->tablaAlquilar->currentRow();
        QString nombre = ui->tablaAlquilar->item(fila,0)->text();

        auxNodoEvento = listaEvento.getNodoEvento(nombre);
        ventana->mostrarEvento(auxNodoEvento);
    }
}


void MainWindow::on_btnAlquilar_clicked()
{
    int seleccion = ui->tablaAlquilar->currentRow();

    if ( seleccion > -1){
        //Obtengo los datos de la interfaz Alquilar
        QString tipo = ui->tipoEventoAlquilar->itemText(ui->tipoEventoAlquilar->currentIndex());
        QDate fecha = ui->fechaAlquilar->date();
        QTime horaInicio = ui->horaAlquilar->time();
        int horas = ui->tiempoAlquilar->text().toInt();
        QTime horaFin = horaInicio.addSecs(horas*3600);

        Disponibilidad disponibilidad(fecha, horaInicio, horaFin, horas);

        int fila = ui->tablaAlquilar->currentRow();
        QString nombre = ui->tablaAlquilar->item(fila,0)->text();
        QString estado = ui->tablaAlquilar->item(fila,3)->text();

        if (estado == "Disponible"){
            listaEvento.insertarDisponibilidad(nombre, disponibilidad);
            QMessageBox::information(this, "", "Operacion terminada con exito");
        } else {
            QMessageBox::critical(this, "", "El evento seleccionado no esta disponible");
        }

        //Borra todas las filas
        int filas = ui->tablaAlquilar->rowCount();
        for (int i = filas - 1; i >= 0; i--) {
            ui->tablaAlquilar->removeRow(i);
        }

    }
}

//--------MODULO REPORTES-----------------
void MainWindow::on_btnMostrarTodo_clicked()
{
    //Borrar todas las filas
    int filas = ui->tablaReportes->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaReportes->removeRow(i);
    }

    NodoEvento *aux = listaEvento.getCabecera();

    if (aux != NULL){
        //Titulos para la tabla en la pestania Alquilar
        QStringList titulosReportes;

        int validacion = 0;
        while (aux != NULL) {
            titulosReportes  << "Nombre";
            //Creo una fila al final de la tabla
            ui->tablaReportes->insertRow(ui->tablaReportes->rowCount());

            if (ui->cbTIpo->isChecked() || ui->cbAforo->isChecked() || ui->cbArea->isChecked()
                    || ui->cbDireccin->isChecked() || ui->cbPiso->isChecked() || ui->cbPrecio->isChecked()){
                if (ui->cbTIpo->isChecked() ){
                    if (validacion == 0){
                        titulosReportes  << "Tipo";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                              new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Tipo"),
                                               new QTableWidgetItem(aux->getEvento().getTipo()));
                }
                if (ui->cbAforo->isChecked()){
                    if (validacion == 0){
                        titulosReportes  << "Aforo";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                              new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Aforo"),
                                               new QTableWidgetItem(QString::number(aux->getEvento().getAforo())));
                }
                if (ui->cbArea->isChecked()){
                    if (validacion == 0){
                        titulosReportes  << "Area";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                               new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Area"),
                                               new QTableWidgetItem(QString::number(aux->getEvento().getArea())));
                }
                if (ui->cbDireccin->isChecked()){
                    if (validacion == 0){
                        titulosReportes  << "Dirección";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                               new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Dirección"),
                                               new QTableWidgetItem(aux->getEvento().getDireccion()));
                }
                if (ui->cbPiso->isChecked()){
                    if (validacion == 0){
                        titulosReportes  << "Piso";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                               new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Piso"),
                                               new QTableWidgetItem(QString::number(aux->getEvento().getPiso())));
                }
                if (ui->cbPrecio->isChecked()){
                    if (validacion == 0){
                        titulosReportes  << "Precio";
                        ui->tablaReportes->setColumnCount(titulosReportes.count());
                        ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                    }
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                               new QTableWidgetItem(aux->getEvento().getNombre()));
                    ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Precio"),
                                               new QTableWidgetItem(QString::number(aux->getEvento().getCosto())));
                }
                validacion++;
            } else{
                if (validacion == 0){
                    titulosReportes  << "Tipo" << "Dirección" << "Aforo" << "Area" << "Piso" << "Precio";
                    ui->tablaReportes->setColumnCount(titulosReportes.count());
                    ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);
                }

                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                          new QTableWidgetItem(aux->getEvento().getNombre()));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Tipo"),
                                           new QTableWidgetItem(aux->getEvento().getTipo()));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Dirección"),
                                          new QTableWidgetItem(aux->getEvento().getDireccion()));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Aforo"),
                                          new QTableWidgetItem(QString::number(aux->getEvento().getAforo())));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Area"),
                                          new QTableWidgetItem(QString::number(aux->getEvento().getArea())));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Piso"),
                                          new QTableWidgetItem(QString::number(aux->getEvento().getPiso())));
                ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, titulosReportes.indexOf("Precio"),
                                          new QTableWidgetItem(QString::number(aux->getEvento().getCosto())));
            }
            validacion++;
            aux = aux->getSiguiente();
        }
    } else {
        QMessageBox::information(this, "", "No hay eventos registrados");
    }
}

void MainWindow::on_btnMostrarTodoEventos_clicked()
{
    //Borrar todas las filas
    int filas = ui->tablaReportes->rowCount();
    for (int i = filas - 1; i >= 0; i--) {
        ui->tablaReportes->removeRow(i);
    }

    QStringList titulosReportes;
    titulosReportes << "Tipo" << "Nombre" << "Total de horas" << "Dinero recaudado";
    ui->tablaReportes->setColumnCount(titulosReportes.count());
    ui->tablaReportes->setHorizontalHeaderLabels(titulosReportes);

    QString tipo = ui->tipoEventoReporte->itemText(ui->tipoEventoReporte->currentIndex());
    QDate fecha = ui->fechaReportes->date();

    int totalHoras;
    float dineroRecaudado;

    NodoEvento *aux = listaEvento.getCabecera();
    while (aux != NULL) {
        totalHoras = 0;
        for (int i = 0; i < aux->getListaDisponibilidad().getN(); i++){
            if (ui->cbFecha->isChecked()){
                if (fecha <= aux->getListaDisponibilidad().getDisponibilidad()[i].getFechaEvento()){
                    totalHoras += aux->getListaDisponibilidad().getDisponibilidad()[i].getHoras();
                }
            } else {
                totalHoras += aux->getListaDisponibilidad().getDisponibilidad()[i].getHoras();
            }
        }

        dineroRecaudado = totalHoras * aux->getEvento().getCosto();

        if (ui->cbTipoEventos->isChecked() == true && tipo != aux->getEvento().getTipo()){
            aux = aux->getSiguiente();
            continue;
        }

        //Creo una fila al final de la tabla
        ui->tablaReportes->insertRow(ui->tablaReportes->rowCount());
        //inserto elementos en la fila creada
        ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 0,
                                   new QTableWidgetItem(aux->getEvento().getTipo()));
        ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 1,
                                   new QTableWidgetItem(aux->getEvento().getNombre()));
        ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 2,
                                   new QTableWidgetItem(QString::number(totalHoras)));
        ui->tablaReportes->setItem(ui->tablaReportes->rowCount() - 1, 3,
                                   new QTableWidgetItem(QString::number(dineroRecaudado)));

        aux = aux->getSiguiente();
    }
}

void MainWindow::on_btnVerTodo_clicked()
{
    int seleccion = ui->tablaReportes->currentRow();
    NodoEvento *auxNodoEvento;
    if ( seleccion > -1){
        int fila = ui->tablaReportes->currentRow();
        QString nombre = ui->tablaReportes->item(fila,0)->text();
        auxNodoEvento = listaEvento.getNodoEvento(nombre);
        VntVerTodo *ventana = new VntVerTodo;
        ventana->setModal(true);
        ventana->mostrarEvento(auxNodoEvento);
        ventana->show();
    }
}


//--------PESTAÑAS-----------------
void MainWindow::on_actionAgregar_nuevo_Tipo_triggered()
{
    QString nuevoItems ;
    QString itemAux;
    QStringList items;
    QStringList itemsAux;
    int fila, accion;
    //obtengo todos los items
    for (int i = 0; i < ui->tipoEventoAgregar->count(); i++) {
        itemAux = ui->tipoEventoAgregar->itemText(i);
        itemsAux << itemAux;
    }
    VtnAgregarItems ventana(this);
    ventana.mostrar(itemsAux);
    ventana.exec();
    nuevoItems = ventana.getItem();
    fila = ventana.getFila();
    accion = ventana.getAccion();
    if (nuevoItems != "" && accion == 0){
        items << nuevoItems;
        ui->tipoEventoAgregar->addItems(items);
        ui->tipoEventoAlquilar->addItems(items);
        ui->tipoEventoProceso->addItems(items);
        ui->tipoEventoReporte->addItems(items);
    }

    if (fila >= 0 && accion == 1 && nuevoItems != ""){
        ui->tipoEventoAgregar->setItemText(fila, nuevoItems);
        ui->tipoEventoAlquilar->setItemText(fila, nuevoItems);
        ui->tipoEventoProceso->setItemText(fila, nuevoItems);
        ui->tipoEventoReporte->setItemText(fila, nuevoItems);
    }

    if (fila >= 0 && accion == 2){
        ui->tipoEventoAgregar->removeItem(fila);
        ui->tipoEventoAlquilar->removeItem(fila);
        ui->tipoEventoProceso->removeItem(fila);
        ui->tipoEventoReporte->removeItem(fila);
    }
}

void MainWindow::on_actionAcerda_de_triggered()
{
    AcercaDe ventana(this);
    ventana.exec();
}


//--------ARCHIVO-----------------
void MainWindow::cargarArchivo(){
    QByteArray contenido;
    QFile archivo;

    QString linea;
    QString palabra;
    QStringList datos;

    int i = 0;

    Evento evento;

    archivo.setFileName(":/lugares.txt");
    if (!archivo.exists()){
        qDebug() << "El no archivo existe";
    }

    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){
        qDebug() << "el archivo no se ha podido abrir";
    }

    while (i < 10) {
        contenido = archivo.readLine();
        linea.clear();
        datos.clear();
        linea.append(contenido);
        for (int i = 0; i < linea.length() - 1; i++) {
            if (linea[i] == " "){
                datos << palabra;
                palabra.clear();
            } else {
                palabra.append(linea[i]);
            }
        }
        datos << palabra;
        palabra.clear();
        i++;

        evento.setTipo(datos[0]);
        evento.setNombre(datos[1]);
        evento.setDireccion(datos[2]);
        evento.setAforo(datos[3].toInt());
        evento.setArea(datos[4].toFloat());
        evento.setPiso(datos[5].toInt());
        evento.setCosto(datos[6].toFloat());
        listaEvento.inserta(evento);
    }
    archivo.close();
}


