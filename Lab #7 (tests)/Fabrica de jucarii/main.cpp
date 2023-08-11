#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
class Jucarie{
    protected:
    char tip;
        std::string tematica;
        std::string nume;
    public:
        Jucarie(char tip, std::string tematica, std::string nume):
        tip(tip), tematica(tematica), nume(nume){}
        
        virtual void afisare() = 0;
        
        std::string get_tematica(){
            return tematica;
        }
        
        virtual float dimensiune(){ return 0;}
        
        virtual void afisare3() = 0;
};

class Action_figure: public Jucarie{
    private:
        int inaltime;
        int latime;
        int lungime;
    public:
        Action_figure(char tip, std::string tematica, std::string nume, int inaltime, int latime, int lungime):
        Jucarie(tip, tematica, nume), inaltime(inaltime), latime(latime), lungime(lungime){}
        
        void afisare(){
            std::cout << "Action_figure " << tematica << " " << nume << " " << inaltime << " " << latime << " " << lungime << std::endl;
        }
        
        void afisare3(){
            std::cout << "Action_figure " << nume << " " << floor(10/dimensiune()) << std::endl;
        }
        
        float dimensiune(){
            float mini = 9999;
            if(mini > inaltime)
                mini = inaltime;
            if(mini > latime)
                mini = latime;
            if(mini > lungime)
                mini = lungime;
            return mini;
        }
};

class Puzzle: public Jucarie{
    private:
        int nr_piese;
        int latime;
        int lungime;
    public:
        Puzzle(char tip, std::string tematica, std::string nume, int nr_piese, int latime, int lungime):
        Jucarie(tip, tematica, nume), nr_piese(nr_piese), latime(latime), lungime(lungime){}
        
        void afisare(){
            std::cout << "Puzzle " << tematica << " " << nume << " " << nr_piese << " " << latime << " " << lungime << std::endl;
        }
        
        void afisare3(){
            std::cout << "Puzzle " << nume << " " << floor(10/dimensiune()) << std::endl;
        }
        
        float dimensiune(){
            float dim1 = latime/sqrt(nr_piese);
            float dim2 = lungime/sqrt(nr_piese);
            if(dim1 < dim2)
                return dim1;
            else
                return dim2;
        }
};

bool metoda(Jucarie *j1, Jucarie *j2){
    return (floor(10/j1->dimensiune()) < floor(10/j2->dimensiune()));
}

class Gestionare{
    private:
        std::vector<Jucarie*> vec;
    public:
        void vec_add(Jucarie *j){
            vec.push_back(j);
        }
        
        void test1(){
            for(int i = 0 ; i < vec.size() ; ++i)
                vec[i]->afisare();
        }
        
        void test2(std::string x){
            for(int i = 0 ; i < vec.size() ; ++i)
                if(vec[i]->get_tematica() == x)
                    vec[i]->afisare();
        }
        
        void test3(){
            for(int i = 0 ; i < vec.size() ; ++i)
                vec[i]->afisare3();
        }
        
        void test4(){
            std::sort(vec.begin(), vec.end(), metoda);
        }
        
        
};



int main(){
    Gestionare obiect;
    int n, test;
    char tip;
    std::string tematica;
    std::string nume;
    int nr_piese;
    int inaltime;
    int latime;
    int lungime;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> tip;
        std::cin.ignore();
        std::getline(std::cin, tematica);
        std::getline(std::cin, nume);
        if(tip == 'a'){
            std::cin >> inaltime >> latime >> lungime;
            obiect.vec_add(new Action_figure(tip,tematica,nume,inaltime,latime,lungime));
        }
        else{
            std::cin >> nr_piese >> latime >> lungime;
            obiect.vec_add(new Puzzle(tip,tematica,nume,nr_piese,latime,lungime));
        }
    }
    
    std::cin >> test;
    switch(test){
        case 1:{
            obiect.test1();
            break;
        }
        case 2:{
            std::cin >> tematica;
            obiect.test2(tematica);
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
    }
    
    
    
    return 0;
}