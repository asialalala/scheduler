#include "../Inc/bogie.hpp"

Bogie::Bogie(   int startTime, int ID,
                std::string gameName, int weight,
                int amount, int duration): 
                m_startTime(startTime),
                m_ID(ID),
                m_weight(weight),
                m_amount(amount),
                m_duration(duration)
{
    int result = gameName.compare("rubiny");
    if(result == 0)
        m_game = Game::rubiny;
    
    result = gameName.compare("agaty");
    if(result == 0)
        m_game = Game::agaty;
}

Bogie::~Bogie()
{
}