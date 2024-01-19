#include "../Inc/mine.hpp"
#include <vector>
#include <iterator>

Mine::Mine::Mine(int robotsNr)
{
    std::cout << "Kopalnia uruchomiona.\n";
    m_robotsNr = robotsNr;
    for (size_t i = 0; i < m_robotsNr; i++)
    {
        m_robotsContainer.push_back(Robot::Robot());
    }
    
}

Mine::Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc.\n";
}

int Mine::Mine::MineInit(char * argv [])
{
    // wczytanie parametrow programu

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany kwant czasu.\n";
            return EXIT_FAILURE;
        }        
    }

    m_timeQuantum = atoi(argv[2]);

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany typ strategii.\n";
            return EXIT_FAILURE;
        }        
    }

    switch (atoi(argv[4]))
    {
    case 1:
        m_strategyName = RR;
        break;
    
    case 2:
        m_strategyName = FCFS;
        break;

    default:    
        std::cout << "Niepoprwany typ strategii.\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int Mine::Mine::Schedule()
{
    std::cout << "Kopalnia wczytuje harmonogram.\n";
    std::string temp = "";
    int spacePlace = 0;
    int time = 0;
    int ID = 0;
    std::string game = "";
    int weight = 0;
    int amount = 0;
    
    do{     // przydaloby sie zrobic input validation
        std::cout << "Kopalnia wczytuje nadjerzdzajace roboty.\n";
        std::cout << "  Prosze podac minute, w ktorej przybyla taczka.\n";
        std::cin >> temp;
        time = stoi(temp);
        std::cout << "  Prosze podac ID taczki.\n";
        std::cin >> temp;
        ID = stoi(temp);
        std::cout << "  Prosze podac zawarte w taczce kamienie.\n";
        std::cin >> temp;
        game = temp;
        std::cout << "  Prosze podac ilosc kamieni.\n";
        std::cin >> temp;
        weight = stoi(temp);
        std::cout << "  Prosze podac wage kamienia.\n";
        std::cin >> temp;
        amount = stoi(temp);
        std::cout << "  Prosze podac jakikolwiek znak, aby podac wiecej informacji o taczkach\n"
                   << " lub wpisac koniec, aby zakonczyc.\n";
        std::cin >> temp;

        m_bogieContainer.push_back( Bogie::Bogie(time, ID, game, weight,
                            amount));
        // ScheduleFCFS();
    }while(temp.compare("koniec") != 0);

    return EXIT_SUCCESS;
}

int Mine::Mine::Schedule(std::string name)
{
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
            std::cout << "Kopalnia wczytuje nadjerzdzajace roboty.\n";
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

                m_bogieContainer.push_back( Bogie::Bogie(time, ID, game, weight,
                                    amount));
            }
            ScheduleFCFS();

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
    for(Bogie::BogieContainer::iterator it = m_bogieContainer.begin(); it != m_bogieContainer.end(); it++)
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

void Mine::Mine::ScheduleFCFS()
{
    std::cout << "Szereguje zadania zgodnie z FCFS\n";
    int i = 0;
    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.IncreaseWorkingTime();
    }

    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.FinishJob();
    }

    for(Robot::Robot& robot : m_robotsContainer)
    {
        std::cout << i;
        i++;
        bool workAssigned = robot.StartJob(&m_bogieContainer.front());
        if(workAssigned)    //jesli uda sie to zmniejsz wektor wagonikow do obsluzenia
            m_bogieContainer.erase(m_bogieContainer.begin());
        if(m_bogieContainer.empty())// jesli wektor jest wusty to zakoncz
            break;
    }


}
