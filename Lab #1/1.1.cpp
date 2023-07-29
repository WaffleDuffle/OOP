//Scrieți o clasă Cutie cu 3 date membre publice: lungime, lățime, înălțime, de tip real. În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se vor afișa pe ecran în ordinea precizată, cu o singură zecimală, fiecare pe un rând nou.

#include <iostream>
#include <string>
#include <iomanip>
class Cutie{
public:
    float lungime;
    float latime;
    float inaltime;
    void initializare(float lungime, float latime, float inaltime)
    {
        this -> lungime = lungime;
        this -> latime = latime;
        this -> inaltime = inaltime;
    }
    void afisare()
    {
        std::cout << std::fixed << std::setprecision(1) << this -> lungime <<std::endl;
        std::cout << std::fixed << std::setprecision(1)<< this -> latime << std::endl;
        std::cout << std::fixed << std::setprecision(1) << this -> inaltime << std::endl;
    }
};
int main()
{
    
    float lungime;
    float latime;
    float inaltime;
    std::cin >> lungime >> latime >> inaltime;
    Cutie c;
    c.initializare(lungime,latime,inaltime);
    c.afisare();
    return 0;
}
