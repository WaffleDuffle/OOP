// Să se scrie o clasă Carte cu următoarele date membre: titlu, nume_autor, an_lansare, nr_pagini, pret. Se vor instanția maxim 5 obiecte din această clasă folosind un vector cu alocare statică de memorie. Se citește de la tastatură numărul de cărți pe care dorim să îl folosim. Ulterior, pentru fiecare carte se vor citi, de pe rânduri diferite datele membre în ordinea enunțată mai sus.

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
        Carte(std::string titlu = "", std::string nume_autor = "", int an_lansare = 0, int nr_pagini = 0, int pret = 0):titlu(titlu),nume_autor(nume_autor), an_lansare(an_lansare), nr_pagini(nr_pagini), pret(pret){}
   
    void display(){
        std::cout << titlu << std::endl << nume_autor << std::endl << an_lansare << std::endl << nr_pagini << std::endl << pret << std::endl;
    }
    std::string get_titlu(){
        return titlu;
    }
    std::string get_autor(){
        return nume_autor;
    }
    int get_numar_pagini(){
        return nr_pagini;
    }
    int get_an_lansare(){
        return an_lansare;
    }
    
    
};
int main(){
    int n, test;
    std::string temp_titlu, temp_nume_autor;
    int temp_an_lansare, temp_nr_pagini, temp_pret;
    std::cin >> n;
    Carte biblioteca[5];
    for(int i = 0 ; i < n ; ++i){
        std::cin.ignore();
        std::getline(std::cin,temp_titlu);
        std::getline(std::cin,temp_nume_autor);
        std::cin>>temp_an_lansare>>temp_nr_pagini>>temp_pret;
        biblioteca[i] = Carte(temp_titlu,temp_nume_autor,temp_an_lansare,temp_nr_pagini,temp_pret);
    }
    std::cin >> test;
    switch(test){
        case 1: {
                    std::string autor;
                    std::cin.ignore();
                    std::getline(std::cin,autor);
                    for(int i = 0 ; i < n ; ++i)
                        if(autor == biblioteca[i].get_autor()){
                            std::cout << biblioteca[i].get_titlu() << ", ";
                        }
                    break;
                }
        case 2: {   
                    int mini = 999999, x;
                    for(int i = 0 ; i < n ; ++i)
                        if(mini > biblioteca[i].get_numar_pagini())
                            x = i, mini = biblioteca[i].get_numar_pagini();
                    biblioteca[x].display();
                    break;
                }
        case 3: {   
                    int maxi = -1, x;
                    for(int i = 0 ; i < n ; ++i)
                        if(maxi < biblioteca[i].get_an_lansare())
                            x = i, maxi = biblioteca[i].get_an_lansare();
                    biblioteca[x].display();
                    break;
                }
        }
    return 0;
}
