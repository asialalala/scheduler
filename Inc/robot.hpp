#include "bogie.hpp"
#ifndef ROBOT_H
#define ROBOT_H

namespace Robot
{

    class Robot
    {
    private:
        Bogie::BogieContainer m_bogieContainer; // wagoniki, ktore obsluguje robot
    public:
        Robot();
        ~Robot(){};
    };

    typedef std::vector<Robot> RobotsContainer;
    
} // namespace Robot
#endif
