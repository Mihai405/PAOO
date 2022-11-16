#include <iostream>
#include <RealMadrid.hpp>

RealMadrid::RealMadrid() : EchipaFotbal(11, "Real Madrid")
{
}

RealMadrid::~RealMadrid()
{
    std::cout << "Echipa Real Madrid stearsa" << std::endl;
}