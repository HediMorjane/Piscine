#include <iostream>
#include "station.h"

int main()
{
    ///std::cout<<"Quel fichier voulez-vous ouvrir ? ";
    int choix;

    Station nathanael("data_arcs.txt");
    do
    {
        std::cout<<"Choissisez une action : "<<std::endl;
        std::cout<<"0: Trouver votre localisation : "<<std::endl;
        std::cout<<"1. Quitter"<<std::endl;

        std::cout<<"Entrer votre choix :" << std::endl;
        std::cin>> choix;
        system("cls");

        switch(choix)
        {
        case 0:
            int choix2;
            std::cout<<"1: via un trajet  "<<std::endl;
            std::cout<<"2: via un point   "<<std::endl;
            std::cout<<"Entrer votre choix :" << std::endl;
            std::cin>> choix2;

            if(choix2==1)
            {
                std::string nom;
                std::pair<Point*,Point*> sommetSelec;
                std::cout<<"Comment se nommme votre trajet?"<<std::endl;
                std::cin>>nom;
                sommetSelec= nathanael.afficherSommet(nom);
                std::cout<<"1er point "<<sommetSelec.first->getindice()<<"  2nd point:  "<<sommetSelec.second->getindice()<<std::endl;


            }
            if(choix2==2)
            {
                std::string nom;

                std::pair<std::vector <Trajet*>, std::vector<Trajet*>> TrajetSelec;
                std::cout<<"Comment se nommme votre point?"<<std::endl;
                std::cin>>nom;
                TrajetSelec=nathanael.afficherTrajet(nom);
                for(unsigned int i=0; i<TrajetSelec.first.size();i++)
                {
                    std::cout << " trajet qui en partent :"<<TrajetSelec.first[i]->getNomTrajet()<<std::endl;
                }

                for(unsigned int i=0; i<TrajetSelec.second.size();i++)
                {
                    std::cout<<" trajet qui permettent d'y arriver:"<<TrajetSelec.second[i]->getNomTrajet()<<std::endl;
                }

               // std::cout << " trajet qui en partent :"<<TrajetSelec.first->m_trajet[j]<<" trajet qui permettent d'y arriver: "<<TrajetSelec.second->getNomTrajet()<<std::endl;

            }
            break;

        default:
            break;
        }
    }
    while(choix!=4);


    /// nathanael.afficher();
    return 0;
}
