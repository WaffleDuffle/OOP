#ifndef MAIL_BOX_H
#define MAIL_BOX_H

#include "Mail.h"

class Mail_box{
private:
    std::string email;
    int capacitate;
    Mail** vec_mail;
    int nr_email;
public:
    Mail_box(std::string, int);
    void add_mail(Mail);
    void afisare_mailbox();
    void check_inbox();
};

#endif