#ifndef ROBOT_H
#define ROBOT_H
#include "bogie.hpp"

#define NONE_BOGIE -1
namespace Robot
{

    class Robot
    {
    private:
        Bogie::Bogie *m_pBogie; // wagonik, ktory obsluguje robot
        int m_workingTime;
        bool m_outOfWorkState;
        int m_bogieIdInBogiesContainer;

    public:
        Robot();
        ~Robot(){};
        int IncreaseWorkingTime();
        int FinishJob();
        bool StartJob(Bogie::Bogie *const pBogie, int idInContainer);
        Bogie::Bogie *getBogie();
        int const getTimeToEnd() const;
        bool getOutOfWorkState();
        int FinishJobForced();
    };

    typedef std::vector<Robot> RobotsContainer;

} // namespace Robot
#endif
