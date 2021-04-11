#include "station.h"


Station::Station(std::string nomFichier)
{
      loadGraph(nomFichier);

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
        m_trajets.push_back( new Trajet{indice_trajet});
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
        std::vector<std::pair <Point*,float >> tamp;
        tamp= rechercheAdj(i+1);

       for (unsigned int j=0;j<tamp.size();j++)
       {
           int index;
           index=tamp[j].first->getindice()-1;
          m_points[i]->addAdjBfs(m_points[index]);
          m_points[i]->addAdjDijsktra(tamp[j].first,tamp[j].second);

       }
       }
        /*for(unsigned int i=0; i<m_points.size();i++)
        {

        std::cout<<"point: " <<m_points[i]->getindice();

            m_points[i]->afficherAdja();
            std::cout<<std::endl;
        }*/

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


std::vector<std::pair <Point*,float>>Station::rechercheAdj(int indice)
{
    std::vector<std::pair <Point*,float >> indicePoint;
    std::string TampNom;
    std::pair<std::vector <Trajet*>, std::vector<Trajet*> > trajetSelected;

    TampNom=m_points[indice-1]->getNomLieu();
    trajetSelected= afficherTrajet(TampNom);

    for (unsigned int i=0; i<trajetSelected.first.size(); i++)
    {
        std::pair<Point*,float> data;
        int indiceArrive = trajetSelected.first[i]->getNumArrive()-1;

        data.first=m_points[indiceArrive];
        data.second=trajetSelected.first[i]->getTemps();
        indicePoint.push_back(data);

    }

     for (unsigned int i=0; i<trajetSelected.second.size(); i++)
    {
        std::pair<Point*,float> data1;
        int indiceDepart = trajetSelected.second[i]->getNumDepart()-1;
        data1.first=m_points[indiceDepart];
        data1.second=trajetSelected.second[i]->getTemps();
        indicePoint.push_back(data1);

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
unsigned int Station::initialisation(unsigned int& point2)
{

      std::cout<<std::endl<<"Par quel sommet voulez-vous debuter le parcours ? "<<std::endl;
    unsigned int point1=-1;
    ///Blindage saisie

    while(point1<0 || point1>m_ordre)
        std::cin>>point1;
    std::cout<<std::endl<<"Par quel sommet voulez-vous finir le parcours ? "<<std::endl;
    ///Blindage saisie

    while(point2<0 || point2>m_ordre)
        std::cin>>point2;
    ///On parcours tous les sommets pour les initialiser
    for(size_t i=0; i<m_points.size(); i++)
            m_points[i]->init(point1);


    ///On retourne le sommet de début de parcours
    return point1;
}

unsigned int Station::initialisationAll()
{   std::cout<<std::endl<<"Par quel sommet voulez-vous debuter le parcours ? "<<std::endl;
    unsigned int point1=-1;
    ///Blindage saisie

    while(point1<0 || point1>m_ordre)
        std::cin>>point1;

         for(size_t i=0; i<m_points.size(); i++)
            m_points[i]->init(point1);
              return point1;


}
void Station::Dijsktra()
{
    std::cout<<"begin dijsktra"<<std::endl;
    std::vector<Point*> sousgraphe;
    unsigned int pointf;
    std::cout<<std::endl<<"1  : Plus court chemin entre deux points ?"<<std::endl<<"2: entre 1 point et les autres? "<<std::endl;
    int choix2;
    std::cin>>choix2;
    int pointi;
    if (choix2 == 1){pointi=initialisation(pointf);
    std::cout<<"pointf:"<<pointf;
    std::cout<<"pointi:"<<pointi;
}
    else if (choix2 ==2){pointi= initialisationAll();
    std::cout<<"pointi:"<<pointi;
}

    int cpt=0;
    float temps = 0 ,mini=100000;
    unsigned point=-1;

    while(sousgraphe.size()<m_ordre)
    {
        for(size_t i=0; i < m_points.size();i++)
        {
            if(!sousgraphe.empty())
            {


                for(size_t j=0; j<sousgraphe.size(); j++)
                   {
                    ///On regarde si le sommet n'est pas dans sous graphe
                    if(m_points[i]->getindice()==sousgraphe[j]->getindice())
                        cpt++;}
            }
            if (m_points[i]->getTemps()< mini && cpt==0)
            {

                mini=m_points[i]->getTemps();
                point=m_points[i]->getindice();
            }
            cpt=0;

        }
        mini=100000;
        sousgraphe.push_back(m_points[point-1]);
        m_points[point-1]->Dijsktra(sousgraphe);
    }
     if (choix2 == 1){afficherDijkstra(pointf,pointi,temps);}
    else if (choix2 ==2){afficherDijkstraAll(pointi,temps);}



}
void Station::afficherDijkstraAll(unsigned int pointi, float temps)
{std::cout<<std::endl;
    for (size_t i=0; i<m_points.size();i++)
    {temps=m_points[i]->getTemps();
    m_points[i]->afficherDijkstra();
     std::cout<<pointi<<" : temps = "<<temps<<std::endl;

    }
}
void Station::afficherDijkstra(unsigned int pointf, unsigned int pointi, float temps)
{
    std::cout<<std::endl;
    temps=m_points[pointf-1]->getTemps();
    m_points[pointf-1]->afficherDijkstra();
     std::cout<<pointi<<" : temps = "<<temps<<std::endl;
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
