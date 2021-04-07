#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>
#include <string.h>
#include <vector>
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

private:
    int m_indice;
    std::string m_nom;
    int m_altitude;
    std::vector<std::pair<Point*, int>>point_adj;
    int m_temps=0;
    Point* point_predecesseur=nullptr;


};

#endif // POINT_H_INCLUDED
