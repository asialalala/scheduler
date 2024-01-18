// in Build
// ./scheduler.out ../Data/data.txt

#include <iostream>
#include <string>
#include <iterator>
#include "../Inc/mine.hpp"

int main(int argc, char * argv [])
{
    if(argc != 5)
    {
        std::cout << "Niewlasciwa liczba argumentow.\n";
        return EXIT_FAILURE;
    }

    // wczytanie parametrow programu
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!isdigit(argv[1][i]))
        {
            std::cout << "Niepoprwana ilosc robotow.\n";
            return EXIT_FAILURE;
        }        
    }

    int robotsNr = atoi(argv[1]);

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany kwant czasu.\n";
            return EXIT_FAILURE;
        }        
    }

    int timeQuantum = atoi(argv[2]);

    std::string fileNamePass = argv[3];



    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany typ strategii.\n";
            return EXIT_FAILURE;
        }        
    }
    int strategyName = atoi(argv[4]);


    Mine::Mine mine;

    int initState = mine.InitScheme(fileNamePass);
    if(initState == EXIT_FAILURE)
        return EXIT_FAILURE;

    mine.Report();

    return EXIT_SUCCESS;
}