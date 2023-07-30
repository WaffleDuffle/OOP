#include <iostream>
#include <string>
#include "Profil.h"

int main(){
    std::string temp_nume;
    float temp_sold_card;
    float temp_sold_cont;
    float temp_dobanda;
    int test;
    std::getline(std::cin,temp_nume);
    std::cin >> temp_sold_card;
    std::cin >> temp_sold_cont;
    std::cin >> temp_dobanda;
    std::cin >> test;
    Profil P(temp_nume, temp_sold_card, temp_sold_cont, temp_dobanda);
    switch(test){
        case 1:{
            P.display1();
            break;        
        }
        case 2:{
            float suma_bonus;
            std::cin >> suma_bonus;
            P.adaugare(suma_bonus);
            break;
        }
        case 3:{
            float diferenta_bonus;
            std::cin >> diferenta_bonus;
            P.diferenta(diferenta_bonus);
            break;
        }
        case 4:{
            float suma;
            std::cin >> suma;
            P.transfer(suma);
            break;
        }
        case 5:{
            float suma;
            std::cin >> suma;
            P.acumulare_dobanda(suma);
        }
    }
}