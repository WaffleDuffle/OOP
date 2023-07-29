// Să se scrie o clasă Coș, care conține 2 date membre: nr_mere, nr_pere. Clasa va conține o funcție care poate transfera mere și pere într-un alt Coș, transmis ca parametru. Funcția va avea următorul prototip:
// void transfer(int nr_mere, int nr_pere, Cos &c)
// Să se inițializeze 2 obiecte de tipul Coș de la tastatură și să se facă transferul unui număr de mere și pere de la primul coș către cel de-al doilea coș. Să se afișeze pe ecran numerele de mere și pere stocate în fiecare dintre cele 2 coșuri atât înainte, cât și după transfer.

#include <iostream>
class Cos{
    private:
        int nr_mere;
        int nr_pere;
    public:
    Cos(int nr_mere = 0, int nr_pere = 0){
        this->nr_mere = nr_mere;
        this->nr_pere = nr_pere;
    }
    void transfer(int nr_mere, int nr_pere, const Cos &c){
        this->nr_mere += c.nr_mere;
        this->nr_pere += c.nr_pere;
    }
    void golire(){
        this->nr_mere = 0;
        this->nr_pere = 0;
    }
    int get_mere(){
        return nr_mere;
    }
    int get_pere(){
        return nr_pere;
    }
};
int main()
{
    int nrm1,nrp1,nrm2,nrp2;
    std::cin >> nrm1 >> nrp1 >> nrm2 >> nrp2;
    Cos c1(nrm1, nrp1);
    Cos c2(nrm2, nrp2);
    std::cout << c1.get_mere() << " " << c1.get_pere() << std::endl << c2.get_mere() << " " << c2.get_pere() << std::endl;
    c2.transfer(nrm1,nrm2,c1);
    c1.golire();
    std::cout << c1.get_mere() << " " << c1.get_pere() << std::endl << c2.get_mere() << " " << c2.get_pere() << std::endl;
    return 0;
}
