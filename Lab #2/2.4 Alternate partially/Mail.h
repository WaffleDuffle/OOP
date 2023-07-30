#ifndef MAIL_H
#define MAIL_H

#include <string>
#include <iostream>

class Mail{
private:
    std::string sender;
    std::string recipient;
    std::string subject;
    std::string body;
public:
    Mail(std::string, std::string, std::string, std::string);
    void afisare();
    std::string get_recipient();
};

#endif