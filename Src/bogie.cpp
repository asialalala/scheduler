#include "../Inc/bogie.hpp"

Bogie::Bogie::Bogie(   int startTime, int ID,
                std::string gameName, int weight,
                int amount): 
                m_startTime(startTime),
                m_ID(ID),
                m_weight(weight),
                m_amount(amount)
{
    m_duration = amount * weight;
    
    int result = gameName.compare("rubiny");
    if(result == 0)
        m_game = Game::rubiny;
    
    result = gameName.compare("agaty");
    if(result == 0)
        m_game = Game::agaty;
    
    result = gameName.compare("zloto");
    if(result == 0)
        m_game = Game::zloto;

    result = gameName.compare("turkus");
    if(result == 0)
        m_game = Game::turkus;
    
}

std::string Bogie::Bogie::getGameName() const
{
    switch(m_game)
    {
        case Game::agaty :
            return "agat";
        case Game::rubiny :
            return "rubin";
        case Game::zloto :
            return "zloto";
        case Game::turkus :
            return "turkus";
        default : 
            return "niezdefiniowany";
    }
}