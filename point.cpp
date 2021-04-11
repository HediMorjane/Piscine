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
void Point::addAdjBfs(Point* point,std::string type)
{
    std::pair<Point*,std::string> data;
    data.first=point;
    data.second = type;
    m_pointadj.push_back(data);

}

void Point::addAdjDijsktra(Point* point,PointInfoTrajet* pointInfo)
{

    std::pair<Point*,PointInfoTrajet*> paire(point,pointInfo);
    std:: string type = pointInfo->getPointInfoType();
    if( type.compare("S") == 0 )
    {
        point_adj.push_back(paire);
    }

}

std::vector<std::pair<Point*,std::string>> Point::getAdjacent()
{
    return m_pointadj;/// sert a rien ?
}
void Point::init(unsigned int point)
{
    m_temps=100000;
    if(m_indice==point)
        m_temps=0;
}
float Point::getTemps()
{
    return m_temps;
}
void Point::Dijsktra(std::vector<Point*> sousgraphe)
{
    int cpt=0;
    for(size_t i=0; i<point_adj.size(); i++)
    {
        for(size_t j=0; j<sousgraphe.size(); j++)
        {
            if(sousgraphe[j]->getindice() == point_adj[i].first->getindice())
                cpt++;
        }
        if (cpt== 0 && point_adj[i].first->m_temps> m_temps + point_adj[i].second->getPointInfoTemps())
        {
            point_adj[i].first->m_temps= m_temps+ point_adj[i].second->getPointInfoTemps();
            point_adj[i].first->point_predecesseur=this;
        }
        cpt=0;



    }
}
void Point::afficherDijkstra()
{
    if(point_predecesseur!=nullptr)
    {
        std::cout<<m_indice <<" <-- ";
        point_predecesseur->afficherDijkstra();

    }
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

            if (file.front()->m_pointadj[i].first->m_color==0)
            {
                std:: string type = file.front()->m_pointadj[i].second;
                if( type.compare("S") == 0 )
                {
                    file.front()->m_pointadj[i].first->m_color=2;
                    file.push(file.front()->m_pointadj[i].first);
                    file.front()->m_pointadj[i].first->m_successeur.push_back(file.front());
                }

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

    for (size_t i=0; i< point_adj.size(); i++)
    {
        std::cout<<" "<<point_adj[i].first->getindice()<<" temps: "<<point_adj[i].second;
    }
}
void Point::afficher() const
{
    std::cout<<" "<<m_indice<<" "<<m_nom<<" "<<m_altitude;

}
void Point::reinitialiser()
{
    m_color =0;
    m_successeur.clear();
    m_temps=0;
    point_predecesseur=nullptr;
}
