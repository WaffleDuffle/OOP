// Scrieți o clasă Cutie cu 3 date membre publice: lungime, lățime, înălțime, de tip real și o funcție membră care întoarce volumul cutiei.

// Definiți o funcție membră care calculează volumul rămas în cutia inițială dacă în ea se va introduce o altă cutie transmisă ca argument în funcție. Se va verifica, mai întâi, dacă cea de-a doua cutie poate fi introdusă în prima cutie (considerăm că cele 3 dimensiuni respectă aceeași ordine și nu putem roti nicio cutie). În caz contrar, se va afișa volumul cutiei inițiale.

// În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se va citi un întreg reprezentând o comandă, în funcție de valoarea căreia se vor executa diferite acțiuni:
// 1. Se afișează pe ecran volumul cutiei, cu 3 zecimale.
// 2. Se citesc un nou set de atribute: lungime, lățime, înălțime cu ajutorul cărora se instanțiază o a doua cutie. Se afișează pe ecran volumul rămas liber în prima cutie după introducerea celei de-a doua cutii (dacă este posibil), cu 3 zecimale.

#include <iostream>
#include <iomanip>
class Cutie{
  public:
  float lungime;
  float latime;
  float inaltime;
  void init(float lungime, float latime, float inaltime)
  {
      this -> lungime = lungime;
      this -> latime = latime;
      this -> inaltime = inaltime;
  }
  float volum(float lungime, float latime, float inaltime)
  {
      return lungime * latime * inaltime;
  }
  void afisare()
  {
      
  }
};
int main()
{
    int test;
    float lungime;
    float latime;
    float inaltime;
    std::cin >> lungime >> latime >> inaltime;
    Cutie c;
    c.init(lungime, latime, inaltime);
    std::cin >> test;
    switch(test)
    {
        case 1: {
            float v = c.volum(lungime, latime, inaltime);
            std::cout << std::fixed << std::setprecision(3) << v;
            break;
        }
        case 2:{
            Cutie c1;
            float lungime2;
            float latime2;
            float inaltime2;
            std::cin >> lungime2 >> latime2 >> inaltime2;
            c1.init(lungime2, latime2, inaltime2);
            float v1 = c.volum(lungime, latime, inaltime);
            float v2 = c1.volum(lungime2, latime2, inaltime2);
            if(lungime2 > lungime || latime2 > latime || inaltime2 > inaltime)
                std::cout << std::fixed << std::setprecision(3) << v1;
                else
                std::cout << std::fixed << std::setprecision(3) << v1 - v2;
            break;
        }
    }
  return 0;
}
