#ifndef MINE_HPP
#define MINE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "bogie.hpp"
#define BOGIES_NR 5
class Mine
{
private:
    std::map <int, Bogie> scheme;       // czas + taczka

public:
    Mine(/* args */);
    ~Mine();
    int InitScheme(std::string name);
};

#endif  // MINE_HPP