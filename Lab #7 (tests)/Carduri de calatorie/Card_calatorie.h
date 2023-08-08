#ifndef CARD_CALATORIE_H
#define CARD_CALATORIE_H

class Card_calatorie{
private:
    int id;
    char tip;
    int moment_ultima_validare;
public:
    Card_calatorie(int,char);
    virtual void validare_calatorie(int, int)=0;
    virtual void incarcare(int)=0;
    virtual void display();
    char get_tip();
    int get_id();
    int get_moment();
    void set_moment(int);
    virtual bool verificare(int)=0;
};

#endif