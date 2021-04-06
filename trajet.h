#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include "point.h"

#endif // TRAJET_H_INCLUDED
class Trajet
{

    public:
    Trajet(int indice,int num_depart, int num_arrive);
    ~Trajet();

    int getindice() const;
    std::string get_nom_trajet();
    std::string get_type();
    int get_num_depart();
    int get_num_arrive();
    std::pair<Point*,Point*>& gettrajet();

    /// Setter

    void settemps(float temps);
    void set_nom_trajet(std::string nom_trajet);
    void set_type(std::string type);


    ///Methodes d'affichage

    void afficher() const ;
    private:
        int m_indice;
        int m_temps;
        std::string m_nom_trajet;
        std::string m_type;
        std::pair<Point*,Point*>m_trajet;

};
