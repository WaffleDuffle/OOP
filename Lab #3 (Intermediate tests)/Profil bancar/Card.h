#ifndef CARD_H
#define CARD_H
class Card{
    private:
        float sold_card;
    public:
        Card(float);
        float get_sold_card();
        void card_display();
        void adaugare_sold(float);
        void diferenta_sold(float);
};
#endif