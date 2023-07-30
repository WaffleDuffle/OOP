#include "Cont_economii.h"
#include <iostream>
Cont_economii::Cont_economii(float sold_cont, float dobanda):sold_cont(sold_cont),dobanda(dobanda){}

float Cont_economii::get_sold_cont(){
    return sold_cont;
}

float Cont_economii::get_dobanda(){
    return dobanda;
}

void Cont_economii::cont_economii_display(){
    std::cout << "cont_economii:\n" << sold_cont << std::endl << dobanda << std::endl;
}

void Cont_economii::adaugare(float x){
    sold_cont = (sold_cont + x)*(dobanda/100 + 1);
}