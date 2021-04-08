#include <iostream>
#include "station.h"

int main()
{
    std::cout<<"Quel fichier voulez-vous ouvrir ? ";
    std::cout<<"Salut";


    Station nathanael("data_arcs.txt");
    nathanael.afficher();
    return 0;
}
