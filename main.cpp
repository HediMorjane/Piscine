#include <iostream>
#include "station.h"

int main()
{
    ///std::cout<<"Quel fichier voulez-vous ouvrir ? ";
    int choix;

    Station nathanael("test.txt");


        nathanael.afficherGraph();
    do
    {
        std::cout<<std::endl<<"Veuillez choisir une action parmis les choix suivants : "<<std::endl;
        std::cout<<"    0: Trouver votre localisation : "<<std::endl;
        std::cout<<"    1: Trouver mon plus court chemin (BFS)  "<<std::endl;
        std::cout<<"    2: Rechercher mes sommets ADJ   "<<std::endl;
        std::cout<<"    3:Trouver mon plus court chemin (Dijsktra)  "<<std::endl;
        std::cout<<"    4. Quitter "<<std::endl;

        std::cout<<"Entrer votre choix :" << std::endl;
        std::cin>> choix;

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
                std::cout<<"Comment se nommme votre trajet?"<<std::endl;
                std::cin>>nom;
                int isTrajetExist = nathanael.isTrajetExistByName(nom);
                std::pair<Point*,Point*> sommetSelec;
                sommetSelec= nathanael.afficherSommet(nom);
                if(isTrajetExist ==-1)
                {
                    std::cout<<"Le nom renseigné n'est attribué à aucun trajet. "<<std::endl;
                    std::cout<<"Vérifier l'orthographe du nom saisi "<<std::endl;
                }
                else
                {
                    int indice_depart = sommetSelec.first->getindice();
                    int indice_arrive = sommetSelec.second->getindice();
                    std::vector< Point*> m_all_pts = nathanael.getTabPoints();
                    std::cout<<"   Le point de départ est : "<<indice_depart<< " "<<m_all_pts[indice_depart-1]->getNomLieu()<<std::endl;
                    std::cout<<"   Le point d'arrivée est : "<<indice_arrive<< " "<<m_all_pts[indice_arrive-1]->getNomLieu()<<std::endl;
                }
            }
            if(choix2==2)
            {
                std::string nom;
                std::cout<<"Comment se nommme votre point?"<<std::endl;
                std::cin>>nom;
                int isPointExist = nathanael.isPointExistByName(nom);
                if( isPointExist == -1)
                {
                    std::cout<<"Le nom renseigné n'est attribué à aucun point. "<<std::endl;
                    std::cout<<"Vérifier l'orthographe du nom saisi "<<std::endl;
                }
                else
                {
                    std::pair<std::vector <Trajet*>, std::vector<Trajet*>> TrajetSelec;
                    TrajetSelec=nathanael.afficherTrajet(nom);
                    if(TrajetSelec.first.size()==0)
                    {
                        std::cout << "Il n'y a pas de trajets qui partent de ce point "<<std::endl;
                    }
                    else
                    {
                        for(unsigned int i=0; i<TrajetSelec.first.size(); i++)
                        {
                            std::cout << "Les trajets qui partent du point "<<nom<<" sont : "<<TrajetSelec.first[i]->getNomTrajet()<<std::endl;
                        }
                    }
                    if(TrajetSelec.second.size()==0)
                    {
                        std::cout << "Il n'y a pas de trajets qui arrivent par ce point "<<std::endl;
                    }
                    else
                    {
                        for(unsigned int i=0; i<TrajetSelec.second.size(); i++)
                        {
                            std::cout<<"Les trajets qui arrivent du point "<<nom<<" sont : "<<TrajetSelec.second[i]->getNomTrajet()<<std::endl;
                        }
                    }
                }
            }
            break;
        case 1:
            nathanael.ParcoursBfs();
            nathanael.reinitialiser();

            break;
        case 2:
        {
            std::vector<std::pair <Point*,PointInfoTrajet*>>test;
            int indice;
            std::cout<<"Entrez l'indice du point"<<std::endl;

            std::cin>>indice;
            test=nathanael.rechercheAdj(indice);


            for(unsigned int i=0; i<test.size(); i++)
            {
                std::cout<<"indice:"<<test[i].first->getindice()<<"  "<<test[i].second->getPointInfoType()<<std::endl;
            }
        }
        break;
        case 3:
            nathanael.Dijsktra();
            nathanael.reinitialiser();

        default:
            break;
        }
    }
    while(choix!=4);



    return 0;
}
