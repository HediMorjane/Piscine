#include <iostream>
#include "station.h"

int main()
{
    std::cout<<"Quel fichier voulez-vous ouvrir ? ";


    Station nathanael("data_arcs.txt");
    nathanael.afficher();
    return 0;
}
