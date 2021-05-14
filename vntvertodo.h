#ifndef VNTVERTODO_H
#define VNTVERTODO_H

#include <QDialog>
#include "evento.h"
#include "nodoevento.h"

namespace Ui {
class VntVerTodo;
}

class VntVerTodo : public QDialog
{
    Q_OBJECT

public:
    explicit VntVerTodo(QWidget *parent = nullptr);
    ~VntVerTodo();
    void mostrarEvento(NodoEvento*);

private slots:
    void on_btnOk_clicked();

private:
    Ui::VntVerTodo *ui;
};

#endif // VNTVERTODO_H
