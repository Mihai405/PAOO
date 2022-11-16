#ifndef BARCELONA_HPP
#define BARCELONA_HPP
#include <EchipaFotbal.hpp>

class Barcelona : public EchipaFotbal
{

private:
    int fani;

public:
    Barcelona();
    Barcelona(int numarJucatori, std::string numeClub, int fani);
    Barcelona(const Barcelona &b) = delete;
    Barcelona &operator=(const Barcelona &b);
    void setNumarJucatori(int numarJucatori);
    std::string informatii();
    //Tema2 -> item12
    int getFani();
    ~Barcelona();
};

#endif