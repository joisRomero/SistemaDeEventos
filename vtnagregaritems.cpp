#include "vtnagregaritems.h"
#include "ui_vtnagregaritems.h"
#include <QMessageBox>

VtnAgregarItems::VtnAgregarItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VtnAgregarItems)
{
    ui->setupUi(this);
}

VtnAgregarItems::~VtnAgregarItems()
{
    delete ui;
}

QString VtnAgregarItems::getItem(){
    return item;
}

void VtnAgregarItems::on_agregar_clicked()
{
    item = ui->item->text();
    if (item == ""){
        QMessageBox::warning(this, "", "Llene todos los campos");
    } else {
        QMessageBox::information(this, "", "Se ha agregado con éxito");
        this->close();
    }
}

void VtnAgregarItems::mostrar(QStringList items){
    itemsAux = items;
    QStringList titulos;
    titulos << "Tipos";
    ui->tabla->setColumnCount(1);
    ui->tabla->setHorizontalHeaderLabels(titulos);
    ui->tabla->setColumnWidth(0, 300);

    for (int i = 0; i < items.count(); i++) {
        ui->tabla->insertRow(ui->tabla->rowCount());
        ui->tabla->setItem(ui->tabla->rowCount() - 1, 0,
                                   new QTableWidgetItem(items[i]));
    }

}


void VtnAgregarItems::on_editar_clicked()
{
    accion = 1;
    fila = ui->tabla->currentRow();

    if(fila < 0){
        QMessageBox::warning(this, "", "No ha hecho una selección");
    }else{
        QString itemModificado = ui->tabla->item(fila,0)->text();
        if (itemModificado == ""){
            QMessageBox::warning(this, "", "No se puedo agregar un texto en blanco");
            //Borra todas las filas
            int cant = ui->tabla->rowCount();
            for (int y = cant - 1; y >= 0; y--) {
                ui->tabla->removeRow(y);
            }
            mostrar(itemsAux);
        } else {
            item = itemModificado;
            QMessageBox::information(this, "", "Se ha modificado con éxito");
            this->close();
        }
    }

}

void VtnAgregarItems::on_eliminar_clicked()
{
    accion = 2;
    fila = ui->tabla->currentRow();
    if(fila < 0){
        QMessageBox::warning(this, "", "No ha hecho una selección");
    } else {
        if (QMessageBox::question(this, "", "¿Estás seguro de eliminar?") == QMessageBox::Yes){
            QMessageBox::information(this, "", "Se ha elinado con éxito");
            this->close();
        }
    }
}
