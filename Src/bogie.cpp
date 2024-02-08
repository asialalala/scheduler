#include "../Inc/bogie.hpp"

void Bogie::Bogie::setGameName(std::string gameName)
{
    int result = gameName == "rubiny";
    if (result == 0)
        m_game = rubiny;

    result = gameName == "agaty";
    if (result == 0)
        m_game = agaty;

    result = gameName == "zloto";
    if (result == 0)
        m_game = zloto;

    result = gameName == "turkus";
    if (result == 0)
        m_game = turkus;

    result = gameName == "gold";
    if (result == 0)
        m_game = gold;

    result = gameName == "coconuts";
    if (result == 0)
        m_game = coconuts;

    result = gameName == "turquoise";
    if (result == 0)
        m_game = turquoise;

    result = gameName == "aventurines";
    if (result == 0)
        m_game = aventurines;

    result = gameName == "beryls";
    if (result == 0)
        m_game = beryls;

    result = gameName == "sapphires";
    if (result == 0)
        m_game = sapphires;

    result = gameName == "emeralds";
    if (result == 0)
        m_game = emeralds;

    result = gameName == "opals";
    if (result == 0)
        m_game = opals;

    result = gameName == "amethysts";
    if (result == 0)
        m_game = amethysts;

    result = gameName == "topazes";
    if (result == 0)
        m_game = topazes;

    result = gameName == "pearls";
    if (result == 0)
        m_game = pearls;

    result = gameName == "aquamarines";
    if (result == 0)
        m_game = aquamarines;
}

Bogie::Bogie::Bogie(int startTime, int ID,
                    std::string gameName, int weight,
                    int amount) : m_startTime(startTime),
                                  m_ID(ID),
                                  m_weight(weight),
                                  m_amount(amount),
                                  m_served(false)
{
    m_duration = amount * weight;

    setGameName(gameName);

    // std::cout << "  W chwili " << startTime << " dodano wozek z kamieniami " << getGameName() << " potrwa " << m_duration << std::endl;
}

Bogie::Bogie::Bogie(int startTime, int ID,
                    std::string gameName, int weight,
                    int amount, int duration) : m_startTime(startTime),
                                                m_ID(ID),
                                                m_weight(weight),
                                                m_amount(amount),
                                                m_duration(duration),
                                                m_served(false)
                                                
{
    setGameName(gameName);
}

std::string Bogie::Bogie::getGameName() const
{
    switch (m_game)
    {
    case agaty:
        return "agaty";
    case rubiny:
        return "rubiny";
    case zloto:
        return "zloto";
    case turkus:
        return "turkus";
    case gold:
        return "gold";
    case rubins:
        return "rubins";
    case coconuts:
        return "coconuts";
    case turquoise:
        return "turquoise";
    case aventurines:
        return "aventurines";
    case beryls:
        return "beryls";
    case sapphires:
        return "sapphires";
    case emeralds:
        return "emeralds";
    case opals:
        return "opals";
    case amethysts:
        return "amethysts";
    case topazes:
        return "topazes";
    case pearls:
        return "pearls";
    case aquamarines:
        return "aquamarines";
    default:
        return "niezdefiniowany";
    }
}
