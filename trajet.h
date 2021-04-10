#ifndef TRAJET_H_INCLUDED
#define TRAJET_H_INCLUDED

#include "point.h"
#include <map>

#endif // TRAJET_H_INCLUDED
class Trajet
{

    public:
    Trajet(int indice,int num_depart, int num_arrive);
    enum enumAllType {V,B,R,N,KL,SURF,TPH,TC,TSD,TK,BUS,TS};
    ~Trajet();

    int getIndice() const;
    std::string getNomTrajet();
    std::string getType();
    int getNumDepart();
    int getNumArrive();
    float getTemps();
    std::pair<Point*,Point*>& gettrajet();

    /// Setter
    void setTemps(std::string str);
    void setNomTrajet(std::string nom_trajet);
    void setType(std::string type);
    void setPointTrajet(std::pair<Point*,Point*> m_trajetGiven);
    ///Methodes d'affichage
    void initMap();


    void afficher() const ;
    private:
        int m_indice;
        int m_temps;
        std::string m_nom_trajet;
        std::string m_type;
        std::pair<Point*,Point*>m_trajet;
        std::map<std::string, enumAllType> mapType;


};
