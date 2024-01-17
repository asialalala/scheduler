#ifndef MINE_HPP
#define MINE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "bogie.hpp"
#define BOGIES_NR 5
class Mine
{
private:
    Bogie boogiesTab[BOGIES_NR];

public:
    Mine(/* args */);
    ~Mine();
    int InitBoogies(std::string name);
};

#endif  // MINE_HPP