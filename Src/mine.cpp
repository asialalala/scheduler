#include "../Inc/mine.hpp"

Mine::Mine(/* args */)
{
    std::cout << "Kopalnia uruchomiona\n";
}

Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc.\n";
}

void Mine::InitBoogies(std::string name)
{
    std::cout << "Kopalnia wczytuje stan wagonikow.\n";
    std::string line;
    std::ifstream myfile(name);
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
        std::cout << line << '\n';
        }
        myfile.close();
    }
}