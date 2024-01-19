// in Build
// ./scheduler 2 1 ../Data/data.txt 2

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

    std::string fileNamePass = argv[3];
    Mine::Mine mine;

    if(mine.MineInit(argv) == EXIT_FAILURE)
        return EXIT_FAILURE;

    if(fileNamePass == "-")
    {
        if(mine.Schedule() == EXIT_FAILURE)
        return EXIT_FAILURE;
    }else{
        if(mine.Schedule(fileNamePass) == EXIT_FAILURE)
        return EXIT_FAILURE;
    }

    mine.Report();

    return EXIT_SUCCESS;
}