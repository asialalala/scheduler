#include "bogie.hpp"
#ifndef ROBOT_H
#define ROBOT_H

namespace Robot
{

    class Robot
    {
    private:
        Bogie::Bogie *m_pBogie; // wagonik, ktory obsluguje robot
        int m_workingTime;
    public:
        Robot();
        ~Robot(){};
        int IncreaseWorkingTime();
        Bogie::Bogie* FinishJob();
        bool StartJob(Bogie::Bogie* pBogie);
        Bogie::Bogie* getBogie();
        int getTimeToEnd();
    };

    typedef std::vector<Robot> RobotsContainer;
    
} // namespace Robot
#endif
