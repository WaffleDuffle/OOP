#include <iostream>
#include <string>

#include "Mail_box.h"

int main(){
    std::string email_propriu;
    int capacitate_maxima;
    int nr_mesaje;
    int comanda;
    
    std::string temp_sender;
    std::string temp_recipient;
    std::string temp_subject;
    std::string temp_body;
    
    std::cin >> email_propriu;
    std::cin >> capacitate_maxima;
    std::cin >> nr_mesaje;
    
    Mail_box mb(email_propriu, capacitate_maxima);
    
    std::cin.ignore();
    
    for (int i=0; i<nr_mesaje; ++i){
        std::getline(std::cin, temp_sender);
        std::getline(std::cin, temp_recipient);
        std::getline(std::cin, temp_subject);
        std::getline(std::cin, temp_body);
        Mail temp_mail(temp_sender, temp_recipient, temp_subject, temp_body);
        // temp_mail.afisare();
        mb.add_mail(temp_mail);
    }
    // mb.afisare_mailbox();
    
    std::cin >> comanda;
    
    switch(comanda){
        case 1:{
            mb.check_inbox();
            break;
        }
    }
}



