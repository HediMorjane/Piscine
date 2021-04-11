#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED
#include <fstream>
#include <algorithm>
#include <math.h>

#include"trajet.h"

class Station
{
public:
    Station(std::string nomFichier);
    ~Station();
    ///GETTER
    std::vector< Point*>& getTabPoints();
    std::vector< Trajet*>& getTabTrajets();
    void afficherGraph();

    std::pair<Point*,Point*> afficherSommet(std::string nom);

    std::pair<std::vector <Trajet*>, std::vector<Trajet*> >afficherTrajet(std::string nom);
    std::vector<std::pair <Point*,PointInfoTrajet*>> rechercheAdj(int indice);
    int isPointExistByName(std::string name);
    int isTrajetExistByName(std::string name);

    void afficherBfs(int point);
    void ParcoursBfs();
    void loadGraph(std::string nomFichier);
    void Dijsktra();
    unsigned int initialisation(unsigned int& pointf);

    void reinitialiser();
    void afficherDijkstra(unsigned int pointf, unsigned int pointi, float temps);
    void afficherDijkstraAll(unsigned int pointi, float temps);
    unsigned int initialisationAll();


private:
    std::vector< Point*>m_points;
    std::vector< Trajet*>m_trajets;
    int m_ordre;
    int m_taille;

};

#endif // STATION_H_INCLUDED
