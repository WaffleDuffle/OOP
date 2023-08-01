// Se vor instanția un obiect din clasa Vehicul și un obiect din clasa Autovehicul cu datele citite de la tastatură. Se citesc de la tastatură, de pe rânduri diferite, următoarele:
// 1. un șir de caractere, reprezentând numele Vehiculului;
// 2. un număr real, reprezentând prețul Vehiculului;
// 3. un număr real, reprezentând greutatea Vehiculului;
// 4. un șir de caractere, reprezentând numele Autovehiculului;
// 5. un număr real, reprezentând prețul Autovehiculului;
// 6. un număr real, reprezentând greutatea Autovehiculului;
// 7. un număr întreg, reprezentând puterea Autovehiculului.

// Se vor afișa pe ecran datele membre ale celor două obiecte, începând cu vehiculul, fiecare pe un rând nou, sub forma: <nume data membra>: <valoare data membra>. Constructorii vor folosi liste de inițializare, iar funcția de afișare din clasa Autovehicul va utiliza funcția de afișare din clasa Vehicul.

#include <iostream>
#include <string>

class Vehicul{
    private:
        std::string nume;
        float pret;
        float greutate;
    public:
        Vehicul(std::string nume, float pret, float greutate):nume(nume),pret(pret),greutate(greutate){}
    
        void afisare(){
            std::cout << "nume: " << nume << "\n" << "pret: " << pret << "\n" << "greutate: " << greutate << "\n";
        }
};

class Autovehicul: public Vehicul{
    private:
        int putere;
    public:
        Autovehicul(std::string nume, float pret, float greutate, int putere):Vehicul(nume,pret,greutate),putere(putere){}
        
        void afisare(){
            Vehicul::afisare();
            std::cout << "putere: " << putere << "\n";
        }
};

int main(){
    std::string nume_vehicul, nume_autovehicul;
    float pret_vehicul, greutate_vehicul, pret_autovehicul, greutate_autovehicul;
    int putere_autovehicul;
    std::getline(std::cin, nume_vehicul);
    std::cin >> pret_vehicul >> greutate_vehicul;
    std::cin.ignore();
    std::getline(std::cin, nume_autovehicul);
    std::cin >> pret_autovehicul >> greutate_autovehicul;
    std::cin >> putere_autovehicul;
    Vehicul v(nume_vehicul, pret_vehicul, greutate_vehicul);
    Autovehicul a(nume_autovehicul, pret_autovehicul, greutate_autovehicul, putere_autovehicul);
    v.afisare();
    a.afisare();
    return 0;
}
