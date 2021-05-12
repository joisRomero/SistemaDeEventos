#ifndef VERMAS_H
#define VERMAS_H

#include <QDialog>
#include "evento.h"

namespace Ui {
class verMas;
}

class verMas : public QDialog
{
    Q_OBJECT

public:
    explicit verMas(QWidget *parent = nullptr);
    ~verMas();
    void mostrarEvento(Evento);

private slots:
    void on_btnOk_clicked();

private:
    Ui::verMas *ui;
};

#endif // VERMAS_H
