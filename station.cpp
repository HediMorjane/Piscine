#include "station.h"


Station::Station(std::string nomFichier)
{
      loadGraph(nomFichier);
    /*std::ifstream ifs{nomFichier};
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
       {


          m_points[i]->addAdjBfs(m_points[tamp[j]-1]);





       }
}*/
}

void Station::loadGraph(std::string nomFichier){
    //lecture du fichier
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    //on récupere le nombre de point (m_ordre)
    ifs >> m_ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");

    //on initialise le tableau comportant tt les points (m_points)
    for (int i=0; i<m_ordre; i++) {
        m_points.push_back( new Point{i+1});
    }


    int indice,altitude;
    std::string nom;
    //on ajoute tous les points au tableau m_points
    for(int i=0; i<m_ordre; i++)
    {
        ifs>>indice>> nom >> altitude;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme indice du graphe");
        m_points[i]->setNomLieu(nom);
        m_points[i]->setAltitude(altitude);
        m_points[i]->setColor(0);
    }

    //on récupere le nombre de trajet (taille)
    int taille;
    ifs >> taille;

    int node1,node2, indice_trajet;
    std::string nom_trajet,type;
    //on ajoute tout les trajets au tableau (m_trajets)
    for (int i=0; i<taille; ++i)
    {
        ifs>>indice_trajet>> nom_trajet>> type>> node1>> node2;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme indice du graphe");
        m_trajets.push_back( new Trajet{indice_trajet, node1,node2});
        std::pair<Point*,Point*> m_trajetGiven;
        m_trajetGiven.first = m_points[node1-1];
        m_trajetGiven.second = m_points[node2-1];
        m_trajets[i]->setPointTrajet(m_trajetGiven);
        m_trajets[i]->setNomTrajet(nom_trajet);
        m_trajets[i]->setType(type);
        m_trajets[i]->setTemps(type);

    }

    //une fois les trajets trouvé on ajoute au tableau point les points adjacents
    for(unsigned int i=0; i<m_points.size();i++)
    {
        std::vector<int> tamp;
        tamp= rechercheAdj(i+1);

       for (unsigned int j=0;j<tamp.size();j++)
       {
          m_points[i]->addAdjBfs(m_points[tamp[j]-1]);
       }
       }
}




void Station::afficherGraph()
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
    sommetSelected.first = new Point(-1);
    sommetSelected.second = new Point(-1);

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
    std::cout<<std::endl<<"1  : Plus court chemin entre deux points ?"<<std::endl<<"2: entre 1 point et les autres? "<<std::endl;
    int choix;
    std::cin>>choix;
    if (choix == 1)
    {
        int si, sf;
        std::cout<<std::endl<<"Par quel sommet voulez-vous debuter le parcours ? "<<std::endl;
        do{
        std::cin>>si;}
         while(si<0 || si>=m_ordre+1);

        std::cout<<std::endl<<"Par quel sommet voulez-vous finir le parcours ? "<<std::endl;
        do{std::cin>>sf;}
        while(sf<0 || sf>=m_ordre+1);

        m_points[si-1]->BFS();
        std::cout<<std::endl<<m_points[sf-1]->getindice();
        m_points[sf-1]->afficherBfs(si);

    }

    else if (choix==2){
    std::cout<<std::endl<<"Par quel sommet voulez-vous debuter le parcours ? "<<std::endl;
    int point = -1;
    while(point<0 || point>=m_ordre+1)
        std::cin>>point;
    m_points[point-1]->BFS();



    afficherBfs(point);}
}

void Station::reinitialiser()
{
    for(size_t i=0;i<m_points.size();i++)
        m_points[i]->reinitialiser();
}
std::vector<Point*>& Station::getTabPoints()
{
        return m_points;
}

std::vector< Trajet*>& Station::getTabTrajets()
{
    return m_trajets;
}

int Station::isPointExistByName(std::string name) {
    int index = -1;

    for(unsigned int i=0; i<m_points.size();i++) {
        if(name == m_points[i]->getNomLieu()) {
            index = m_points[i]->getindice();
        }
    }
    return index;
}
int Station::isTrajetExistByName(std::string name) {
    int index = -1;

    for(unsigned int i=0; i<m_trajets.size();i++) {
        if(name == m_trajets[i]->getNomTrajet()) {
            index = m_trajets[i]->getIndice();
        }
    }
    return index;
}
