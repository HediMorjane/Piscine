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
void Point::setColor(int color)
{
    m_color=color;
}
void Point::addAdjBfs(Point* point)
{

    m_pointadj.push_back(point);


}

std::vector<Point*> Point::getAdjacent()
{
    return m_pointadj;
}
void Point::BFS()
{
    std::queue<Point*> file;

    file.push(this);
    m_color=2;

    while(!file.empty())
    {
        for(size_t i=0; i<file.front()->m_pointadj.size(); i++)
        {

            if (file.front()->m_pointadj[i]->m_color==0)
            {

                file.front()->m_pointadj[i]->m_color=2;
                file.push(file.front()->m_pointadj[i]);

                file.front()->m_pointadj[i]->m_successeur.push_back(file.front());

            }

        }

        file.pop();

    }
}
void Point::afficherBfs(int point)
{
    if (m_successeur.empty() && point!=m_indice)


        std::cout<<"inatteignable";
    else
        for(size_t i=0; i <m_successeur.size(); i++)
        {
            std::cout<<"<---"<<m_successeur[i]->m_indice;
            m_successeur[i]->afficherBfs(point);
        }
}

void Point::afficherAdja()
{
    std::cout<<m_pointadj.size()<<std::endl;
    for (size_t i=0; i< m_pointadj.size(); i++)
    {
        std::cout<<" "<<m_pointadj[i]->getindice();
    }
}
void Point::afficher() const
{
    std::cout<<" "<<m_indice<<" "<<m_nom<<" "<<m_altitude;

}
