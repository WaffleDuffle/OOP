// Menținerea specificatorului de acces “public” este o potențială breșă de securitate. Pentru a asigura ascunderea datelor, cele 3 date membre ale clasei Cutie vor avea specificatorul de acces “private”.
// Pentru clasa Cutie se vor scrie o serie de funcții care modifică (setter), respectiv accesează (getter) valorile datelor membre. În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se vor asigna obiectului respectiv cu ajutorul funcțiilor setter. Ulterior, se vor afișa pe ecran atributele cu ajutorul funcțiilor getter în ordinea precizată, fiecare pe un rând nou.

#include <iostream>

class Cutie{
private:
    float lungime;
    float latime;
    float inaltime;
public:
    void set_lungime(float lungime){
        this -> lungime = lungime;
    }
    void set_latime(float latime){
        this -> latime = latime;
    }
    void set_inaltime(float inaltime){
        this -> inaltime = inaltime;
    }
    float get_lungime(){
        return this->lungime;
    }
    float get_latime(){
        return this->latime;
    }
    float get_inaltime(){
        return this->inaltime;
    }
};
int main()
{
    float lungime, latime, inaltime;
    std::cin >> lungime >> latime >> inaltime;
    Cutie c;
    c.set_lungime(lungime);
    c.set_latime(latime);
    c.set_inaltime(inaltime);
    std::cout << c.get_lungime() << std::endl << c.get_latime() << std:: endl << c.get_inaltime();
    return 0;
}
