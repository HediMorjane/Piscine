#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include<string>
class Point
{
public:
    bool isMark = false;
    Point* ant= nullptr;

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
    void addAdjBfs(Point* point);
    void BFS();
    void afficherBfs(int point);
    std::vector<Point*> getAdjacent();
    void setColor(int color);
    void reinitialiser();

private:
    int m_indice;
    std::string m_nom;
    int m_altitude;
    int m_color;//La couleur
    std::vector<std::pair<Point*, int>>point_adj;/// dijsktra surement float
    std::vector<Point*> m_pointadj;
    int m_temps=0;
    Point* point_predecesseur=nullptr;
    std::vector<Point*> m_successeur;


};

#endif // POINT_H_INCLUDED
