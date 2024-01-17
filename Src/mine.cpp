#include "../Inc/mine.hpp"
#include <vector>

Mine::Mine(/* args */)
{
    std::cout << "Kopalnia uruchomiona.\n";
}

Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc.\n";
}

int Mine::InitScheme(std::string name)
{
    std::cout << "Kopalnia wczytuje harmonogram.\n";
    std::string line;
    std::ifstream myfile(name);
    // std::vector<std::string> tmp;
    int lastSpacePlace = 0;
    int spacesNr = 0;
    std::string::iterator it;
    int spacePlace = 0;
    int time = 0;
    int ID = 0;
    std::string game = "";
    int weight = 0;
    int amount = 0;
    int duration = 0;

    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            std::cout << "====================================\n";
            std::cout << line << '\n';
            for(it = line.begin(); it < line.end(); it++)
            {
                if(*it == ' ')
                    spacesNr++;
            } // policz ilosc spacji
            spacePlace = line.find(' ');
            
            std::cout << spacePlace << std::endl;
            time = stoi(line.substr(0,spacePlace));
            line.erase(0, spacePlace + 1);  // usun przeczytana wartosc i spacje
            spacesNr--;
            std::cout << "czas: " << time << std::endl;

            spacePlace = line.find(' ');
            while(spacePlace >= 0)
            {
                std::cout << line << std::endl;
                std::cout << "------------\n";
                
                std::cout << line << std::endl;
                std::cout << spacePlace << std::endl;
                ID = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1); // usun przeczytana wartosc i spacje
                std::cout << "ID: " << ID << std::endl;

                spacePlace = line.find(' ');
                game = line.substr(0,spacePlace);
                line.erase(0, spacePlace + 1);
                std::cout << "kamien: " << game << std::endl;

                spacePlace = line.find(' ');
                weight = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1);
                std::cout << "ciezar " << weight << std::endl;

                spacePlace = line.find(' ');
                amount = stoi(line.substr(0,spacePlace));
                line.erase(0, spacePlace + 1);
                spacesNr--;
                lastSpacePlace = spacePlace;
                std::cout << "ilosc " << amount << std::endl; 

                spacePlace = line.find(' ');     
            }

        }

        myfile.close();
    }else{
        std::cout << "Nie udalo sie otworzyc pliku: " << name << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
