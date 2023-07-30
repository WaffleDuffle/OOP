#include "Mobil.h"
#include <iostream>
Mobil::Mobil(int identificator=0, int distanta=0, std::string mesaj_primit="", std::string mesaj_transmis=""):identificator(identificator), distanta(distanta),
                                                                                                    mesaj_primit(mesaj_primit),mesaj_transmis(mesaj_transmis){}
                                                                                                    
void Mobil::display(){
    std::cout << identificator << " " << distanta << " " << mesaj_primit << " " << mesaj_transmis << std::endl;
}

int Mobil::get_id(){
    return identificator;
}

int Mobil::get_distanta(){
    return distanta;
}

std::string Mobil::get_mesaj_transmis(){
    return mesaj_transmis;
}

std::string Mobil::get_mesaj_primit(){
    return mesaj_primit;
}

void Mobil::display_primit(){
    std::cout << identificator << " " << distanta << " " << mesaj_primit << " ";
}

void Mobil::display_transmis(){
    std::cout << identificator << " " << distanta << " " << mesaj_transmis << " ";
}

void Mobil::display_nr(){
    std::cout << identificator << " " << distanta << " ";
}