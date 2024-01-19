#include "../Inc/robot.hpp"

Robot::Robot::Robot()
{
    m_pBogie = nullptr;
    m_workingTime = 0;
}

int Robot::Robot::IncreaseWorkingTime()
{
    if(m_pBogie == nullptr)
    {
        std::cout << "Robot nie ma nad czym pracowac, wiec nie zwieksza godzin pracy\n";
        return m_workingTime;
    }
    return ++m_workingTime;
}

Bogie::Bogie* Robot::Robot::FinishJob()
{
    if(m_pBogie == nullptr)
    {
        std::cout << "Robot nie moze zakonczyc pracy, bo i tak nad niczym nie pracuje\n";
        return nullptr;
    }
    Bogie::Bogie* temp;
    temp = m_pBogie;
    m_pBogie = nullptr;
    return temp;    // zwroc wskaznik na wzek, z ktorym pracowalej
}

bool Robot::Robot::StartJob(Bogie::Bogie* pBogie)
{
    if(m_pBogie != nullptr)
    {
        std::cout << "Robot nie moze zaczac pracy, poniewaz nie zakonczyl poprzedniej.\n";
        return false;
    }
    m_pBogie = pBogie;
    return true;
}

Bogie::Bogie* Robot::Robot::getBogie()
{
    if(m_pBogie == nullptr)
    {
        std::cout << "Robot oddaje pusty wskaznik, bo nad niczym nie pracuje\n";
    }
    return m_pBogie;
}

int Robot::Robot::getTimeToEnd()
{
    if(m_pBogie == nullptr)
    {
        return 0;
    }
    return m_pBogie->getDuration() - m_workingTime;
}