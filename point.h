#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{
public:
    bool isMark = false;
    Point* ant= nullptr;

    Point(int indice, int altitude);
    ~Point();

    /// Getters
    int getindice() const;
    std::string getnom_lieu() const;
    int getAltitude();
    std::vector<Point*>& getadj();

    ///Setters

    void set_nom_lieu(std::string nom);

private:
    int m_indice;
    std::string m_nom;
    int m_altitude;
    std::vector<std::pair<Point*, int>>point_adj;
    int m_temps=0;
    Point* point_predecesseur=nullptr;


};

#endif // POINT_H_INCLUDED
