#ifndef VTNAGREGARITEMS_H
#define VTNAGREGARITEMS_H

#include <QDialog>

namespace Ui {
class VtnAgregarItems;
}

class VtnAgregarItems : public QDialog
{
    Q_OBJECT

public:
    explicit VtnAgregarItems(QWidget *parent = nullptr);
    ~VtnAgregarItems();
    QString getItem();
    int getFila(){return fila;}
    int getAccion(){return accion;}
    void mostrar(QStringList items);

private slots:
    void on_agregar_clicked();


    void on_editar_clicked();

    void on_eliminar_clicked();

private:
    Ui::VtnAgregarItems *ui;
    QString item;
    int fila;
    int accion = 0;
    QStringList itemsAux;
};

#endif // VTNAGREGARITEMS_H
