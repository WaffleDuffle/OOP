#include "Profil.h"
#include <iostream>
Profil::Profil(std::string nume, float sold_card, float sold_cont, float dobanda):nume(nume), card(sold_card),
                                                                                cont(sold_cont, dobanda){}
                                                                                
void Profil::display1(){
    std::cout << nume << std::endl;
    card.card_display();
    cont.cont_economii_display();
}

void Profil::adaugare(float x){
    if(x < 0)
        std::cout << "EROARE: depunere suma negativa";
    else{
        card.adaugare_sold(x);
        card.card_display();
    }
        
}

void Profil::diferenta(float x){
    if(card.get_sold_card() < x)
        std::cout << "EROARE: fonduri insuficiente";
    else{
        card.diferenta_sold(x);
        card.card_display();
    }
}

void Profil::transfer(float x){
    if(card.get_sold_card() < x)
        std::cout << "EROARE: fonduri insuficiente";
    else{
        card.diferenta_sold(x);
        cont.adaugare(x);
        card.card_display();
        cont.cont_economii_display();
    }
}

void Profil::acumulare_dobanda(float x){
    int nr = 0;
    float temp_sold = cont.get_sold_cont();
    float temp_dobanda = cont.get_dobanda();
    while(temp_sold < x){
        temp_sold = temp_sold *(temp_dobanda/100 + 1);
        nr++;
    }
    std::cout << nr;
}











