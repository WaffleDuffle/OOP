#ifndef CONT_ECONOMII_H
#define CONT_ECONOMII_H
class Cont_economii{
    private:
        float sold_cont;
        float dobanda;
    public:
        Cont_economii(float,float);
        float get_sold_cont();
        float get_dobanda();
        void cont_economii_display();
        void adaugare(float);
};


#endif