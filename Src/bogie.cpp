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
    
    result = gameName.compare("gold");
    if(result == 0)
        m_game = gold;

    result = gameName.compare("coconuts");
    if(result == 0)
        m_game = coconuts;

    result = gameName.compare("turquoise");
    if(result == 0)
        m_game = turquoise;

    result = gameName.compare("aventurines");
    if(result == 0)
        m_game = aventurines;

    result = gameName.compare("beryls");
    if(result == 0)
        m_game = beryls;

    result = gameName.compare("sapphires");
    if(result == 0)
        m_game = sapphires;

    result = gameName.compare("emeralds");
    if(result == 0)
        m_game = emeralds;

    result = gameName.compare("opals");
    if(result == 0)
        m_game = opals;

    result = gameName.compare("amethysts");
    if(result == 0)
        m_game = amethysts;

    result = gameName.compare("topazes");
    if(result == 0)
        m_game = topazes;

    result = gameName.compare("pearls");
    if(result == 0)
        m_game = pearls;

    result = gameName.compare("aquamarines");
    if(result == 0)
        m_game = aquamarines;

    
    // std::cout << "  W chwili " << startTime << " dodano wozek z kamieniami " << getGameName() << " potrwa " << m_duration << std::endl;
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
        case gold :
            return "gold";
        case rubins :
            return "rubins";
        case coconuts :
            return "coconuts";
        case turquoise :
            return "turquoise";
        case aventurines :
            return "aventurines";
        case beryls :
            return "beryls";
        case sapphires :
            return "sapphires";
        case emeralds :
            return "emeralds";
        case opals :
            return "opals";
        case amethysts :
            return "amethysts";
        case topazes :
            return "topazes";
        case pearls :
            return "pearls";
        case aquamarines :
            return "aquamarines";
        default : 
            return "niezdefiniowany";
    }
}