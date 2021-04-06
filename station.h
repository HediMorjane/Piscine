#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED

#include"trajet.h"

class Station
{
public:
    Station(std::string nomFichier);
    ~Station();
    void afficher() const;




private:
    std::vector< Point*>m_points;
    std::vector< Trajet*>m_trajets;
    int m_ordre;
    int m_taille;


};

#endif // STATION_H_INCLUDED
