#include "../Inc/robot.hpp"

Robot::Robot::Robot()
{
    m_pBogie = nullptr;
    m_workingTime = 0;
    m_outOfWorkState = true;
    m_bogieIdInBogiesContainer = NONE_BOGIE;
}

int Robot::Robot::IncreaseWorkingTime()
{
    if (m_pBogie == nullptr)
    {
        // std::cout << "Robot nie ma nad czym pracowac, wiec nie zwieksza godzin pracy\n";
        return m_workingTime;
    }
    //  std::cout << "Robot zwiekszyl czas pracy do " << m_workingTime + 1 << std::endl;
    //  std::cout << "      " << m_pBogie->getID() << " " << m_pBogie->getGameName() <<std::endl;
    return ++m_workingTime;
}

int Robot::Robot::FinishJob()
{
    if (m_pBogie == nullptr)
    {
        // std::cout << "Robot nie moze zakonczyc pracy, bo i tak nad niczym nie pracuje\n";
        return -1;
    }
    else if (getTimeToEnd() > 0)
    {
        // std::cout << "Robot nie moze zakonczyc pracy, bo za krotko rozpakowywal wozek.\n";
        // std::cout << "      " << m_pBogie->getID() << " " << m_pBogie->getGameName() <<std::endl;
        return -1;
    }
    // std::cout << "Robot konczy prace.\n";
    int temp = m_bogieIdInBogiesContainer;
    m_bogieIdInBogiesContainer = NONE_BOGIE;
    m_pBogie = nullptr;
    m_outOfWorkState = true;
    m_workingTime = 0;
    return temp; // zwroc numer wozka w kontenerze
}

int Robot::Robot::FinishJobForced()
{
    if (m_pBogie == nullptr)
    {
        // std::cout << "Robot nie moze zakonczyc pracy, bo i tak nad niczym nie pracuje\n";
        return -1;
    }
    // std::cout << "Robot konczy prace.\n";
    int temp = m_bogieIdInBogiesContainer;
    m_bogieIdInBogiesContainer = NONE_BOGIE;
    m_pBogie = nullptr;
    m_outOfWorkState = true;
    m_workingTime = 0;
    return temp; // zwroc numer wozka w kontenerze
}

bool Robot::Robot::StartJob(Bogie::Bogie *const pBogie, int idInContainer)
{
    // std::cout << "Proba przypisania wozka o ID: " << pBogie->getID();
    if (m_pBogie != nullptr)
    {
        // std::cout << "Robot nie moze zaczac pracy, poniewaz nie zakonczyl poprzedniej z wzokiem.\n" << m_pBogie->getID() << " " << m_pBogie->getGameName() <<std::endl;
        return false;
    }
    Bogie::Bogie *newBogie = new Bogie::Bogie(pBogie->getStartTime(), pBogie->getID(),
                                              pBogie->getGameName(), pBogie->getWeight(), pBogie->getAmount(), pBogie->getDuration());
    m_pBogie = newBogie;
    m_outOfWorkState = false;
    m_bogieIdInBogiesContainer = idInContainer;
    // std::cout << "Robot zaczyna prace  z "  << m_pBogie->getGameName()  << m_pBogie->getDuration() <<std::endl;
    return true;
}

Bogie::Bogie *Robot::Robot::getBogie()
{
    if (m_pBogie == nullptr)
    {
        // std::cout << "Robot oddaje pusty wskaznik, bo nad niczym nie pracuje\n";
    }
    return m_pBogie;
}

int const Robot::Robot::getTimeToEnd() const
{
    if (m_pBogie == nullptr)
    {
        //  std::cout << " Robot nad niczym nie pracuje, czas od zakonczenia: 0 \n";
        return 0;
    }
    //  std::cout << "Czas do zakonczone " << m_pBogie->getDuration()<< " - " <<  m_workingTime << " = " <<  m_pBogie->getDuration() - m_workingTime <<std::endl ;
    return m_pBogie->getDuration() - m_workingTime;
}

bool Robot::Robot::getOutOfWorkState()
{
    return m_outOfWorkState;
}