// Să se scrie o clasă Carte cu următoarele date membre: titlu, nume_autor, an_lansare, nr_pagini, pret. Se vor instanția obiecte din această clasă folosind un vector cu alocare dinamică de memorie. Se citește de la tastatură numărul de cărți pe care dorim să îl folosim. Ulterior, pentru fiecare carte se vor citi, de pe rânduri diferite datele membre în ordinea enunțată mai sus.

// Se va citi o comandă de la tastatură. În funcție de valoarea acesteia se vor executa diferite acțiuni:
// Se citește de la tastatură un nume de autor. Se afișează titlurile tuturor cărților scrise de acest autor, separate de virgulă și spațiu. Pentru simplitate, ultimul titlu va fi, de asemenea, urmat de virgulă și spațiu.
// Se va afișa cartea cu numărul minim de pagini. 
// Se va afișa cartea cel mai recent lansată. 
// Prin afișarea cărții se înțelege afișarea tuturor datelor membre ale cărții, fiecare pe un rând nou.

#include <iostream>
#include <string>
class Carte{
    private:
        std::string titlu;
        std::string nume_autor;
        int an_lansare;
        int nr_pagini;
        int pret;
    public:
        Carte(std::string titlu="", std::string nume_autor="", int an_lansare=0, int nr_pagini=0, int pret=0):titlu(titlu), nume_autor(nume_autor), an_lansare(an_lansare), nr_pagini(nr_pagini), pret(pret){}
        std::string get_autor(){
            return nume_autor;
        }
        std::string get_titlu(){
            return titlu;
        }
        int get_pagini(){
            return nr_pagini;
        }
        int get_an_lansare(){
            return an_lansare;
        }
        void display(){
            std::cout << titlu << std::endl;
            std::cout << nume_autor << std::endl;
            std::cout << an_lansare << std::endl;
            std::cout << nr_pagini << std::endl;
            std::cout << pret << std::endl;
        }
};

int main(){
    int nr_carti, test;
    std::string temp_titlu, temp_nume_autor;
    int temp_an_lansare, temp_nr_pagini, temp_pret;
    Carte **biblioteca = nullptr;
    std::cin >> nr_carti;
    biblioteca = new Carte*[nr_carti];
    for(int i = 0 ; i < nr_carti ; ++i){
        std::cin.ignore();
        std::getline(std::cin, temp_titlu);
        std::getline(std::cin, temp_nume_autor);
        std::cin >> temp_an_lansare >> temp_nr_pagini >> temp_pret;
        biblioteca[i] =  new Carte(temp_titlu, temp_nume_autor, temp_an_lansare, temp_nr_pagini, temp_pret);
    }
    std::cin >> test;
    switch(test){
        case 1: { std::string autor;
                  std::cin.ignore();
                  std::getline(std::cin, autor);
                  std::cout << autor << std::endl;
                  for(int i = 0 ; i < nr_carti ; ++i){
                      if(biblioteca[i]->get_autor() == autor)
                        std::cout << (biblioteca[i]->get_titlu()) << ", ";
                  }
                  break;
                }
        case 2: { int mini = 99999, x;
                  for(int i = 0 ; i < nr_carti ; ++i){
                      if(mini > biblioteca[i]->get_pagini())
                        mini = biblioteca[i]->get_pagini(), x = i;
                  }
                  biblioteca[x]->display();
                  break;
                }
        case 3: { int maxi = -1, x;
                  for(int i = 0 ; i< nr_carti ; ++i){
                      if(maxi < biblioteca[i]->get_an_lansare())
                        maxi = biblioteca[i]->get_an_lansare(), x = i;
                  }
                  biblioteca[x]->display();
                  break;
                }
    }
    for(int i = 0 ; i < nr_carti ; ++i)
        delete *(biblioteca + i);
    delete biblioteca;
    return 0;
}
