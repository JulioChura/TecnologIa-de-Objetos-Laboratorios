#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList colores;
    colores << "Rojo" << "Verde" << "Azul" << "Amarillo"
            << "Morado" << "Naranja" << "Rosa" << "Gris";

    ui->cmbColores->addItems(colores);
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->cmbColores->model());
    if (model) {
        for (int i = 0; i < model->rowCount(); ++i) {
            QStandardItem *item = model->item(i);
            if (item)
                item->setTextAlignment(Qt::AlignCenter);
        }
    }

    ui->lblMensaje->setStyleSheet("color: black; font-size: 16pt; font-weight: bold; heigh: 18pt");
    ui->lblMensaje->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmbColores_currentTextChanged(const QString &arg1)
{
    QString mensaje = arg1;
    ui->lblMensaje->setText(mensaje);

    if (arg1 == "Rojo") {
        ui->lblMensaje->setStyleSheet("color: red; font-size: 16pt; font-weight: bold;");
    }
    else if (arg1 == "Verde") {
        ui->lblMensaje->setStyleSheet("color: green; font-size: 16pt; font-weight: bold;");
    }
    else if (arg1 == "Azul") {
        ui->lblMensaje->setStyleSheet("color: blue; font-size: 16pt; font-weight: bold;");
    }
    else if (arg1 == "Amarillo") {
        ui->lblMensaje->setStyleSheet("color: yellow; font-size: 16pt; font-weight: bold;");
    }
    else if (arg1 == "Morado") {
        ui->lblMensaje->setStyleSheet("color: purple; font-size: 16pt; font-weight: bold;");
    }
    else if (arg1 == "Naranja") {
        ui->lblMensaje->setStyleSheet("color: orange; font-size: 16pt; font-weight: bold;");
    }
    else {
        ui->lblMensaje->setStyleSheet("color: black; font-size: 16pt; font-weight: bold;");
    }

    qDebug() <<  arg1;
}
