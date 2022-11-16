#include <iostream>
#include <EchipaFotbal.hpp>

EchipaFotbal::EchipaFotbal() :   numarJucatori(24),
                                 numeClub("Echipa Fotbal Default")
{
}

EchipaFotbal::EchipaFotbal(int numarJucatori, std::string numeClub) :   numarJucatori(numarJucatori),
                                                                        numeClub(numeClub)
{
}

EchipaFotbal::EchipaFotbal(const EchipaFotbal &ef)
{
    std::cout << "Copy Constructor" << std::endl;
    this->numarJucatori= ef.numarJucatori;
    this->numeClub = ef.numeClub;
}

EchipaFotbal& EchipaFotbal::operator=(const EchipaFotbal &ef)
{
    //Tema2 -> Item11
    if(this == &ef) {
        std::cout << "Aceeasi referinta" << std::endl;
        return *this;
    }
    std::cout << "Copy Assignment Operator" << std::endl;
    this->numarJucatori = ef.numarJucatori;
    this->numeClub = ef.numeClub;
    return *this;
}

void EchipaFotbal::setNumarJucatori(int numar)
{
    numarJucatori = numar;
}

int EchipaFotbal::getNumarJucatori()
{
    return numarJucatori;
}

void EchipaFotbal::setNumeClub(std::string nume)
{
    numeClub = nume;
}

std::string EchipaFotbal::getNumeClub()
{
    return numeClub;
}

std::string EchipaFotbal::informatii()
{
   return "Informatii Echipa Fotbal";  
}

//Tema2
EchipaFotbal& EchipaFotbal::operator+=(const EchipaFotbal &ef) {
    std::cout << "Plus operator" << std::endl;
    this->numarJucatori += ef.numarJucatori;
    return *this;
}

EchipaFotbal::~EchipaFotbal()
{
    std::cout << "Echipa " + numeClub + " stearsa" << std::endl;
}