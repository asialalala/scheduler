#include "../Inc/mine.hpp"
#include <vector>
#include <iterator>

#define MAX_LENGTH 15 // czy tutaj?

Mine::Mine::Mine(int robotsNr)
{
    std::cout << "Kopalnia uruchomiona." << std::endl;
    m_robotsNr = robotsNr;
    for (size_t i = 0; i < m_robotsNr; i++)
    {
        m_robotsContainer.push_back(Robot::Robot());
    }
    lackOfBogie = false;
    m_bogieContainerIterator = 0;
    m_arrivingBogieIterator = 0;
    m_lastArrvied = -1;
    
}

Mine::Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc." << std::endl;
}

int Mine::Mine::MineInit(char * argv [])
{
    // wczytanie parametrow programu

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany kwant czasu." << std::endl;
            return EXIT_FAILURE;
        }        
    }

    m_timeQuantum = atoi(argv[2]);

    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany typ strategii." << std::endl;
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
        std::cout << "Niepoprwany typ strategii." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int Mine::Mine::Schedule()
{
    std::cout << "Kopalnia wczytuje harmonogram." << std::endl;
    std::string temp = "";
    int spacePlace = 0;
    int time = 0;
    int ID = 0;
    std::string game = "";
    int weight = 0;
    int amount = 0;
    
    do{     // przydaloby sie zrobic input validation
        std::cout << "Kopalnia wczytuje nadjerzdzajace roboty." << std::endl;
        std::cout << "  Prosze podac minute, w ktorej przybyla taczka." << std::endl;
        std::cin >> temp;
        time = stoi(temp);
        std::cout << "  Prosze podac ID taczki." << std::endl;
        std::cin >> temp;
        ID = stoi(temp);
        std::cout << "  Prosze podac zawarte w taczce kamienie." << std::endl;
        std::cin >> temp;
        game = temp;
        std::cout << "  Prosze podac ilosc kamieni." << std::endl;
        std::cin >> temp;
        weight = stoi(temp);
        std::cout << "  Prosze podac wage kamienia." << std::endl;
        std::cin >> temp;
        amount = stoi(temp);
        std::cout << "  Prosze podac jakikolwiek znak, aby podac wiecej informacji o taczkach." << std::endl;
                std::cout    << " lub wpisac koniec, aby zakonczyc." << std::endl;
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
    bool startTask = false;

    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            std::cout << "Kopalnia wczytuje nadjerzdzajace roboty." << std::endl;
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

                Bogie::Bogie* newBogie = new Bogie::Bogie(time, ID, game, weight,amount);
                m_bogieContainer.push_back(*newBogie );
                            }
            if(m_bogieContainer.size() > 0)
            {

                ScheduleFCFS();
                Report(time);
            }
        }

        myfile.close();
    }else{
        std::cout << "Nie udalo sie otworzyc pliku: " << name << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void Mine::Mine::Report(int time)       // tutaj przydałoby sie zrobic consta
{
    int i = 0;

    std::cout << "Moment " << time <<  std::endl;
    if(m_lastArrvied != m_arrivingBogieIterator)
    {
        for (; m_arrivingBogieIterator < m_bogieContainer.size(); m_arrivingBogieIterator++)
        {
            std::cout << "      wheelbarrow arrived <" << std::setw(MAX_LENGTH) 
                        << std::left << m_bogieContainer[m_arrivingBogieIterator].getID() << " " 
                        << m_bogieContainer[m_arrivingBogieIterator].getGameName() << " "
                        << m_bogieContainer[m_arrivingBogieIterator].getWeight() << " "
                        << m_bogieContainer[m_arrivingBogieIterator].getAmount() << " "
                        << "[" << m_bogieContainer[m_arrivingBogieIterator].getDuration() << "]" 
                        << std::right << ">" << std::endl;
            m_lastArrvied = m_arrivingBogieIterator;
        }
        
    }
    

     for (Robot::RobotsContainer::iterator robot = m_robotsContainer.begin(); robot != m_robotsContainer.end(); robot++)
        {
           
            if (robot->getOutOfWorkState() == true)
            {
                if (i == 0)
                {
                    std::cout << "\t[" << std::setw(MAX_LENGTH+2) << "]";
                }

                else 
                {
                    std::cout << "[" << std::setw(MAX_LENGTH+2) << "]" << std::endl;
                }
                        
            }
            else
            {
                if (i == 0)
                {
                    std::cout << "\t[" << std::setw(MAX_LENGTH) << std::left << robot->getBogie()->getGameName()
                    << std::right << robot->getTimeToEnd() << "]";
                }
                else
                {
                    std::cout << "[" << std::setw(MAX_LENGTH) << std::left << robot->getBogie()->getGameName()
                    << std::right << robot->getTimeToEnd() << "]" << std::endl;
                }

            }
            i++;
        }
        std::cout << std::endl;
}

void Mine::Mine::ScheduleFCFS()
{       
    std::cout << "Szereguje zadania zgodnie z FCFS"<< std::endl;
    int i = 0;
    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.IncreaseWorkingTime();
    }

    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.FinishJob();
    }

    if(lackOfBogie && m_bogieContainerIterator < m_bogieContainer.size() - 1)
        m_bogieContainerIterator++;
    
    lackOfBogie = false;
    for(Robot::Robot& robot : m_robotsContainer)
    {
        if(robot.StartJob(&(m_bogieContainer[m_bogieContainerIterator])))    //jesli uda sie to przesunac iterator do nastepnego 
        {
            if(m_bogieContainerIterator < m_bogieContainer.size() - 1)  
            {
                m_bogieContainerIterator++;
            }else{  // jesli nie ma juz wiecej wozkow
                lackOfBogie = true;
                break;
            }
        }else{
            // std::cout << "nie udalo sie dodac wozka\n";
        }
    }
}
