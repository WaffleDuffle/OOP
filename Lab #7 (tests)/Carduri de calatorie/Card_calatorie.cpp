#include "Card_calatorie.h"
#include <iostream>

Card_calatorie::Card_calatorie(int id, char tip):id(id),tip(tip),moment_ultima_validare(0){}

void Card_calatorie::display(){
    std::cout << this->id << " " << this->tip << " " << this->moment_ultima_validare << std::endl;
}

char Card_calatorie::get_tip(){
    return this->tip;
}

int Card_calatorie::get_id(){
    return this->id;
}

int Card_calatorie::get_moment(){
    return this->moment_ultima_validare;
}

void Card_calatorie::set_moment(int moment_ultima_validare){
    this->moment_ultima_validare = moment_ultima_validare;
}