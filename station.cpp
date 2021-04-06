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
        m_trajets[i]->set_nom_trajet(nom_trajet);
        m_trajets[i]->set_type(type);
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
