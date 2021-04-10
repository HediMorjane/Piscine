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
    std::vector<int> rechercheAdj(int indice);
    int isPointExistByName(std::string name);
    int isTrajetExistByName(std::string name);

    void afficherBfs(int point);
   void ParcoursBfs();
        void loadGraph(std::string nomFichier);

    void reinitialiser();

private:
    std::vector< Point*>m_points;
    std::vector< Trajet*>m_trajets;
    int m_ordre;
    int m_taille;

};

#endif // STATION_H_INCLUDED
