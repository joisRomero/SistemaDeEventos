#ifndef VNTACTUALIZAR_H
#define VNTACTUALIZAR_H

#include <QDialog>
#include "evento.h"
#include "nodoevento.h"

namespace Ui {
class VntActualizar;
}

class VntActualizar : public QDialog
{
    Q_OBJECT

public:
    explicit VntActualizar(QWidget *parent = nullptr);
    ~VntActualizar();
    void mostrar(Evento);
    Evento getEvento(){return evento;}
private slots:
    void on_btnActualizar_clicked();

private:
    Ui::VntActualizar *ui;
    Evento evento;

};

#endif // VNTACTUALIZAR_H
