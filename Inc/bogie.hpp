#ifndef BOOGIE_HPP
#define BOOGIE_HPP

#include <iostream>
class Bogie
{
    enum class Game {
        rubiny,
        agaty
    };

private:
    int m_startTime;
    int m_ID;
    Game m_game;
    int m_weight;
    int m_amount;
    int m_duration;

public:
    Bogie(  int startTime, int ID,
            std::string gameName, int weight,
            int amount, int duration);
    ~Bogie();

    void setmStartTime(int startTime) {m_startTime = startTime;};
    void setID(int ID) {m_ID = ID;};
    void setGame(Game game){m_game = game;};
    void setWeight(int weight){m_weight = weight;};
    void setAmount(int amount){m_amount = amount;};
    void setDuration(int time){m_duration = time;};

    int getStartTime()const {return m_startTime;};
    int getID() const {return m_ID;};
    Game getGame() const {return m_game;};
    int getWeight() const {return m_weight;};
    int getAmount() const {return m_amount ;};
    int getDuration() const {return m_duration;};
};


#endif  // BOOGIE_HPP