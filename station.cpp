#include "station.h"


Station::Station(std::string nomFichier)
{
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    for (int i=0; i<m_ordre; i++)
        m_points.push_back( new Point{i+1});
    int indice;
    std::string nom;
    int altitude;
    for(int i=0; i<m_ordre; i++)
    {
        ifs>>indice>> nom >> altitude;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme indice du graphe");
        m_points[i]->setNomLieu(nom);
        m_points[i]->setAltitude(altitude);
    }
    int taille;
    ifs >> taille;
    int node1,node2, indice_trajet;
    std::string nom_trajet, type;
    for (int i=0; i<taille; ++i)
    {
        ifs>>indice_trajet>>nom_trajet>>type>>node1>>node2;

        m_trajets.push_back( new Trajet{indice_trajet, node1,node2});
        m_trajets[i]->setNomTrajet(nom_trajet);
        m_trajets[i]->setType(type);
    }
}

void Station::afficher()
{
    std::cout<<"ordre = "<<m_points.size()<<std::endl<<"  ";

    for (auto s : m_points)
    {
        std::cout<<"points";
        s->afficher();
        std::cout<<std::endl;
    }

    std::cout<<"taille = "<<m_trajets.size()<<std::endl;
    for (auto s : m_trajets)
    {
        std::cout<<"trajets ";
        s->afficher();
        std::cout<<std::endl;
    }
}

Station::~Station()
{

}
std::pair<Point*,Point*> Station::afficherSommet(std::string nom)
{
    std::pair<Point*,Point*> sommetSelected;

    for (unsigned int i=0; i<m_trajets.size(); i++)
    {
        std::string tampName;

        tampName=m_trajets[i]->getNomTrajet();
        if(nom == tampName)
        {

            sommetSelected=m_trajets[i]->gettrajet();
            break;

        }
    }
    return sommetSelected;
}
/*std::pair<Trajet*, Trajet*> Station::afficherTrajet(std::string nom)
{
    std::pair<Trajet*, Trajet*> trajetSelected;
    for (unsigned int i=0; i<m_points.size();i++)
    {
        std::string tampNom;
        tampNom=m_points[i]->getNomLieu();
        if (nom == tampNom)
        {
            int x;
            x = m_points[i]->getindice();
            for (unsigned int j=0; j<m_trajets.size(); j++)
            {
                if (m_trajets[j]->getNumDepart() == x)
                {
                    trajetSelected.first.push_back ( m_trajets[j]);
                }
                else if (m_trajets[j]->getNumArrive() == x)
                {
                    trajetSelected.second.push_back ( m_trajets[j]);
                }
            }

            break;

        }
    }

    return trajetSelected;
}
*/


std::pair<std::vector <Trajet*>, std::vector<Trajet*>>Station::afficherTrajet(std::string nom)
{
    std::pair<std::vector <Trajet*>, std::vector<Trajet*> > trajetSelected;
    for (unsigned int i=0; i<m_points.size(); i++)
    {
        std::string tampNom;

        tampNom=m_points[i]->getNomLieu();
        if (nom == tampNom)
        {
            int x;
            x = m_points[i]->getindice();
            for (unsigned int j=0; j<m_trajets.size(); j++)
            {
                if (m_trajets[j]->getNumDepart() == x)
                {
                    trajetSelected.first.push_back ( m_trajets[j]);

                }
                else if (m_trajets[j]->getNumArrive() == x)
                {
                    trajetSelected.second.push_back ( m_trajets[j]);

                }
            }

            break;

        }
    }

    return trajetSelected;
}

