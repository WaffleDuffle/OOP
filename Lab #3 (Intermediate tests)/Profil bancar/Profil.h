#ifndef PROFIL_H
#define PROFIL_H
#include "Card.h"
#include "Cont_economii.h"
#include <string>
class Profil{
    private:
        std::string nume;
        Card card;
        Cont_economii cont;
    public:
        Profil(std::string, float, float, float);
        void display1();
        void adaugare(float);
        void diferenta(float);
        void transfer(float);
        void acumulare_dobanda(float);
};
#endif