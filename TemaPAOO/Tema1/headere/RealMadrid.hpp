#ifndef REALMADRID_HPP
#define REALMADRID_HPP
#include <EchipaFotbal.hpp>

class RealMadrid : public EchipaFotbal
{
    
public:
    RealMadrid();
    RealMadrid(const RealMadrid &r) = delete;
    RealMadrid &operator=(const RealMadrid &r);
    ~RealMadrid();
};

#endif