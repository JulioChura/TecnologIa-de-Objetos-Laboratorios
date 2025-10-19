#ifndef PAIS_H
#define PAIS_H

#include <QString>

class Pais
{
public:
    Pais(const QString &nombre = "", const QString &capital = "",
         const QString &idioma = "", const QString &foto = "");

    QString getNombre() const;
    QString getCapital() const;
    QString getIdioma() const;
    QString getFoto() const;

private:
    QString m_nombre;
    QString m_capital;
    QString m_idioma;
    QString m_foto;
};

#endif // PAIS_H
