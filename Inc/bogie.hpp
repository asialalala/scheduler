#ifndef BOOGIE_HPP
#define BOOGIE_HPP

#include <iostream>
#include <vector>

namespace Bogie
{
    enum Game
    {
        rubiny,
        agaty,
        zloto,
        turkus,
        gold,
        rubins,
        coconuts,
        turquoise,
        aventurines,
        beryls,
        sapphires,
        emeralds,
        opals,
        amethysts,
        topazes,
        pearls,
        aquamarines
    };

    class Bogie
    {
    private:
        int m_startTime;
        int m_ID;
        Game m_game;
        int m_weight;
        int m_amount;
        int m_duration;
        bool m_served;

    public:
        Bogie(int startTime, int ID,
              std::string gameName, int weight,
              int amount);
        Bogie(int startTime, int ID,
              std::string gameName, int weight,
              int amount, int duration);
        ~Bogie(){};

        void setmStartTime(int startTime) { m_startTime = startTime; };
        void setID(int ID) { m_ID = ID; };
        void setGame(Game game) { m_game = game; };
        void setWeight(int weight) { m_weight = weight; };
        void setAmount(int amount) { m_amount = amount; };
        void setDuration(int time) { m_duration = time; };
        void setGameName(std::string gameName);

        int getStartTime() const { return m_startTime; };
        int getID() const { return m_ID; };
        Game getGame() const { return m_game; };
        std::string getGameName() const;
        int getWeight() const { return m_weight; };
        int getAmount() const { return m_amount; };
        int getDuration() const { return m_duration; };
        void setServed() { m_served = true; };
        bool getServedInfo() const { return m_served; };
        void freeServed() { m_served = false; };
    };

    typedef std::vector<Bogie> BogieContainer;
} // namespace Bogie

#endif // BOOGIE_HPP
