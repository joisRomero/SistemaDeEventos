#ifndef VERMAS_H
#define VERMAS_H

#include <QDialog>
#include "evento.h"
#include "nodoevento.h"

namespace Ui {
class verMas;
}

class verMas : public QDialog
{
    Q_OBJECT

public:
    explicit verMas(QWidget *parent = nullptr);
    ~verMas();
    void mostrarEvento(NodoEvento*);

private slots:
    void on_btnOk_clicked();

private:
    Ui::verMas *ui;
};

#endif // VERMAS_H
