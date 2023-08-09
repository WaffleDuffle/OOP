#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Angajat.h"
class Salariat:public Angajat{
    private:
        int norma;
        int vechime;
        float salariu_net;
    public:
        Salariat(std::string tip, std::string nume, std::string departament, int norma, int vechime, float salariu_net)
        :Angajat(tip, nume,departament),norma(norma), vechime(vechime), salariu_net(salariu_net){}
        
        void afisare(){
            std::cout << get_nume() << " " << norma << " " << vechime << " " << salariu_net << std::endl;
        }
        
        float calcul_salariu(){
            if(get_departament() == "IT")
                return (salariu_net*12)/0.65;
            else
                return (salariu_net*12)/0.55;
        }
        
        float rentabilitate_angajat(){
            int k = vechime/3;
            float rent;
            rent = norma*(250 - 20 + k)/calcul_salariu();
            return rent;
        }
};

class Colaborator: public Angajat{
    private:
        float onorariu;
        float nr_prestari_anuale;
    public:
        Colaborator(std::string tip, std::string nume, std::string departament, float onorariu, float nr_prestari_anuale)
        :Angajat(tip,nume,departament),onorariu(onorariu), nr_prestari_anuale(nr_prestari_anuale){}
        
        void afisare(){
            std::cout << get_nume() << " " << onorariu << " " << nr_prestari_anuale << std::endl;
        }
        
        float calcul_salariu(){
            if(get_departament() == "IT")
                return (onorariu*nr_prestari_anuale)/0.65;
            else
                return (onorariu*nr_prestari_anuale)/0.55;
        }
        
        float rentabilitate_angajat(){
            return 0;
        }
        
        
};

int main(){
    int n, temp_norma, temp_vechime, temp_salariu_net;
    int temp_nr_prestari;
    float temp_onorariu;
    std::vector<Angajat*> vec;
    std::string temp_tip;
    std::string temp_nume;
    std::string temp_departament;
    std::cin >> n;
    int test;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> temp_tip >> temp_nume >> temp_departament;
        if(temp_tip == "salariat"){
            std::cin >> temp_norma >> temp_vechime >> temp_salariu_net;
            vec.push_back(new Salariat(temp_tip,temp_nume,temp_departament,temp_norma,temp_vechime,temp_salariu_net));
        }
        else if(temp_tip == "colaborator"){
            std::cin >> temp_onorariu >> temp_nr_prestari;
            vec.push_back(new Colaborator(temp_tip,temp_nume,temp_departament,temp_onorariu,temp_nr_prestari));
        }
    }
    std::cin >> test;
    switch(test){
        case 1:{
            std::cin >> temp_departament;
            for(int i = 0 ; i < vec.size() ; ++i)
                if(temp_departament == vec[i]->get_departament())
                    vec[i]->afisare();
            break;
        }
        case 2:{
            std::cin >> temp_nume;
            for(int i = 0 ; i < vec.size() ; ++i)
                if(temp_nume == vec[i]->get_nume())
                    std::cout << std::fixed << std::setprecision(2) << vec[i]->calcul_salariu() << std::endl;
            break;
        }
        case 3:{
            float maxi = -1;
            int p;
            for(int i = 0 ; i < vec.size() ; ++i){
                std::cout << vec[i]->rentabilitate_angajat() << std::endl;
                if(maxi < vec[i]->rentabilitate_angajat()){
                    maxi = vec[i]->rentabilitate_angajat();
                    p = i;
                }
                
            }
            
            std::cout << vec[p]->get_nume() << std::endl;
            break;
        }
        case 4:{
            std::cin >> temp_departament;
            float ma = 0;
            int s = 0;
            for(int i = 0 ; i < vec.size() ; ++i){
                if(vec[i]->get_departament() == temp_departament){
                    s++;
                    ma += vec[i]->calcul_salariu();
                }
            }
            ma = ma / s;
            std::cout << std::fixed << std::setprecision(2) << ma << std::endl;
            break;
        }
    }
    
    
    
    
    
    
    
    return 0;
    
}