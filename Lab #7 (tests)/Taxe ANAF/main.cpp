#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

class PlatitorTaxe{
private:
    std::string nume;
    int suma;
    int suma_netaxabila;
    std::string id;
public:
    PlatitorTaxe(std::string nume, int suma, int suma_netaxabila, std::string id):
    nume(nume), suma(suma), suma_netaxabila(suma_netaxabila), id(id){}
    std::string get_nume() { return this->nume; }
    int get_suma() { return this->suma; }
    int get_suma_netaxabila() { return this->suma_netaxabila; }
    std::string get_id() { return this->id; }
};

class PersoanaFizica: public PlatitorTaxe{
public:
    PersoanaFizica(std::string nume, int suma, int suma_netaxabila):PlatitorTaxe(nume, suma, suma_netaxabila, "PersoanaFizica"){}
};

class Firma: public PlatitorTaxe{
public:
    Firma(std::string nume, int suma, int suma_netaxabila):PlatitorTaxe(nume, suma, suma_netaxabila, "Firma"){}
};

class AgentieAdministrareFiscala{
private:
    std::vector<PlatitorTaxe*> vec_entitati;
public:
    void add_entity(PlatitorTaxe* p_entity){
        vec_entitati.push_back(p_entity);
    }
    void afisare_platitori(){
        for (int i=0; i<vec_entitati.size(); ++i){
            std::cout << vec_entitati[i] -> get_nume() << "\n";
            std::cout << vec_entitati[i] -> get_suma() << "\n";
        }
    }
    void afisare_taxe_baza(int procent_pf, int procent_firma){
        for (int i=0; i<vec_entitati.size(); ++i){
            int procent;
            if (vec_entitati[i] -> get_id() == "PersoanaFizica"){
                procent = procent_pf;
            }
            else {
                procent = procent_firma;
            }
            std::cout << vec_entitati[i] -> get_nume() << std::endl;
            std::cout << (vec_entitati[i] -> get_suma() - 
                          vec_entitati[i] -> get_suma_netaxabila()) *
                          procent / 100 << "\n";
        }
    }
    
    void procent_venituri_netaxabile(){
        bool ok = true;
        for (int i=0; i<vec_entitati.size(); ++i){
            if (vec_entitati[i]->get_suma_netaxabila() / float(vec_entitati[i]->get_suma()) > 0.2){
                std::cout << vec_entitati[i]->get_nume() << "\n";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << (vec_entitati[i]->get_suma_netaxabila() / float(vec_entitati[i]->get_suma())) *100 <<"\n";
                ok = false;
            }
        }
        if (ok){
            std::cout << "Nicio potentiala frauda detectata\n";
        }
    }
    
    void taxe_totale(int procent_pf, int procent_firma){
        float taxe_totale = 0;
        float taxa_entitate = 0;
        int netaxabil;
        std::cout << std::fixed << std::setprecision(2);
        
        for (int i=0; i<vec_entitati.size(); ++i){
            netaxabil = vec_entitati[i] -> get_suma() - vec_entitati[i] -> get_suma_netaxabila();
            if (vec_entitati[i] -> get_id() == "PersoanaFizica"){
                
                if (netaxabil > 300000){
                    taxa_entitate = (procent_pf * 300000.0 / 100) +
                                    (netaxabil - 300000.0) * procent_pf * 2 / 100; 
                }
                else {
                    taxa_entitate = netaxabil * float(procent_pf) / 100;
                }
            } else {
                if (netaxabil > 300000){
                    taxa_entitate = netaxabil * float(procent_firma + 19) / 100;
                }
                else {
                    taxa_entitate = netaxabil * float(procent_firma) / 100;
                }
            }
            
            std::cout << vec_entitati[i] -> get_nume() << "\n";
            std::cout << taxa_entitate << "\n";
            taxe_totale += taxa_entitate;
        }
        std::cout << taxe_totale << "\n";
    }
};

int main(){
    int comanda;
    int nr_entitati;
    std::string tip_entitate;
    std::string nume_entitate;
    int suma;
    int suma_netaxabila;
    int procent_pf;
    int procent_firma;
    AgentieAdministrareFiscala anaf;
    
    std::cin >> comanda;
    std::cin >> nr_entitati;
    
    
    for (int i=0; i<nr_entitati; ++i){
        // std::cin >> tip_entitate;
        std::cin.ignore();
        std::getline(std::cin, tip_entitate);
        // std::cin >> nume_entitate;
        std::getline(std::cin, nume_entitate);
        std::cin >> suma;
        std::cin >> suma_netaxabila;
        
        if (tip_entitate == "Persoana Fizica"){
            anaf.add_entity(new PersoanaFizica(nume_entitate, suma, suma_netaxabila));
        }
        else {
            anaf.add_entity(new Firma(nume_entitate, suma, suma_netaxabila));
        }
    }
    
    switch(comanda){
        case 1:{
            anaf.afisare_platitori();
            break;
        }
        
        case 2:{
            std::cin >> procent_pf;
            std::cin >> procent_firma;
            anaf.afisare_taxe_baza(procent_pf, procent_firma);
            break;
        }
        
        case 3:{
            anaf.procent_venituri_netaxabile();
            break;
        }
        
        case 4:{
            std::cin >> procent_pf;
            std::cin >> procent_firma;
            anaf.taxe_totale(procent_pf, procent_firma);
            break;
        }
        
        default:{
            break;
        }
    }
}



