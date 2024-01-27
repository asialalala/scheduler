#include "../Inc/mine.hpp"
#include <vector>
#include <iterator>
#include <cstring>
#include <iomanip>

#define MAX_LENGTH 15 // czy tutaj?

Mine::Mine::Mine(int robotsNr, int quantum) : m_quantum(0), m_RRtime(0), m_lackOfBogie(false), m_bogieContainerIterator(0),
                                            m_arrivingBogieIterator(0), m_lastArrvied(-1), m_endOfreading(false)
{
    
    m_robotsNr = robotsNr;
    for (size_t i = 0; i < m_robotsNr; i++)
    {
        m_robotsContainer.push_back(Robot::Robot());
    }
    std::cout << "Kopalnia uruchomiona." << std::endl;
    m_added = false;
}

Mine::Mine::~Mine()
{
    std::cout << "Kopalnia zamyka dzialalnosc." << std::endl;
}

int Mine::Mine::MineInit(char * argv [])
{
    // wczytanie parametrow programu

    // std::cout << "Kopalnia organizuje sie do pracy." << std::endl;
    for(int i = 0; i < strlen(argv[2]); i++)
    {
        if(!isdigit(argv[2][i]))
        {
            std::cout << "Niepoprwany kwant czasu." << std::endl;
            return EXIT_FAILURE;
        }        
    }

    for(int i = 0; i < strlen(argv[4]); i++)
    {
        if(!isdigit(argv[4][i]))
        {
            std::cout << "Niepoprwany typ strategii." << std::endl;
            return EXIT_FAILURE;
        }        
    }

    m_quantum = atoi(argv[2]);

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

    // std::cout << "Kopalnia uruchomiona z kwantem: " << m_quantum; 
    return EXIT_SUCCESS;
}

int Mine::Mine::UploadBogieContainer()
{
    // std::cout << "Kopalnia wczytuje harmonogram." << std::endl;
    std::string temp = "";
    int spacePlace = 0;
    int time = 0;
    int ID = 0;
    std::string game = "";
    int weight = 0;
    int amount = 0;
    
    do{     // przydaloby sie zrobic input validation
        time++;
        std::cout << "Kopalnia wczytuje nadjerzdzajace roboty." << std::endl;
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

        Bogie::Bogie* newBogie = new Bogie::Bogie(time, ID, game, weight,amount);
        m_bogieContainer.push_back(*newBogie );
        
        if(m_bogieContainer.size() > 0)
        {
            switch (m_strategyName)
            {
                case FCFS:
                    ScheduleFCFS();
                    break;

                case RR:
                    ScheduleRR();
                    break;

                default:
                    std::cout << "Niepoprawna strategia szeregowania.\n";
                    break;
            }

            Report(time);
        }

    }while(temp.compare("koniec") != 0);

    
    m_endOfreading = true;
    return time;
}

int Mine::Mine::UploadBogieContainer(std::string name)
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
            // std::cout << "Kopalnia wczytuje nadjerzdzajace roboty." << std::endl;
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
                switch (m_strategyName)
                {
                    case FCFS:
                        ScheduleFCFS();
                        break;

                    case RR:
                        ScheduleRR();
                        break;

                    default:
                        std::cout << "Niepoprawna strategia szeregowania.\n";
                        break;
                }
                Report(time);
            }
        }

        myfile.close();
    }else{
        std::cout << "Nie udalo sie otworzyc pliku: " << name << std::endl;
        return WRONG_FILE;
    }
    m_endOfreading = true;
    
    return time;
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
                    std::cout << "[" << std::setw(MAX_LENGTH+2) << "]" ;
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
                    << std::right << robot->getTimeToEnd() << "]" ;
                }

            }
            i++;
        }
        std::cout << std::endl;
}

void Mine::Mine::ScheduleFCFS()
{       
    //  std::cout << "Szeregowanie FCFS." << std::endl;
    int i = 0;

    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.IncreaseWorkingTime();
    }

    int bogieIdToUpdate = NONE_BOGIE;
    for(Robot::Robot& robot : m_robotsContainer)
    {
        int timeOfWork = robot.getTimeToEnd();
        bogieIdToUpdate =  robot.FinishJob();
        if(bogieIdToUpdate != NONE_BOGIE)
            m_bogieContainer[bogieIdToUpdate].setDuration(timeOfWork);
    }

    if(!m_lackOfBogie || !m_endOfreading)
    {
        if(m_lackOfBogie && m_bogieContainerIterator < m_bogieContainer.size() - 1)
        m_bogieContainerIterator++;
    
        m_lackOfBogie = false;

        for(Robot::Robot& robot : m_robotsContainer)
        {
            if(robot.StartJob(&(m_bogieContainer[m_bogieContainerIterator]), m_bogieContainerIterator))    //jesli uda sie to przesunac iterator do nastepnego 
            {
                if(m_bogieContainerIterator < m_bogieContainer.size() - 1)  
                {
                    m_bogieContainerIterator++;
                }else{  // jesli nie ma juz wiecej wozkow
                    m_lackOfBogie = true;
                    break;
                }
            }else{
            // std::cout << "nie udalo sie dodac wozka\n";
            }
        }
    }
    
}

