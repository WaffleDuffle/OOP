/* Să se scrie un program care afișează pe ecran numele studentului cu cea mai mare medie a notelor.

Se citesc de la tastatură:

un întreg, reprezentând numărul de studenți ce urmează a fi inițializați; pentru fiecare student se citesc:
un std::string, reprezentând numele studentului;
un întreg, n, reprezentând numărul de note ce urmează a fi citit de la tastatură;
n întregi reprezentând notele studentului; */

#include <iostream>
#include <string>
#include <vector>

class Student{
    private:
        std::string nume;
        float nota;
        std::vector<float> note;
        int nr_note;
    public:
        Student(std::vector<float> note, std::string nume, int nr_note):nume(nume), nr_note(nr_note){
            for(int i = 0 ; i < note.size() ; ++i)
                this->note.push_back(note[i]);
        }
        float medie(){
            float medie;
            float suma = 0;
            for(int i = 0 ; i < note.size() ; ++i){
                suma += note[i];
            }
            medie = suma/note.size();
            return medie;
        }
        std::string get_nume(){
            return nume;
        }
};


int main(){
    int temp_nr_studenti, x;
    float max = -1;
    std::string temp_nume;
    int n;
    std::vector<Student>studenti;
    std::vector<float>temp_note;
    float temp_nota;
    std::cin >> temp_nr_studenti;
    for(int i = 0 ; i < temp_nr_studenti ; ++i){
        std::cin >> temp_nume;
        std::cin >> n;
        for(int j = 0 ; j < n ; ++j){
            std::cin >> temp_nota;
            temp_note.push_back(temp_nota);
        }
        
        Student s(temp_note, temp_nume, n);
        studenti.push_back(s);
        temp_note.clear();
        float ma = studenti[i].medie();
        
        if(max < ma)
            max = ma, x = i;
    }
    std::cout << studenti[x].get_nume();
    return 0;
}
