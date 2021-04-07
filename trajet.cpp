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
void Trajet::setTemps(float temps)
{
    /*switch(std::string type)
    {
    case "V":
        m_temps= (300*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case "B":
        m_temps= (240*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case "R":
        m_temps=  (180*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
       break;
    case "N":
        m_temps= (120*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case "KL":
            m_temps= (10*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case "SURF":
        m_temps= (600*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case "TPH":
        m_temps = (120*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+240;
        break;
    case "TC":
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+120;
        break;
    case "TSD":
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case "TS":
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case "TK":
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case "BUS":
        if (m_indice == 58 || 59)
        {
            m_temps= 1800;
        }
        else if (m_indice == 60 || 61)
        {
            m_temps= 2400;
        }
        break;


    }*/
}
void Trajet::afficher() const
{
    std::cout<<" "<<m_indice<<" "<< m_nom_trajet<<" "<<m_type<<" "<<m_trajet.first->getindice()<<" "<<m_trajet.second->getindice();

}
