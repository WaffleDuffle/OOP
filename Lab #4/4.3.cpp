// În urma rulării codului din funcția main() se vor afișa pe ecran nota maximă a studenților seriei selectate, respectiv media notelor lor. Constructorul clasei Serie are rolul de a prelua din vectorul de intrare și a reține doar studenții care aparțin seriei selectate ('A').

#include <iostream>
#include <string>
class Persoana{
    protected:
        std::string nume;
    public:
        Persoana(std::string nume):nume(nume){}
        std::string get_nume(){
            return nume;
        }
};
class Student:public Persoana{
    private:
        char serie;
        int nota;
    public:
    Student(std::string nume, char serie, int nota):Persoana(nume), serie(serie), nota(nota){}
        void display(){
            std::cout << nume << std::endl << serie << std::endl << nota << std::endl;
        }
    char get_serie(){
        return serie;
    }
    int get_nota(){
        return nota;
    }
};

class Serie{
    private:
        char serie;
        Student** p_studenti;
        int nr_studenti;
    public:
        Serie(char serie, Student studenti[], int nr_studenti):serie(serie), nr_studenti(nr_studenti), p_studenti(nullptr){
            int nr = 0;
            p_studenti = new Student*[this->nr_studenti];
            for(int i = 0 ; i < nr_studenti ; ++i)
                if(serie == studenti[i].get_serie()){
                    p_studenti[nr] = new Student(studenti[i].get_nume(), studenti[i].get_serie(), studenti[i].get_nota());
                    nr++;
                }
            this->nr_studenti = nr;
            
        }
        int nota_max(){
            int maxi = -1;
            
            for(int i = 0 ; i < nr_studenti ; ++i){
                if(maxi < p_studenti[i]->get_nota())
                    maxi = p_studenti[i]->get_nota();
            }
            return maxi;
        }
        float nota_medie(){
            float medie = 0;
            for(int i = 0 ; i < nr_studenti ; ++i)
                medie += p_studenti[i]->get_nota();
            return medie/nr_studenti;
        }
        void display(){
            // std::cout << this->nr_studenti;
            for(int i = 0 ; i < nr_studenti ; ++i)
                p_studenti[i]->display();
        }
        
};

int main(){
    Student studenti[] = {Student("Costache", 'A', 9),
                          Student("Dobre", 'B', 10),
                          Student("Enache", 'A', 8),
                          Student("Faur", 'A', 5),
                          Student("Georgescu", 'B', 2),
                          Student("Harapu", 'A', 10),
                          Student("Ionescu", 'C', 7),
                          Student("Jianu", 'B', 9),
                          Student("Konstantinos", 'A', 10),
                          Student("Laica", 'B', 3),
                          Student("Manea", 'A', 9)};
    Serie s('A', studenti, sizeof(studenti)/sizeof(Student));
    // s.display();
    std::cout << s.nota_max() << std::endl;
    std::cout << s.nota_medie() << std::endl;
    
    return 0;
}
