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
        m_points[i]->setColor(0);
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


        /// ajoutez set temps


    }
    for(unsigned int i=0; i<m_points.size();i++)
    {
        std::vector<int> tamp;


      tamp= rechercheAdj(i+1);

       for (unsigned int j=0;j<tamp.size();j++)
       {   /// std::cout<<"tamp  : "<<tamp[j]<<std::endl;

        //   std::cout<<"POINT ADJ  :  "<<m_points[tamp[j]-1]->getindice();
          m_points[i]->addAdjBfs(m_points[tamp[j]-1]);///pb aussi ici

          /// std::cout<<"POINT ADJ  :  "<<m_pointadj[j]->getindice();

                /*for(size_t t=0; t<m_points.size();t++)
            {


        m_points[t]->afficherAdja();}*/
       }

          // m_points[i]->afficherAdja();

       }

    /// appel boucle for des points pour associé les adjs  :utilisation de rechercheADJ
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


std::vector<int> Station::rechercheAdj(int indice)
{
    std::vector<int> indicePoint;
    std::string TampNom;
    std::pair<std::vector <Trajet*>, std::vector<Trajet*> > trajetSelected;

    TampNom=m_points[indice-1]->getNomLieu();
    trajetSelected= afficherTrajet(TampNom);

    for (unsigned int i=0; i<trajetSelected.first.size(); i++)
    {

        indicePoint.push_back(trajetSelected.first[i]->getNumArrive() );
    }

     for (unsigned int i=0; i<trajetSelected.second.size(); i++)
    {

        indicePoint.push_back(trajetSelected.second[i]->getNumDepart() );


    }

    return indicePoint;

}


void Station::afficherBfs(int point)
{
    for (size_t i=0; i<m_points.size();i++)
    {
        std::cout<<std::endl<<m_points[i]->getindice();
        m_points[i]->afficherBfs(point);
    }
}
void Station::ParcoursBfs()
{
    std::cout<<std::endl<<"Par quel sommet voulez-vous debuter le parcours ? "<<std::endl;
    int point = -1;
    while(point<0 || point>=m_ordre+1)
        std::cin>>point;
    m_points[point-1]->BFS();


    afficherBfs(point);
}

