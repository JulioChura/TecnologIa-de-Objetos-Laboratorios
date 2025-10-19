#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << " EJEMPLO DE QVector ";
    QVector<int> numeros;
    numeros << 10 << 20 << 30 << 40;
    numeros.append(50);
    numeros.insert(2, 25);

    qDebug() << "Contenido del QVector:";
    for (int num : numeros) {
        qDebug() << num;
    }

    qDebug() << "Tamaño del QVector:" << numeros.size();
    qDebug() << "Elemento en posición 3:" << numeros.at(3);
    qDebug() << "----------------------------------\n";


    qDebug() << " EJEMPLO DE QList ";
    QList<QString> nombres;
    nombres << "Ana" << "Luis" << "Carlos";
    nombres.append("María");
    nombres.insert(1, "Pedro");
    nombres.removeAt(2);

    qDebug() << "Contenido del QList:";
    for (const QString &nombre : nombres) {
        qDebug() << nombre;
    }

    qDebug() << "Tamaño del QList:" << nombres.size();
    qDebug() << "Primer elemento:" << nombres.first();
    qDebug() << "Último elemento:" << nombres.last();
    qDebug() << "----------------------------------\n";


    return a.exec();
}