bool Mine::Mine::checkIfEnd() {
    for(Robot::Robot& robot : m_robotsContainer)
    {
        if(robot.getTimeToEnd() > 0)
        {
            // std::cout << "kontynuuj prace.\n";
            return false;
        }
    }
    // std::cout << "Wszystkie skonczyly.\n";
    return true;
}

int Mine::Mine::Schedule()
{
    int time = UploadBogieContainer();
    if(time == WRONG_FILE)
    {
        return EXIT_FAILURE;
    }
    while (!checkIfEnd())
    {
        time++;
        switch (m_strategyName)
        {
            case FCFS:
                ScheduleFCFS();
                break;
            case RR:
                ScheduleRR();
                break;
            default:
                std::cout << "Niepoprawna strategia szeregowania.\n";
                break;
        }
        Report(time);
    }
    return EXIT_SUCCESS;
}

int Mine::Mine::Schedule(std::string name)
{
    int time =  UploadBogieContainer(name);
    if(time == WRONG_FILE)
    {
        return EXIT_FAILURE;
    }
    while (!checkIfEnd())
    {
        time++;
        switch (m_strategyName)
        {
            case FCFS:
                ScheduleFCFS();
                break;
            case RR:
                ScheduleRR();
                break;
            default:
                std::cout << "Niepoprawna strategia szeregowania.\n";
                break;
        }
        Report(time);
    }
    return EXIT_SUCCESS;
}

void Mine::Mine::ScheduleRR()
{

    for(Robot::Robot& robot : m_robotsContainer)
    {
        robot.IncreaseWorkingTime();
    }

    int bogieIdToUpdate = NONE_BOGIE;
    // zakoncz dziaalnie tych robotow, ktore moge
    if(m_RRtime == m_quantum)
    {
        std::cout << "zakoncz prace  wszytskich robotow\n";
        // zakoncz dzaialnie wszystkich robotow                         musis jakos zliczac to od ktorego zaczac dodawac prace
        for(Robot::Robot& robot : m_robotsContainer)
        {
            int timeOfWork = robot.getTimeToEnd();
            bogieIdToUpdate =  robot.FinishJobForced();
            if(bogieIdToUpdate != NONE_BOGIE)
            {
                m_bogieContainer[bogieIdToUpdate].setDuration(timeOfWork);
                // std::cout << "  Czas do zakonczenia po minieciu kwantu: " <<  m_bogieContainer[bogieIdToUpdate].getDuration() <<std::endl;
                m_bogieContainer[bogieIdToUpdate].freeServed();
            }
        }
        m_RRtime = 0;

    }else{
        // std::cout << "sprawdzam, czy ktorys moze zakonczyc prce\n";
        for(Robot::Robot& robot : m_robotsContainer)
        {
            int timeOfWork = robot.getTimeToEnd();
            bogieIdToUpdate =  robot.FinishJob();
            if(bogieIdToUpdate != NONE_BOGIE)
            {
                m_bogieContainer[bogieIdToUpdate].setDuration(timeOfWork);
                m_bogieContainer[bogieIdToUpdate].freeServed();
            }    
        }
    }
    
    
    
     if(!m_lackOfBogie || !m_endOfreading)
    {
        m_lackOfBogie = false;

        if(m_added)
            m_bogieContainerIterator = ++m_bogieContainerIterator % (m_bogieContainer.size());
        
        m_added = false;
        // std::cout << "PRZED. zmieniam m_bogieContainerIterator na " << m_bogieContainerIterator << std::endl;
        int startShercingID = m_bogieContainerIterator;
        for(Robot::Robot& robot : m_robotsContainer)
        {
            while((m_bogieContainer[m_bogieContainerIterator].getDuration() <= 0  || m_bogieContainer[m_bogieContainerIterator].getServedInfo() ) && !m_lackOfBogie)
            {
                m_bogieContainerIterator = ++m_bogieContainerIterator % (m_bogieContainer.size());
                // std::cout << "1. zmieniam m_bogieContainerIterator na " << m_bogieContainerIterator << std::endl;
                // std::cout << "startShercingID: " << startShercingID << std::endl;
                if(m_bogieContainerIterator == startShercingID)
                {
                    m_lackOfBogie = true;
                }
            }

            if(!m_lackOfBogie)
            {
                // std::cout << "  podczas zaczecia pracy " << m_bogieContainer[m_bogieContainerIterator].getGameName() << m_bogieContainer[m_bogieContainerIterator].getDuration() <<std::endl;
                if(robot.StartJob(&(m_bogieContainer[m_bogieContainerIterator]), m_bogieContainerIterator))    //jesli uda sie to przesunac iterator do nastepnego 
                {
                    // std::cout << "dodano id " << m_bogieContainerIterator << std::endl;
                    m_added = true;
                    m_bogieContainer[m_bogieContainerIterator].setServed();

                    if(m_bogieContainerIterator < (m_bogieContainer.size() - 1))
                    {
                        // std::cout << "2. zmieniam m_bogieContainerIterator na " << m_bogieContainerIterator << std::endl;
                    }else{
                        // std::cout << "2. pozostawiam m_bogieContainerIterator na " << m_bogieContainerIterator << std::endl;
                    }

                    // std::cout << "udalo sie dodac wozek\n";
                }else{
                // std::cout << "nie udalo sie dodac wozka\n";
                }
            }
        }   
    }
    m_RRtime++;

}
