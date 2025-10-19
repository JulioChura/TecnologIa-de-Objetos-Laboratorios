#include "pais.h"

Pais::Pais(const QString &nombre, const QString &capital,
           const QString &idioma, const QString &foto)
    : m_nombre(nombre), m_capital(capital), m_idioma(idioma), m_foto(foto)
{
}

QString Pais::getNombre() const { return m_nombre; }
QString Pais::getCapital() const { return m_capital; }
QString Pais::getIdioma() const { return m_idioma; }
QString Pais::getFoto() const { return m_foto; }
