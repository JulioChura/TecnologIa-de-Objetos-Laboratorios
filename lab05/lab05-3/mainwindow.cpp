#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "pais.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QPixmap>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_listaPaises()
{
    ui->setupUi(this);

    cargarDatosCompletos();
    cargarNombresPaises();
    configurarConexiones();

    ui->paisFoto->setScaledContents(true);
    ui->paisFoto->setMinimumSize(200, 120);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarDatosCompletos()
{
    m_listaPaises.clear();

    QFile file(":/banderas/banderas/data.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No se pudo abrir data.json";
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray array = doc.array();

    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        m_listaPaises.append(Pais(
            obj["nombre"].toString(),
            obj["capital"].toString(),
            obj["idioma"].toString(),
            obj["foto"].toString()
            ));
    }

    file.close();
    qDebug() << "Datos cargados. Total países:" << m_listaPaises.size();
}

void MainWindow::cargarNombresPaises()
{
    QStringList nombres;
    for (const Pais &pais : m_listaPaises) {
        nombres << pais.getNombre();
    }

    QStringListModel *model = new QStringListModel(nombres, this);
    ui->paises->setModel(model);

    qDebug() << "Nombres cargados en ListView:" << nombres.size();
}

void MainWindow::configurarConexiones()
{
    connect(ui->paises, &QListView::clicked,
            this, &MainWindow::onPaisSeleccionado);
}

void MainWindow::onPaisSeleccionado(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    if (row < 0 || row >= m_listaPaises.size()) return;

    const Pais &pais = m_listaPaises.at(row);

    ui->paisNombre->setText("Nombre del país: " + pais.getNombre());
    ui->paisCapital->setText("Capital: " + pais.getCapital());
    ui->paisIdioma->setText("Idioma: " + pais.getIdioma());


    QPixmap bandera(pais.getFoto());
    if (!bandera.isNull()) {
        ui->paisFoto->setPixmap(bandera);
    } else {
        ui->paisFoto->setText("Bandera no encontrada");
    }

    qDebug() << "País seleccionado:" << pais.getNombre();
}
