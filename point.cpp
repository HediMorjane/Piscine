#include "point.h"
#include <iostream>

Point::Point(int indice):m_indice{indice}
{

}
Point::~Point()
{

}
int Point::getindice() const
{
    return m_indice;

}

std::string Point::getNomLieu()const
{
    return m_nom;
}
int Point::getAltitude()const
{
    return m_altitude;
}
void Point::setNomLieu(std::string nom)
{
    m_nom=nom;
}
void Point::setAltitude(int altitude)
{
    m_altitude=altitude;
}
void Point::afficher() const
{
    std::cout<<" "<<m_indice<<" "<<m_nom<<" "<<m_altitude;
}
