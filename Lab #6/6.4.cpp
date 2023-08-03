/* Să se scrie un program care ordonează o secvență de maxim 20 de numere complexe în funcție de valoarea modulului.

Se va citi de la tastatură un număr întreg reprezentând numărul de numere complexe ce urmează a fi citit. Ulterior, de pe fiecare linie se citesc 2 valori reale, reprezentând partea reală, respectiv partea imaginară, separate de un spațiu.

Să se afișeze pe ecran numerele complexe ordonate, câte unul pe linie. Afișarea unui număr complex se face sub forma "<partea_reala> <partea_imaginara>". */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
class Complex{
    private:
        float re;
        float im;
    public:
        Complex(float re, float im):re(re), im(im){}
        void display(){
            std::cout << re << " " << im << std::endl;
        }
    float modul(){
        return sqrt((re*re)+(im*im));
    }
    bool operator < (Complex &c1){
        return modul() < c1.modul();
    }
};

int main(){
    int n;
    float temp_re, temp_im;
    std::vector<Complex>numere;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> temp_re >> temp_im;
        numere.push_back(Complex(temp_re, temp_im));
    }
    std::sort(numere.begin(), numere.end());
    for(auto a : numere)
        a.display();
    return 0;
}
