#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include "point.h"

#endif // TRAJET_H_INCLUDED
class Trajet
{

    public:
    Trajet(int indice,std::string nom_trajet, std::string type,int num_depart, int num_arrive, int temps );
    ~Trajet();

    int getindice() const;
    std::string get_nom_trajet();
    std::string get_type();
    int get_num_depart();
    int get_num_arrive();
    std::pair<Point*,Point*>& gettrajet();

    /// Setter

    void settemps(int temps);

    ///Methodes d'affichage
    private:
        int m_indice;
        int m_temps;
        std::pair<Point*,Point*>m_trajet;

_};
