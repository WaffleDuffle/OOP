#ifndef MOBIL_H
#define MOBIL_H
#include <string>
class Mobil{
    private:
        int identificator;
        int distanta;
        std::string mesaj_primit;
        std::string mesaj_transmis;
    public:
        Mobil(int, int, std::string, std::string);
        void display();
        int get_id();
        int get_distanta();
        std::string get_mesaj_transmis();
        std::string get_mesaj_primit();
        void display_primit();
        void display_transmis();
        void display_nr();
};





#endif