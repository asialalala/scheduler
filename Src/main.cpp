// in Build
// ./scheduler.out ../Data/data.txt
#include <iostream>

int main(int argc, char * argv [])
{
    if(argc != 2)
    {
        std::cout << "Niewlasciwa liczba argumentow.\n";
        return EXIT_FAILURE;
    }

    char *fileNamePass = argv[1];
    FILE *fPass = fopen(fileNamePass, "r");

    if (!fPass)
    {
        fprintf(stderr, "Blad. Nie otwarto pliku. '%s'\n", fileNamePass);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}