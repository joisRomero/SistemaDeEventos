#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listaeventos.h"
#include "listadisponibilidad.h"
#include "vntactualizar.h"

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

    void on_btnEliminar_clicked();

    void on_btnBuscarAlquilar_clicked();

    void on_btnAlquilar_clicked();

    void on_btnActualizar_clicked();

    void on_btnBuscarProceso_clicked();


    void on_actionAgregar_nuevo_Tipo_triggered();

    void on_btnMostrarTodo_clicked();

private:
    Ui::MainWindow *ui;
    ListaEventos listaEvento;

};
#endif // MAINWINDOW_H
