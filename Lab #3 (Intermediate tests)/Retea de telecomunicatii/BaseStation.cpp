#include "BaseStation.h"
#include "Mobil.h"
#include <cmath>
#include <iostream>
#include <string>
BaseStation::BaseStation(int nr):nr(nr){
    vec = new Mobil*[nr];
}

void BaseStation::add(int x, int identificator, int distanta, std::string mesaj_primit, std::string mesaj_transmis){
    vec[x] = new Mobil(identificator, distanta, mesaj_primit, mesaj_transmis);
}

void BaseStation::test1(){
    for(int i = 0 ; i < nr ; ++i)
        vec[i]->display();
    
}

void BaseStation::test2(int temp_id1, int temp_id2, std::string mesaj2){
    int x, y;
    for(int i = 0 ; i < nr ; ++i){
        if(temp_id1 == vec[i]->get_id())
            x = i;
        if(temp_id2 == vec[i]->get_id())
            y = i;
    }
    if((vec[x]->get_distanta() < 1500) && (vec[y]->get_distanta()) > 1500){
        vec[x]->display_primit();
        std::cout << mesaj2 << std::endl;
        vec[y]->display();
    }
    else if((vec[x]->get_distanta() > 1500)){
        vec[x]->display();
        vec[y]->display();
    }
    else{
        vec[x]->display_primit();
        std::cout << mesaj2 << std::endl;
        vec[y]->display_nr();
        std::cout << mesaj2 << " ";
        std::cout << vec[y]->get_mesaj_transmis() << std::endl;
        
    }
    
}

void BaseStation::test3(std::string mesaj){
    for(int i = 0 ; i < nr ; ++i){
        if(vec[i]->get_distanta() < 1500){
            vec[i]->display_nr();
            std::cout << mesaj << " ";
            std::cout << vec[i]->get_mesaj_transmis() << std::endl;
        }
        else{
            vec[i]->display_nr();
            std::cout << vec[i]->get_mesaj_primit() << " " << vec[i]->get_mesaj_transmis() << std::endl;
        }
    }
}







