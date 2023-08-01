// Se va instanția un obiect din clasa Telefon_mobil cu următoarele date, citite de la tastatură, de pe rânduri diferite:
// 1. o valoare reală, reprezentând tensiunea;
// 2. o valoare reală, reprezentând intensitatea;
// 3. un șir de caractere, reprezentând numărul de telefon;
// 4. un număr întreg, reprezentând procentul de baterie disponibil;

// Separat, se vor mai citi următoarele date, de pe linii diferite, pentru a utiliza funcția suna:
// 5. un șir de caractere, reprezentând numărul apelat;
// 6. un număr întreg, reprezentând durata apelului, exprimată în minute.

// Funcția suna din clasa Telefon primește ca argument un șir de caractere și afișează mesajul "Calling: <numar de telefon transmis ca argument>". Funcția suna din clasa Telefon_mobil primește un argument în plus reprezentând durata apelului în minute și afișează mesajul "Outgoing number: <numar de telefon propriu>", urmat de mesajul funcției cu același nume din clasa Telefon, și reduce bateria direct proporțional cu puterea consumată de dispozitivul electronic. Bateria scade cu <putere>/100 pentru fiecare minut de conversație.

// În programul principal se apelează funcția suna cu argumentele citite de la tastatură și se afișează pe ecran, pe un rând separat, procentul de baterie rămas disponibil, după efectuarea apelului.

#include <iostream>
#include <string>
class Echipament_electronic{
    protected:
        float tensiune;
        float intensitate;
    public:
        Echipament_electronic(float tensiune, float intensitate):tensiune(tensiune), intensitate(intensitate){}
        
};

class Telefon: private Echipament_electronic{
    protected:
        std::string nr_tel;
        float get_tensiune(){
            return tensiune;
        }
        float get_intensitate(){
            return intensitate;
        }
    public:
    Telefon(float tensiune, float intensitate, std::string nr_tel):Echipament_electronic(tensiune,intensitate),nr_tel(nr_tel){}
    
        void suna(std::string nr_tel){
            std::cout << "Calling: " << nr_tel << std::endl;
        }
        
};

class Telefon_mobil: protected Telefon{
    private:
        int baterie;
    public:
    Telefon_mobil(float tensiune, float intensitate, std::string nr_tel, int baterie):Telefon(tensiune,intensitate,nr_tel),baterie(baterie){}
    
        void suna(std::string nr_tel2, int durata){
            Telefon::suna(nr_tel2);
            std::cout << "Outgoing number: " << nr_tel << std::endl;
            
            baterie = baterie - ((get_tensiune()*get_intensitate())/100*durata);
            if(baterie < 0)
                baterie = 0;
            std::cout << baterie << std::endl;
        }
};

int main(){
    float temp_tensiune, temp_intensitate;
    std::string temp_nr_telefon, temp_nr_telefon2;
    int procent_baterie, temp_durata;
    std::cin >> temp_tensiune >> temp_intensitate;
    std::cin >> temp_nr_telefon;
    std::cin >> procent_baterie;
    
    Telefon_mobil tm(temp_tensiune, temp_intensitate, temp_nr_telefon, procent_baterie);
    
    
    std::cin >> temp_nr_telefon2;
    std::cin >> temp_durata;
    tm.suna(temp_nr_telefon2, temp_durata);
    return 0;
}
