// in Build
// ./scheduler.out ../Data/data.txt

#include <iostream>
#include <string>
#include "../Inc/mine.hpp"

int main(int argc, char * argv [])
{
    if(argc != 2)
    {
        std::cout << "Niewlasciwa liczba argumentow.\n";
        return EXIT_FAILURE;
    }

    std::string fileNamePass = argv[1];

    Mine mine;

    int initState = mine.InitScheme(fileNamePass);
    if(initState == EXIT_FAILURE)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}