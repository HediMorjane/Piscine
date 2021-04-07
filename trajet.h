#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include "point.h"

#endif // TRAJET_H_INCLUDED
class Trajet
{

    public:
    Trajet(int indice,int num_depart, int num_arrive);
    ~Trajet();

    int getIndice() const;
    std::string getNomTrajet();
    std::string getType();
    int getNumDepart();
    int getNumArrive();
    float getTemps();
    std::pair<Point*,Point*>& gettrajet();

    /// Setter

    void setTemps(float temps);
    void setNomTrajet(std::string nom_trajet);
    void setType(std::string type);


    ///Methodes d'affichage

    void afficher() const ;
    private:
        int m_indice;
        int m_temps;
        std::string m_nom_trajet;
        std::string m_type;
        std::pair<Point*,Point*>m_trajet;

};
