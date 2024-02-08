#ifndef MINE_HPP
#define MINE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include "bogie.hpp"
#include "robot.hpp"

#define WRONG_FILE -1

namespace Mine
{
    enum Strategy
    {
        RR,
        FCFS
    };

    class Mine
    {
    private:
        Bogie::BogieContainer m_bogieContainer;
        Strategy m_strategyName;
        Robot::RobotsContainer m_robotsContainer;
        int m_robotsNr;
        int m_bogieContainerIterator;
        int m_arrivingBogieIterator;
        int m_lastArrvied;
        int m_lackOfBogie;
        bool m_endOfreading;
        int m_quantum;
        int m_RRtime;

        int UploadBogieContainer();
        int UploadBogieContainer(std::string name);
        void Report(int time);
        void ScheduleFCFS();
        void ScheduleRR();
        bool checkIfEnd();
        bool m_added;

    public:
        Mine(int robotsNr, int quantum);
        ~Mine();
        int MineInit(char *argv[]);
        int Schedule();
        int Schedule(std::string name);
    };
} // Mine namespace

#endif // MINE_HPP
