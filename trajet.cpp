#include "trajet.h"

Trajet::Trajet(int indice,int num_depart, int num_arrive)
{
    Point*s1=new Point(num_depart);
    Point*s2=new Point(num_arrive);
    m_trajet.first=s1;
    m_trajet.second=s2;
    m_indice=indice;

}

Trajet::~Trajet()
{

}

int Trajet::getIndice() const
{
    return m_indice;

}
int Trajet::getNumDepart()
{
    return m_trajet.first->getindice();
}
int Trajet::getNumArrive()
{
    return m_trajet.second->getindice();
}

std::string Trajet::getNomTrajet()
{
    return m_nom_trajet;
}
std::string Trajet::getType()
{
    return m_type;
}
float Trajet::getTemps()
{
    return m_temps;
}
void Trajet::setNomTrajet(std::string nom_trajet)
{
    m_nom_trajet=nom_trajet;
}
void Trajet::setType(std::string type)
{
    m_type=type;
}
std::pair< Point*, Point*>& Trajet::gettrajet()
{
    return m_trajet;
}
/*void Trajet::setTemps(const char * str)
{
    switch( hash(str))
    {
    case hash ("V"):
        m_temps= (300*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case hash ("B"):
        m_temps= (240*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case hash ("R"):
        m_temps=  (180*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
       break;
    case hash ("N"):
        m_temps= (120*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case hash("KL"):

            m_temps= (10*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case hash ("SURF"):
        m_temps= (600*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case hash ("TPH"):
        m_temps = (120*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+240;
        break;
    case hash ("TC"):
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+120;
        break;
    case hash ("TSD"):
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case hash ("TS"):
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case hash ("TK"):
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case hash ("BUS"):
        if (m_indice == 58 || 59)
        {
            m_temps= 1800;
        }
        else if (m_indice == 60 || 61)
        {
            m_temps= 2400;
        }
        break;
    default:
        std::cout << "wut?" << std::endl;
     break;


    }
}*/
void Trajet::afficher() const
{
    std::cout<<" "<<m_indice<<" "<< m_nom_trajet<<" "<<m_type<<" "<<m_trajet.first->getindice()<<" "<<m_trajet.second->getindice();

}
