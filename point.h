#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include<string>
#include "PointInfoTrajet.h"
class Point
{
public:
    Point(int indice);
    ~Point();

    /// Getters
    int getindice() const;
    std::string getNomLieu() const;
    int getAltitude()const;
    std::vector<Point*>& getadj();

    ///Setters

    void setNomLieu(std::string nom);
    void setAltitude(int altitude);

    void afficher() const;
    void afficherAdja();
    void addAdjBfs(Point* point,std::string type);
    void BFS();
    void afficherBfs(int point);
    std::vector<std::pair<Point*,std::string>>  getAdjacent();
    void setColor(int color);
    void reinitialiser();
    void addAdjDijsktra(Point* point,PointInfoTrajet* pointInfo);
    void init(unsigned int point);
    void Dijsktra(std::vector<Point*> sousgraphe);
    void afficherDijkstra();
    float getTemps();


private:
    int m_indice;
    std::string m_nom;
    int m_altitude;
    int m_color;//La couleur
    std::vector<std::pair<Point*, PointInfoTrajet* >>point_adj; /// dijsktra
    std::vector<std::pair<Point*,std::string>> m_pointadj;
    float m_temps=0;
    Point* point_predecesseur=nullptr;
    std::vector<Point*> m_successeur;


};

#endif // POINT_H_INCLUDED
