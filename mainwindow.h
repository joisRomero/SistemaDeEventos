#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaeventos.h"
#include "listadisponibilidad.h"

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

    void on_btnBuscarEliminar_clicked();

    void on_btnEliminar_clicked();

    void on_btnBuscarActualizar_clicked();

    void on_btnBuscarAlquilar_clicked();

    void on_btnAlquilar_clicked();

    void on_btnSeleccionarActualizar_clicked();

    void on_btnActualizar_clicked();

private:
    Ui::MainWindow *ui;
    ListaEventos listaEvento;
    QString nombreAux;

};
#endif // MAINWINDOW_H
