#include "Mail.h"

Mail::Mail(std::string sender, 
            std::string recipient, 
            std::string subject, 
            std::string body):
            sender(sender),
            recipient(recipient),
            subject(subject),
            body(body){}

void Mail::afisare(){
    std::cout << "From:" << this->sender << std::endl;
    std::cout << "To:" << this->recipient << std::endl;
    std::cout << "Subject:" << this->subject << std::endl;
    std::cout << "Body:" << this->body << std::endl;
    std::cout << "---" << std::endl;
}

std::string Mail::get_recipient(){return this->recipient;}