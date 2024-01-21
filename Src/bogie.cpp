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
        m_game = rubiny;
    
    result = gameName.compare("agaty");
    if(result == 0)
        m_game = agaty;
    
    result = gameName.compare("zloto");
    if(result == 0)
        m_game = zloto;

    result = gameName.compare("turkus");
    if(result == 0)
        m_game = turkus;
    
    std::cout << "  W chwili " << startTime << " dodano wozek z kamieniami " << getGameName() << " potrwa " << m_duration << std::endl;
}

std::string Bogie::Bogie::getGameName() const
{
    switch(m_game)
    {
        case agaty :
            return "agaty";
        case rubiny :
            return "rubiny";
        case zloto :
            return "zloto";
        case turkus :
            return "turkus";
        default : 
            return "niezdefiniowany";
    }
}