#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Pasare{
    protected:
        char tip;
        std::string nume;
        int dimensiune;
    public:
        Pasare(char tip, std::string nume, int dimensiune):tip(tip), nume(nume), dimensiune(dimensiune){}
        
        virtual void afisare() = 0;
        
        char get_tip(){
            return tip;
        }
        
        int get_dimensiune(){
            return dimensiune;
        }
        
        std::string get_nume(){
            return nume;
        }
        
        virtual float supraf(){ return 0;}
};

bool metoda(Pasare *p1, Pasare *p2){
    return (p1->supraf() < p2->supraf());
}

class Zburatoare: public Pasare{
    private:
        int batai_pe_minut;
    public:
        Zburatoare(char tip, std::string nume, int dimensiune, int batai_pe_minut):
        Pasare(tip, nume, dimensiune), batai_pe_minut(batai_pe_minut){};
        
        void afisare(){
            std::cout << nume << " " << dimensiune << " " << batai_pe_minut << std::endl;
        }
        
        float supraf(){
            return dimensiune * 110 * batai_pe_minut / 100;
        }
};

class Nezburatoare: public Pasare{
    private:
        std::string culoare;
    public:
        Nezburatoare(char tip, std::string nume, int dimensiune, std::string culoare):
        Pasare(tip, nume, dimensiune), culoare(culoare){}
        void afisare(){
            std::cout << nume << " " << dimensiune << " " << culoare << std::endl;
        }
        
        float supraf(){
            return dimensiune * 30;
        }
};

class Gestionare{
    private:
        std::vector<Pasare*> vec;
    public:
        void add_vec(Pasare* p){
            vec.push_back(p);
        }
        
        void test1(){
            for(int i = 0 ; i < vec.size() ; ++i)
                vec[i]->afisare();
        }
        
        void test2(char tip, int dimensiune){
            for(int i = 0 ; i < vec.size() ; ++i)
                if(vec[i]->get_tip() == tip && vec[i]->get_dimensiune() >= dimensiune)
                    vec[i]->afisare();
        }
        
        void test3(){
            for(int i = 0 ; i < vec.size() ; ++i)
                std::cout << vec[i]->get_nume() << " " << vec[i]->supraf() << std::endl;
        }
        
        void test4(){
            std::sort(vec.begin(), vec.end(), metoda);
        }
        
        void test5(){
            int s1 = 0, s2 = 0;
            for(int i = 0 ; i < vec.size() ; ++i){
                if(vec[i]->get_tip() == 'z')
                    s1 += vec[i]->supraf();
                else
                    s2 += vec[i]->supraf();
            }
            if(s1 > s2) std::cout << s1 << std::endl;
            else std::cout << s2 << std::endl;
                
        }
};

int main(){
    Gestionare obiect;
    int n, test;
    char tip;
    std::string nume;
    int dimensiune;
    int batai_pe_minut;
    std::string culoare;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> tip;
        std::cin >> nume;
        std::cin >> dimensiune;
        if(tip == 'z'){
            std::cin >> batai_pe_minut;
            obiect.add_vec(new Zburatoare(tip,nume,dimensiune,batai_pe_minut));
        }
        else{
            std::cin >> culoare;
            obiect.add_vec(new Nezburatoare(tip,nume,dimensiune,culoare));
        }
    }
    std::cin >> test;
    switch(test){
        case 1:{
            obiect.test1();
            break;
        }
        case 2:{
            std::cin >> tip;
            std::cin >> dimensiune;
            obiect.test2(tip, dimensiune);
            break;
        }
        case 3:{
            obiect.test3();
            break;
        }
        case 4:{
            obiect.test4();
            obiect.test1();
            break;
        }
        case 5:{
            obiect.test5();
            break;
        }
    }
    
    
    return 0;
}