#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "pais.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPaisSeleccionado(const QModelIndex &index);

private:
    void cargarNombresPaises();
    void configurarConexiones();
    void cargarDatosCompletos();

    Ui::MainWindow *ui;
    QList<Pais> m_listaPaises;
};

#endif // MAINWINDOW_H
