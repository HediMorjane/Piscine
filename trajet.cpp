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

int Trajet::getindice() const
{
    return m_indice;
}
int Trajet::get_num_depart()
{
    return m_trajet.first->getindice();
}
int Trajet::get_num_arrive()
{
    return m_trajet.second->getindice();
}

std::string Trajet::get_nom_trajet()
{
    return m_nom_trajet;
}
std::string Trajet::get_type()
{
    return m_type;
}
void Trajet::set_nom_trajet(std::string nom_trajet)
{
    m_nom_trajet=nom_trajet;
}
void Trajet::set_type(std::string type)
{
    m_type=type;
}
std::pair< Point*, Point*>& Trajet::gettrajet()
{
    return m_trajet;
}
void Trajet::settemps(float temps)
{
    /*switch(type)
    {
    case V:
        m_temps= (300*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case B:
        m_temps= (240*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case R:
        m_temps=  (180*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
       break;
    case N:
        m_temps= (120*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case KL:
            m_temps= (10*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case SURF:
        m_temps= (600*(m_trajet.first->getAltitude - m_trajet.second->getAltitude))/100;
        break;
    case TPH:
        m_temps = (120*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+240;
        break;
    case TC:
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+120;
        break;
    case TSD:
        m_temps = (180*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case TS:
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case TK:
        m_temps = (240*(m_trajet.second->getAltitude - m_trajet.first->getAltitude)/100)+60;
        break;
    case BUS:
        if (m_indice == 58 || 59)
        {
            m_temps= 1800
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
