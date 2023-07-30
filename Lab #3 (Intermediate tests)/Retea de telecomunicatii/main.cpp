#include <iostream>
#include "BaseStation.h"
#include <string>
int main(){
    int n;
    int temp_id;
    int temp_distanta;
    std::string temp_mesaj_primit;
    std::string temp_mesaj_transmis;
    std::cin >> n;
    BaseStation B(n);
    for(int i = 0 ; i < n ; ++i){
        std::cin >> temp_id;
        std::cin >> temp_distanta;
        std::cin.ignore();
        std::getline(std::cin,temp_mesaj_primit);
        std::getline(std::cin,temp_mesaj_transmis);
        B.add(i,temp_id,temp_distanta,temp_mesaj_primit,temp_mesaj_transmis);
    }
    int test;
    std::cin >> test;
    switch(test){
        case 1:{
            B.test1();
            break;
        }
        case 2:{
            int id1;
            int id2;
            std::string mesaj;
            std::cin >> id1;
            std::cin >> id2;
            std::cin.ignore();
            std::getline(std::cin,mesaj);
            B.test2(id1,id2,mesaj);
            break;
        }
        case 3:{
            std::string mesaj3;
            std::cin.ignore();
            std::getline(std::cin,mesaj3);
            B.test3(mesaj3);
            break;
        }
        case 4:{
            int n4;
            std::string text;
            std::cin >> n4;
            BaseStation B4(n)
            for(int i = 0 ; i < n4 ; ++i){
                std::cin.ignore();
                std::getline(std::cin, text);
                if(text == "mesaj"){
                    int id1, id2;
                    std::string mesaj2;
                    std::cin >> id1 >> id2;
                    std::cin.ignore();
                    std::getline(std::cin,mesaj2);
                    
                    
                }
                else if(text == "broadcast"){
                    std::string mesaj3;
                    std::cin.ignore();
                    std::getline(std::cin,mesaj3);
                    
                }
                
            }
            break;
            
        }
    }
    return 0;
}








