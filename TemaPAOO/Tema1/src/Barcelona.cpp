#include <iostream>
#include <Barcelona.hpp>

Barcelona::Barcelona() : EchipaFotbal(11, "FC Barcelona")
{
}

Barcelona::Barcelona(int numarJucatori, std::string numeClub, int fani) : EchipaFotbal(numarJucatori, numeClub), fani(fani){}

Barcelona& Barcelona::operator=(const Barcelona &b)
{
    //Tema2 -> Item12
    if(this == &b) {
        std::cout << "Aceeasi referinta" << std::endl;
        return *this;
    }
    EchipaFotbal::operator=(b); //daca nu se pune asta se actualizeaza doar fanii
    this->fani = b.fani;
    return *this;
}

void Barcelona::setNumarJucatori(int numarJucatori)
{
    std::cout << "Apel setNumarJucatori in subclasa EchipaFotbal" << numarJucatori <<std::endl;
}

std::string Barcelona::informatii() 
{
    return "Informatii Barcelona";
}

int Barcelona::getFani() 
{
    return fani;
}

Barcelona::~Barcelona()
{
    std::cout << "Echipa Barcelona stearsa" << std::endl;
}