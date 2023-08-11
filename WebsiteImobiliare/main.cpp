#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
class Proprietate{
    protected:
        char tip;
        int pret;
        std::string locatie;
        int supraf;
    public:
        Proprietate(char tip, int pret, std::string locatie, int supraf):
        tip(tip), pret(pret), locatie(locatie), supraf(supraf){}
        
        virtual void afisare() = 0;
        
        virtual float supraf_totala(){ return 0;}
        
        virtual float pret_mp(){ return 0;}
        
        virtual int get_x(){ return 0;}
        
        int get_pret(){
            return this->pret;
        }
        
        char get_tip(){
            return this->tip;
        }
        
        std::string get_locatie(){
            return this->locatie;
        }
        
        int get_supraf(){
            return supraf;
        }
};

class Apartament: public Proprietate{
    private:
        int dim_terasa;
    public:
        Apartament(char tip, int pret, std::string locatie, int supraf, int dim_terasa):
        Proprietate(tip, pret, locatie, supraf), dim_terasa(dim_terasa){}
        
        void afisare(){
            std::cout << "Apartament " << pret << " " << locatie << " " << supraf << " " << dim_terasa << std::endl;
        }
        
        float supraf_totala(){
            return dim_terasa+supraf;
        }
        
        float pret_mp(){
            return pret / supraf_totala(); 
        }
        
        int get_dim(){
            return dim_terasa;
        }
        
        int get_x(){
            return dim_terasa; 
        }
};

class Casa: public Proprietate{
    private:
        int nr_etaje;
    public:
    Casa(char tip, int pret, std::string locatie, int supraf, int nr_etaje):
        Proprietate(tip, pret, locatie, supraf), nr_etaje(nr_etaje){}
        
        void afisare(){
            std::cout << "Casa " << pret << " " << locatie << " " << supraf << " " << nr_etaje << std::endl;
        }
        
        float supraf_totala(){
            return nr_etaje*supraf;
        }
        
        float pret_mp(){
            return pret / supraf_totala(); 
        }
        
        int get_nr_etaje(){
            return nr_etaje;
        }
        
        int get_x(){
            return nr_etaje; 
        }
        
};

bool metoda(Proprietate *p1, Proprietate *p2){
    if(p1->get_pret() != p2->get_pret())
        return (p1->pret_mp() < p2->pret_mp());
    else
        return (p1->get_pret() < p2->get_pret());
}

class Gestionare{
    private:
        std::vector <Proprietate*> vec;
        std::vector <Proprietate*> vec_filtrat;
    public:
        void vec_add(Proprietate *p){
            vec.push_back(p);
        }
        
        void test1(){
            for(int i = 0 ; i < vec.size() ; ++i)
                vec[i]->afisare();
        }
        
        void test2(){
            for(int i = 0 ; i < vec.size() ; ++i)
                std::cout << vec[i]->supraf_totala() << std::endl;
        }
        void test3(){
            for(int i = 0 ; i < vec.size() ; ++i)
                std::cout << vec[i]->pret_mp() << std::endl;
        }
        
        void test4(){
            std::sort(vec.begin(), vec.end(), metoda);
            for(int i = 0 ;  i< vec.size() ; ++i){
                vec[i]->afisare();
                std::cout << std::fixed << std::setprecision(2) << vec[i]->pret_mp() << std::endl;
            }
        }
        
        void test5(char tip, int pret, std::string locatie, int supraf, int x){
            for(int i = 0 ; i < vec.size() ; ++i){
                if(vec[i]->get_tip() != tip && tip != '0')
                    vec[i] = new Apartament('0',-1,"0",0,0);
                
                if(vec[i]->get_pret() < pret && pret != 0)
                    vec[i] = new Apartament('0',-1,"0",0,0);
                    
                if(vec[i]->get_locatie() != locatie && locatie != "0")
                    vec[i] = new Apartament('0',-1,"0",0,0);
                
                if(vec[i]->get_supraf() < supraf && supraf != 0)
                    vec[i] = new Apartament('0',-1,"0",0,0);
                   
                if(vec[i]->get_x() < x && x != 0) 
                    vec[i] = new Apartament('0',-1,"0",0,0);
                
            }
            for(int i = 0 ; i < vec.size() ; ++i)
                if(vec[i]->get_pret() != -1)
                    vec[i]->afisare();
            
        }
    
};

int main(){
    Gestionare obiect;
    char tip;
    int pret;
    std::string locatie;
    int supraf;
    int nr_etaje;
    int dim_terasa;
    int n, test;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> tip;
        std::cin >> pret;
        std::cin >> locatie;
        std::cin >> supraf;
        if(tip == 'c'){
            std::cin >> nr_etaje;
            obiect.vec_add(new Casa(tip, pret, locatie, supraf, nr_etaje));
        }
        else{
            std::cin >> dim_terasa;
            obiect.vec_add(new Apartament(tip, pret, locatie, supraf, dim_terasa));
        }
    }
    std::cin >> test;
    switch(test){
        case 1:{
            obiect.test1();
            break;
        }
        case 2:{
            obiect.test2();
            break;
        }
        case 3:{
            obiect.test3();
            break;
        }
        case 4:{
            obiect.test4();
            break;
        }
        case 5:{
            int x;
            std::cin >> tip;
            std::cin >> pret;
            std::cin >> locatie;
            std::cin >> supraf;
            std::cin >> x;
            obiect.test5(tip, pret, locatie, supraf, x);
        }
    }
    
    return 0;
}