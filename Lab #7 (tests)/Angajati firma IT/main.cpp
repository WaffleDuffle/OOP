#include <iostream>
#include <string>
#include <vector>

class Angajat{
    protected:
        std::string nume;
        float salariu_baza;
        std::string functie;
        float procent_taxe_salariu;
    public:
        Angajat(std::string nume, float salariu_baza, std::string functie):
        nume(nume), salariu_baza(salariu_baza), functie(functie){}
        
        std::string get_nume(){
            return nume;
        }
        
        float get_salariu_baza(){
            return salariu_baza;
        }
        
        std::string get_functie(){
            return functie;
        }
        
        virtual float get_salariu_net(){
            return 0;
        }
        
        virtual float get_salariu_brut(){
            return 0;
        }
        
        virtual void marire_salariu(float x){
            if(x != 0)
                salariu_baza += salariu_baza*x/100;
        }
        
        virtual ~Angajat(){
            std::cout << "Destructor Angajat" << std::endl;
        }
        
        
};

class Analist: public Angajat{
    public:
        Analist(std::string nume, float salariu_baza, std::string functie):
        Angajat(nume, salariu_baza, functie){}
        
        float get_salariu_net(){
            return get_salariu_baza()*40/100;
        }
        virtual ~Analist(){
            std::cout << "Destructor Analist" << std::endl;
        }
        
};

class Programator: public Analist{
    protected:
        float procent_deducere_salariu_it;
    public:
        Programator(std::string nume, float salariu_baza, std::string functie):
        Analist(nume, salariu_baza, functie){}
        
        float get_salariu_net(){
            procent_deducere_salariu_it = 10;
            return get_salariu_baza()*(40 - procent_deducere_salariu_it)/100;
        }
        virtual ~Programator(){
            std::cout << "Destructor Programator" << std::endl;
        }
};

class LiderEchipaProgramare: public Programator{
    protected:
        float bonus_vechime_functie;
        int vechime_functie;
    public:
        LiderEchipaProgramare(std::string nume, float salariu_baza, std::string functie, int vechime_functie):
        Programator(nume, salariu_baza, functie), vechime_functie(vechime_functie){}
        
        int get_vechime_functie(){
            return vechime_functie;
        }
        
        float get_salariu_net(){
            bonus_vechime_functie = 500*vechime_functie;
            return (get_salariu_baza() + bonus_vechime_functie)*30/100;
        }
        
        float get_salariu_brut(){
            return (get_salariu_baza() + 500*vechime_functie);
        }
        
        
};

class FirmaProgramare{
    protected:
        std::vector<Angajat*> vec;
    public:
        void vec_add(Angajat* angajat){
            vec.push_back(angajat);
        }
        
        void afiseaza_angajati(){
            for(int i = 0 ; i < vec.size() ; ++i){
                std::cout << vec[i]->get_nume() << std::endl;
                std::cout << vec[i]->get_functie() << std::endl;
            }
        }
        
        void calcul_salariu(){
            float salariu_brut;
            for(int i = 0 ; i < vec.size() ; ++i){
                if(vec[i]->get_functie() == "LiderEchipaProgramare")
                    salariu_brut = vec[i]->get_salariu_brut();
                else
                    salariu_brut = vec[i]->get_salariu_baza();
                std::cout << vec[i]->get_nume() << std::endl;
                std::cout << "Salariu brut: " << salariu_brut << std::endl;
                std::cout << "Salariu Net: " << salariu_brut - vec[i]->get_salariu_net() << std::endl;
            }
        }
        
        void mareste_salarii(float x, float y, float z){
            
            for(int i = 0 ; i < vec.size() ; ++i){
                float salariu_vechi = vec[i]->get_salariu_baza();
                if(vec[i]->get_functie() == "Analist")
                    vec[i]->marire_salariu(x);
                else if(vec[i]->get_functie() == "Programator")
                    vec[i]->marire_salariu(y);
                else
                    vec[i]->marire_salariu(z);
                std::cout << vec[i]->get_nume() << std::endl;
                std::cout << "Salariu de baza vechi: " << salariu_vechi << std::endl;
                std::cout << "Salariu de baza nou: " << vec[i]->get_salariu_baza() << std::endl;
                
            }
        }
        
        void promoveaza(std::string name, std::string rol){
            for(int i = 0 ; i < vec.size() ; ++i){
                if(name == vec[i]->get_nume()){
                   delete vec[i];
                   if(rol == "Programator")
                        vec[i] = new Programator(name, 0, rol);
                    else if(rol == "LiderEchipaProgramare")
                        vec[i] = new LiderEchipaProgramare(name, 0, rol, 0);
                }
            }
        }
        
};

int main(){
    int nr_angajati;
    FirmaProgramare angajat;
    std::string rol;
    std::string nume;
    float salariu;
    int vechime;
    int test;
    std::cin >> nr_angajati;
    for(int i = 0 ; i < nr_angajati ; ++i){
        std::cin.ignore();
        std::getline(std::cin, nume);
        std::cin >> rol;
        std::cin >> salariu;
        if(rol == "LiderEchipaProgramare"){
            std::cin >> vechime;
            angajat.vec_add(new LiderEchipaProgramare(nume, salariu, rol, vechime));
        }
        else if(rol == "Programator")
            angajat.vec_add(new Programator(nume, salariu, rol));
        else if(rol == "Analist")
            angajat.vec_add(new Analist(nume, salariu, rol));
        }
        
        std::cin >> test;
        switch(test){
            case 1:{
                angajat.afiseaza_angajati();
                break;
            }
            case 2:{
                angajat.calcul_salariu();
                break;
            }
            case 3:{
                int analist_marire, programator_marire, lider_marire;
                std::cin >> rol;
                std::cin >> analist_marire;
                std::cin >> rol;
                std::cin >> programator_marire;
                std::cin >> rol;
                std::cin >> lider_marire;
                
                angajat.mareste_salarii(analist_marire, programator_marire, lider_marire);
                break;
            }
            case 4:{
                std::cin.ignore();
                std::getline(std::cin, nume);
                std::cin >> rol;
                angajat.promoveaza(nume, rol);
                angajat.afiseaza_angajati();
                break;
            }
        }
        
    return 0;
}
