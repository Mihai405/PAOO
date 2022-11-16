#include <iostream>
#include <EchipaFotbal.hpp>
#include <Barcelona.hpp>
#include <RealMadrid.hpp>
#include <memory>
using namespace std;

EchipaFotbal*  createEchipaFotbalInstance() 
{
    return (new EchipaFotbal);
}

//Tema3 -> item14
class Teren{
    private:
        int arie = 100;
        bool ocupat = false;

    public:

    Teren(int arie){
        this->arie = arie;
    }

    Teren(const Teren &t){
        this->arie = t.arie;
        this->ocupat = t.ocupat;
    }

    ~Teren(){
        std::cout<<"Teren eliberat"<<std::endl;
    }

    int getArie(){
        return this->arie;
    }

    bool getOcupat(){
        return this->ocupat;
    }

    void setOcupat(bool ocupat){
        this->ocupat = ocupat;
    }

    void stareTeren(){
        if(this->ocupat == false) 
            std::cout<<"Teren liber"<<std::endl;
        else
            std::cout<<"Teren ocupat"<<std::endl;
    }
};

void lock(Teren &t){
    t.setOcupat(true);
}

void unlock(Teren &t){
    t.setOcupat(false);
}

class Fotbalist{
    private:
        Teren &teren;
    public:
    Fotbalist(Teren &t):
    teren(t){
        lock(teren);
    }
    ~Fotbalist(){
        unlock(teren);
    }
};

int main()
{
    EchipaFotbal ef;
    std::cout << ef.getNumeClub() << std::endl;
    
    Barcelona barcelona;
    // Barcelona barcelona2 = barcelona; //copy constructor cu delete
    RealMadrid real;

    {
        EchipaFotbal ef3;
    }

    EchipaFotbal ef2(20, "Ac Milan");

    EchipaFotbal ef3 = ef; //copy constructor
    EchipaFotbal ef4(ef); //copy constructor

    ef2 = real; //copy assignment operator

    EchipaFotbal *ef5 = new Barcelona();
    std::cout << ef5->informatii() << std::endl; //functie cu virtual

    ef.setNumarJucatori(40);
    std::cout << ef.getNumarJucatori() << std::endl;
    std::cout << barcelona.getNumarJucatori() << " " + barcelona.getNumeClub() << std::endl;
    real.setNumarJucatori(25);
    std::cout << real.getNumarJucatori() << std::endl;
    std::cout << ef2.getNumeClub() << std::endl;

    //Tema2 -> item10
    EchipaFotbal ef21(11, "Steaua");
    EchipaFotbal ef22(15, "Dinamo");
    EchipaFotbal ef23(17, "Rapid");
    ef21 += ef22 += ef23;
    std::cout << ef21.getNumarJucatori() << std::endl;

    //Tema2 -> item11
    EchipaFotbal ef24;
    ef24 = ef24;

    //Tema2 -> item12
    Barcelona barcelona21(15, "Fc Barcelona2", 100);
    Barcelona barcelona22(20, "Fc Barcelona3", 150);  
    barcelona21 = barcelona22;
    std::cout << barcelona21.getNumarJucatori() << " " + barcelona21.getNumeClub() << std::endl;
    std::cout << barcelona21.getFani() << std::endl;

    //Tema3 -> item13
    {
        auto_ptr<EchipaFotbal> echipaFotbal1(createEchipaFotbalInstance());
        auto_ptr<EchipaFotbal> echipaFotbal2(echipaFotbal1);
        //echipaFotbal1->getNumarJucatori();  //SEGMENTATION FAULT
    }

    {
        unique_ptr<EchipaFotbal> echipaFotbal1(createEchipaFotbalInstance());
        // unique_ptr<EchipaFotbal> echipaFotbal2(echipaFotbal1);
        unique_ptr<EchipaFotbal> echipaFotbal2 = move(echipaFotbal1); //schimbare ownership
        // std::cout << "Aici " + echipaFotbal1->getNumeClub() << std::endl;
    }

    {
        shared_ptr<EchipaFotbal> echipaFotbal1(createEchipaFotbalInstance());
        shared_ptr<EchipaFotbal> echipaFotbal2(echipaFotbal1); 
        std::cout<<"Shared1 "<<echipaFotbal1.use_count()<<std::endl;
        shared_ptr<EchipaFotbal> echipaFotbal3 = move(echipaFotbal1);
        std::cout<<"Shared2 "<<echipaFotbal1.use_count()<<std::endl;
        std::cout<<"Shared3 "<<echipaFotbal3.use_count()<<std::endl;
    }
    Tema4 -> Item14
    Teren t(1400);
    Fotbalist *fotbalist = new Fotbalist(t);
    t.stareTeren();
    delete fotbalist;
    t.stareTeren();
    lock(t);
    t.stareTeren();
    unlock(t);
    t.stareTeren();
}