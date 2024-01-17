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
class Mine
{
private:
    std::vector <Bogie> scheme;       // czas + taczka

public:
    Mine(/* args */);
    ~Mine();
    int InitScheme(std::string name);
};
} // Mine namespace


#endif  // MINE_HPP