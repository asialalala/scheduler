#ifndef ROBOT_H
#define ROBOT_H
#include "bogie.hpp"

namespace Robot
{

    class Robot
    {
    private:
        Bogie::Bogie *m_pBogie; // wagonik, ktory obsluguje robot
        int m_workingTime;
        bool m_outOfWorkState;
    public:
        Robot();
        ~Robot(){};
        int IncreaseWorkingTime();
        Bogie::Bogie* FinishJob();
        bool StartJob(Bogie::Bogie* const pBogie);
        Bogie::Bogie* getBogie();
        int const getTimeToEnd() const;
        bool getOutOfWorkState();
        
    };

    typedef std::vector<Robot> RobotsContainer;
    
    
} // namespace Robot
#endif
