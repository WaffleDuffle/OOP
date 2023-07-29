// Pentru clasa Punctaj se va defini un destructor, un constructor de copiere și o funcție membră care modifică nota de la un index dat. Ulterior:
// Se va instanția un obiect de tip Punctaj folosind constructorul cu 2 parametri - numărul de note, respectiv un pointer către un vector de întregi reprezentând valorile notelor;
// Se va crea o nouă instanță prin copierea acestuia;
// Se va modifica nota de la un anumit index cu o nouă valoare (atât indexul, cât și valoarea vor fi citite de la tastatură);
// Se vor afișa pe ecran notele celui de-al doilea obiect.

// Se va apela în mod explicit destructorul primului obiect, după care se vor afișa din nou pe ecran notele celui de-al doilea obiect.

// Aceasta problema nu are baterie de teste, ci ofera doar input-ul in mod 
// automat. Output-ul va fi urmarit in caseta de dialog
#include <iostream>
class Punctaj{
private:
    int nr_note;
    int *note;
public:
    Punctaj(int nr_note, int *note){
        this->nr_note = nr_note;
        this->note = new int[nr_note];
        for(int i = 0 ; i < nr_note ; i++){
            *(this -> note + i) = *(note + i);}
    }
    Punctaj(Punctaj &p){
        this->nr_note = p.nr_note;
        this->note = new int[this->nr_note];
        for(int i = 0 ; i < nr_note ; i++)
            *(this->note + i) = *(p.note + i);
    }
    void schimbare(int i, int x){
        *(note + i) = x;
    }
    void afisare(){
        for(int i = 0 ; i < nr_note ; i++)
            std::cout << *(note + i) << " "; 
    }
    ~Punctaj(){
        delete [] note;
    }

};
int main(){
    int numar_note, index, val;
    std::cin >> numar_note;
    int *note = new int[numar_note];
    for(int i = 0 ; i < numar_note ; i++)
        std::cin >> *(note + i);
    std::cin >> index >> val;
    Punctaj e1(numar_note, note);
    Punctaj e2(e1);
    e2.schimbare(index,val);
    e2.afisare();
    return 0;
}
