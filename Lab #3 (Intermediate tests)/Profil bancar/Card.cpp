#include "Card.h"
#include <iostream>
Card::Card(float sold_card):sold_card(sold_card){}

float Card::get_sold_card(){
    return sold_card;
}

void Card::card_display(){
    std::cout << "card_bancar:\n" << sold_card << std::endl;
}

void Card::adaugare_sold(float x){
    sold_card += x;
}

void Card::diferenta_sold(float x){
    sold_card -= x;
}