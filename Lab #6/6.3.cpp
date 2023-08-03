/* Să se scrie un program care afișează pe ecran numele studenților citiți de la tastatură, ordonați după un anumit criteriu definit mai jos.

Se citesc de la tastatură până la apariția cuvântului STOP:

un std::string, reprezentând numele studentului;
un întreg, n, reprezentând numărul de note ce urmează a fi citit de la tastatură;
n întregi reprezentând notele studentului;
După cuvântul STOP se mai citește o valoare întreagă de test, în funcție de a cărei valoare se execută:

Ordonarea studenților după nume. Se afișează pe ecran numele studenților în ordine lexicografică, câte unul pe un rând diferit. Fiecare nume este urmat de caracterul '\n'.
Ordonarea studenților după media notelor. Se afișează pe ecran numele studenților în ordinea mediilor notelor, câte unul pe un rând. Fiecare nume este urmat de caracterul '\n'. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student{
    private:
        std::string nume;
        std::vector<int> note;
        int nr_note;
    public:
        Student(std::vector<int> note, std::string nume, int nr_note):nume(nume), nr_note(nr_note){
            for(int i = 0 ; i < note.size() ; ++i)
                this->note.push_back(note[i]);
        }
        std::string get_nume(){
            return this->nume;
        }
        float get_medie(){
            int s = 0;
            for(int i = 0 ; i < note.size() ; ++i)
                s += note[i];
            return (float)s/nr_note;
        }
        
        
};

bool comparatie_nume(Student &s1, Student &s2){
    return (s1.get_nume() < s2.get_nume());
}
bool comparatie_medie(Student &s1, Student &s2){
    return (s1.get_medie() < s2.get_medie());
}
int main(){
    std::string temp_nume = "";
    int n;
    int temp_nota;
    int test;
    std::vector<Student> studenti;
    std::vector<int> temp_note;
    while(true){
        std::cin >> temp_nume;
        if(temp_nume != "STOP"){
        std::cin >> n;
        for(int i = 0 ; i < n ; ++i){
            std::cin >> temp_nota; 
            temp_note.push_back(temp_nota);
            
        }
        studenti.push_back(Student(temp_note, temp_nume, n));
        temp_note.clear();}
        else
            break;
    
    }
    
    std::cin >> test;
    
    switch(test){
        case 1:{
            std::sort(studenti.begin(), studenti.end(), comparatie_nume);
            for(int i = 0 ; i < studenti.size() ; ++i)
                std::cout << studenti[i].get_nume() << std::endl;
            break;
            
        }
        case 2:{
            std::sort(studenti.begin(), studenti.end(), comparatie_medie);
            for(auto a : studenti)
                std::cout << a.get_nume() << std::endl;
            break;
        }
    }
    return 0;
}
