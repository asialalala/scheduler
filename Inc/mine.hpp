#ifndef MINE_HPP
#define MINE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include "bogie.hpp"
#define BOGIES_NR 5

namespace Mine
{

    typedef std::vector<Bogie::Bogie> Scheme;
    enum Strategy{
        RR,
        FCFS
    };
class Mine
{
private:
    Scheme m_scheme;       // czas + taczka
    Strategy m_strategyName;
    int m_timeQuantum;
    int m_robotsNr;

public:
    Mine();
    ~Mine();
    int MineInit(char * argv []);
    int InitScheme(std::string name);
    void Report() ;
};
} // Mine namespace


#endif  // MINE_HPP