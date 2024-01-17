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
    std::ofstream myfile("blabla.txt");
}