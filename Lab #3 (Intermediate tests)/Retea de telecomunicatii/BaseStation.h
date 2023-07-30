#ifndef BASESTATION_H
#define BASESTATION_H
#include "Mobil.h"
class BaseStation{
    private:
        int nr;
        Mobil **vec;
    public:
        BaseStation(int);
        void add(int, int, int, std::string, std::string);
        void test1();
        void test2(int,int,std::string);
        void test3(std::string);
};


#endif