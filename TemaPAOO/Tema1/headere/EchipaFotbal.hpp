#ifndef ECHIPAFOTBAL_HPP
#define ECHIPAFOTBAL_HPP

class EchipaFotbal
{
private:
    int numarJucatori;
    std::string numeClub;

public:
    //Tema1
    EchipaFotbal();
    EchipaFotbal(int numarJucatori, std::string numeClub);
    EchipaFotbal(const EchipaFotbal &ef);
    EchipaFotbal &operator=(const EchipaFotbal &ef);
    void setNumarJucatori(int numarJucatori);
    int getNumarJucatori();
    void setNumeClub(std::string numeClub);
    std::string getNumeClub();
    virtual std::string informatii();
    //Tema2
    EchipaFotbal &operator+=(const EchipaFotbal &ef);
    virtual ~EchipaFotbal();
};

#endif