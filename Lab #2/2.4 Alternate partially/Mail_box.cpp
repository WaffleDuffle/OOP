#include "Mail_box.h"

Mail_box::Mail_box(std::string email, int capacitate):
    email(email), capacitate(capacitate), vec_mail(nullptr), nr_email(0){}
    
void Mail_box::add_mail(Mail m){
    // 1. verificam daca vec_mail este nullptr sau nu
    // 1.1. Daca este nullptr => ii alocam memorie pentru un element
    // 1.2. Daca nu este nullptr => 
    
    // 2. Alocam memorie pentru un nou vector de Mail-uri de lungimea vectorului vechi+1
    // 3. Copiem primele n elemente din vectorul vechi de Mail-uri in vectorul nou;
    // 4. Eliberam memoria vectorului vechi
    // 5. Adaug Mail-ul m pe ultima pozitie in vectorul nou
    if (vec_mail == nullptr){
        vec_mail = new Mail*;
        *vec_mail = new Mail(m);
        this->nr_email++;
    }
    else {
        // 2:
        Mail** vec_nou = new Mail*[this->nr_email+1];
        // 3:
        for (int i=0; i<this->nr_email; ++i){
            *(vec_nou+i) = *(vec_mail+i);
        }
        // 4 (skip)
        // 5:
        *(vec_nou+nr_email) = new Mail(m);
        vec_mail = vec_nou;
        this->nr_email++;
    }
    
    // std::cout << this->nr_email;
}

void Mail_box::afisare_mailbox(){
    for (int i=0; i<this->nr_email; ++i){
        (*(vec_mail+i)) -> afisare();
    }
}

void Mail_box::check_inbox(){
    for (int i=0; i<this->nr_email; ++i){
        if ((*(vec_mail+i)) -> get_recipient() == this->email){
            (*(vec_mail+i)) -> afisare();
        }
    }
}


