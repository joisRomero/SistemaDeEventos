#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaeventos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnVerMasAlquilar_clicked();

    void on_btnGuardarAgregar_clicked();

private:
    Ui::MainWindow *ui;
    ListaEventos listaEvento;

};
#endif // MAINWINDOW_H
