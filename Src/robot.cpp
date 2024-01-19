#include "../Inc/robot.hpp"

Robot::Robot::Robot()
{
    m_pBogie = nullptr;
    m_workingTime = 0;
    m_outOfWorkState = true;
}

int Robot::Robot::IncreaseWorkingTime()
{
    if(m_pBogie == nullptr)
    {
        // std::cout << "Robot nie ma nad czym pracowac, wiec nie zwieksza godzin pracy\n";
        return m_workingTime;
    }
    //  std::cout << "Robot zwiekszyl czas pracy do " << m_workingTime + 1 << std::endl;
    return ++m_workingTime;
}

Bogie::Bogie* Robot::Robot::FinishJob()
{
    if(m_pBogie == nullptr)
    {
        // std::cout << "Robot nie moze zakonczyc pracy, bo i tak nad niczym nie pracuje\n";
        return nullptr;
    }else if(getTimeToEnd() > 0)
    {
        // std::cout << "Robot nie moze zakonczyc pracy, bo za krotko rozpakowywal wozek.\n";
        return nullptr;
    }
    // std::cout << "Robot konczy prace.\n";
    Bogie::Bogie* temp;
    temp = m_pBogie;
    m_pBogie = nullptr;
    m_outOfWorkState = true;
    return temp;    // zwroc wskaznik na wzek, z ktorym pracowalej
}

bool Robot::Robot::StartJob(Bogie::Bogie* const pBogie )
{
    // std::cout << "ID " << pBogie->getID()<< "trwanie" << pBogie->getDuration() <<std::endl;
    if(m_pBogie != nullptr)
    {
        // std::cout << "Robot nie moze zaczac pracy, poniewaz nie zakonczyl poprzedniej.\n";
        return false;
    }
    // std::cout << "Robot zaczyna prace\n";
    m_pBogie = pBogie;
    m_outOfWorkState = false;
    return true;
}

Bogie::Bogie* Robot::Robot::getBogie()
{
    if(m_pBogie == nullptr)
    {
        // std::cout << "Robot oddaje pusty wskaznik, bo nad niczym nie pracuje\n";
    }
    return m_pBogie;
}

int const Robot::Robot::getTimeToEnd() const
{
    if(m_pBogie == nullptr)
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