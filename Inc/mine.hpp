#ifndef MINE_HPP
#define MINE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include "bogie.hpp"
#include "robot.hpp"

namespace Mine
{
    enum Strategy{
        RR,
        FCFS
    };
class Mine
{
    private:
        Bogie::BogieContainer m_bogieContainer;
        Strategy m_strategyName;
        Robot::RobotsContainer m_robotsContainer;
        int m_timeQuantum;
        int m_robotsNr;
    
    public:
        Mine();
        ~Mine();
        int MineInit(char * argv []);
        int InitScheme();
        int InitScheme(std::string name);
        void Report() ;
};
} // Mine namespace


#endif  // MINE_HPP