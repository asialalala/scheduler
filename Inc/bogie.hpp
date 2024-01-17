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
    int m_ID;
    Game m_game;
    int m_weight;
    int m_amount;
    int m_time;

public:
    Bogie();
    ~Bogie();

    void setID(int ID) {m_ID = ID;};
    void setGame(Game game){m_game = game;};
    void setWeight(int weight){m_weight = weight;};
    void setAmount(int amount){m_amount = amount;};
    void setTime(int time){m_time = time;};
};


#endif  // BOOGIE_HPP