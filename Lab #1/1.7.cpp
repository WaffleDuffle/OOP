// Să se scrie o clasă Cerc cu data membră "raza" de tip real. Clasa trebuie să conțină următoarele funcții membre:

// set_raza
// get_raza
// get_arie
// get_circumferinta
// constructor implicit
// constructor parametrizat

// Se citește de la tastatură o valoare reală reprezentând raza. Să se afișeze pe rânduri succesive următoarele informații, cu câte 2 zecimale:

// raza
// aria
// circumferinta

#include <iostream>
#include <iomanip>
#define pi 3.14
class Cerc{
    private:
        float raza;
    public:
        Cerc(){
            this->raza = 0;
        }
        Cerc(float raza){
            this->raza = raza;
        }
        void set_raza(float raza){
            this->raza = raza;
        }
        float get_raza(){
            return raza;
        }
        float get_arie(){
            return pi * raza * raza;
        }
        float get_circumferinta(){
            return 2 * pi * raza;
        }
    
};
int main()
{
    float r;
    std::cin >> r;
    Cerc c(r);
    std::cout << std::fixed << std::setprecision(2) <<  c.get_raza() << std::endl << c.get_arie() << std::endl << c.get_circumferinta();
    return 0;
}
