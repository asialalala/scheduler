#include "../Inc/mine.hpp"
#include <vector>
#include <iterator>

Mine::Mine::Mine()
{
    std::cout << "Kopalnia uruchomiona.\n";
}

Mine::Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc.\n";
}

int Mine::Mine::MineInit(char * argv [])
{
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

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany typ strategii.\n";
            return EXIT_FAILURE;
        }        
    }
    int strategyName = atoi(argv[4]);

    return EXIT_SUCCESS;
}

int Mine::Mine::InitScheme(std::string name)
{
    std::cout << "Kopalnia wczytuje harmonogram.\n";
    std::string line;
    std::ifstream myfile(name);
    int spacePlace = 0;
    int time = 0;
    int ID = 0;
    std::string game = "";
    int weight = 0;
    int amount = 0;
    int i = 0;

    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            spacePlace = line.find(' ');
            time = stoi(line.substr(0,spacePlace));
            line.erase(0, spacePlace + 1);  // usun przeczytana wartosc i spacje

            spacePlace = line.find(' ');
            while(spacePlace >= 0)
            {
                ID = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1); // usun przeczytana wartosc i spacje

                spacePlace = line.find(' ');
                game = line.substr(0,spacePlace);
                line.erase(0, spacePlace + 1);

                spacePlace = line.find(' ');
                weight = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1);

                spacePlace = line.find(' ');
                amount = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1);

                spacePlace = line.find(' ');     

                scheme.push_back(   Bogie::Bogie(time, ID, game, weight,
                                    amount));
            }

        }

        myfile.close();
    }else{
        std::cout << "Nie udalo sie otworzyc pliku: " << name << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void Mine::Mine::Report()       // tutaj przydałoby sie zrobic consta
{
    std::cout << "=====================================================\n";
    
    int time = -1;
    for(Scheme::iterator it = scheme.begin(); it != scheme.end(); it++)
    {
        if(time == it->getStartTime())
        {
            std::cout << "oraz " << " pojawila sie taczka nr "
            << it->getID() << " zawierajaca " << it->getAmount() << " kamieni typu " 
            << it->getGameName() << " o wadze " << it->getWeight() << ", jej rozpakowanie potrwa "
            << it->getDuration() << " minut.\n";
        }else{ 
            std::cout << "W minucie " << it->getStartTime() << " pojawila sie taczka nr "
            << it->getID() << " zawierajaca " << it->getAmount() << " kamieni typu " 
            << it->getGameName() << " o wadze " << it->getWeight() << ", jej rozpakowanie potrwa "
            << it->getDuration() << " minut.\n";
        }
        
        time = it->getStartTime();

    }

    std::cout << "=====================================================\n";
}
