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
class Mine
{
private:
    Scheme scheme;       // czas + taczka

public:
    Mine(/* args */);
    ~Mine();
    int InitScheme(std::string name);
    void Report() ;
};
} // Mine namespace


#endif  // MINE_HPP