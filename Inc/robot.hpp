#include "bogie.hpp"
#ifndef ROBOT_H
#define ROBOT_H

namespace Robot
{

    class Robot
    {
    private:
        Bogie::Bogie bogie; // wagonik, ktory obsluguje robot
    public:
        Robot();
        ~Robot(){};
    };

    typedef std::vector<Robot> RobotsContainer;
    
} // namespace Robot
#endif
