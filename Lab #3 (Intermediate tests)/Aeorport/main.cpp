#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
class Zbor{
    private:
        std::string oras_plecare;
        std::string oras_sosire;
        int ora_plecare, min_plecare;
        int ora_sosire, min_sosire;
    public:
        void display(){
            std::cout << oras_plecare << " - " << oras_sosire << std::endl;
            std::cout << ora_plecare << ":" << min_plecare << " - " << ora_sosire << ":" << min_sosire << std::endl;
        }
        void display2(){
            std::cout << oras_plecare << " - " << oras_sosire << std::endl;
        }
        Zbor(std::string oras_plecare,std::string oras_sosire, 
        int ora_plecare, int min_plecare, 
        int ora_sosire, int min_sosire):
        oras_plecare(oras_plecare), oras_sosire(oras_sosire), 
        ora_plecare(ora_plecare), min_plecare(min_plecare),
        ora_sosire(ora_sosire), min_sosire(min_sosire){}
        
        std::string get_oras_plecare(){
            return oras_plecare;
        }
        std::string get_oras_sosire(){
            return oras_sosire;
        }
        int get_ora_plecare(){
            return ora_plecare;
        }
        int get_min_plecare(){
            return min_plecare;
        }
        int get_ora_sosire(){
            return ora_sosire;
        }
        int get_min_sosire(){
            return min_sosire;
        }
};

class Aeroport{
    private:
        Zbor **vector;
        int nr_zboruri;
        
    public:
        Aeroport():vector(nullptr),nr_zboruri(0){}
        
        void add_zbor(Zbor z){
            if(vector == nullptr){
                vector = new Zbor*[1];
                vector[0] = new Zbor(z);
                this->nr_zboruri++;
            }
            else{
                Zbor **vec_nou;
                vec_nou = new Zbor*[nr_zboruri+1];
                for(int i = 0 ; i < this->nr_zboruri ; ++i)
                    vec_nou[i] = vector[i];
                vec_nou[this->nr_zboruri] = new Zbor(z);
                vector = vec_nou;
                this->nr_zboruri++;
            }
        }
        void check_go(int x){
            if(x == 0){
                for(int i = 0 ; i < nr_zboruri ; ++i)
                    if(vector[i]->get_oras_plecare() == "Bucuresti")
                        vector[i]->display();
            }
            else{
                for(int i = 0 ; i < nr_zboruri ; ++i)
                    if(vector[i]->get_oras_sosire() == "Bucuresti")
                        vector[i]->display();
            }
        }
        void check_zbor_timp(int temp_ora_plecare, int temp_min_plecare, int temp_ora_sosire, int temp_min_sosire){
            for(int i = 0 ; i < nr_zboruri ; ++i){
                if(vector[i]->get_oras_plecare() == "Bucuresti"){
                    if(((vector[i]->get_ora_plecare() >= temp_ora_plecare && 
                    (vector[i]->get_min_plecare() >= temp_min_plecare)
                    && ((vector[i]->get_ora_sosire() <= temp_ora_sosire && 
                    (vector[i]->get_min_sosire() <= temp_min_sosire))))))
                        vector[i]->display();
                }
            }
        }
        float check_viteza(float x, int i){
            float t;
            
                t = 60 - vector[i]->get_min_plecare() + vector[i]->get_min_sosire();
                t /= 60;
                t = t + vector[i]->get_ora_sosire() - vector[i]->get_ora_plecare() - 1;
                return (float) x/t;
        }
        float check_profit(float x, int i){
            float t, suma = 0, cost = 0;
            t = 60 - vector[i]->get_min_plecare() + vector[i]->get_min_sosire();
            t /= 60;
            t = t + vector[i]->get_ora_sosire() - vector[i]->get_ora_plecare() - 1;
            suma = 0.150 * x * 400;
            cost = t * 10000;
            float z = suma-cost;
            if(floor(z) != z)
                z = z + 0.01;
            return (float)z; 
        }
        void afisare2(int i){
            vector[i]->display2();
        }
        void afisare(int i){
            vector[i]->display();
        }
};

int main(){
    std::string temp_oras_plecare;
    std::string temp_oras_sosire;
    int temp_ora_plecare, temp_min_plecare;
    int temp_ora_sosire, temp_min_sosire;
    int n, test;
    Aeroport A;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin.ignore();
        std::cin >> temp_oras_plecare >> temp_oras_sosire;
        std::cin >> temp_ora_plecare >> temp_min_plecare;
        std::cin >> temp_ora_sosire >> temp_min_sosire;
        Zbor z(temp_oras_plecare, temp_oras_sosire, temp_ora_plecare, temp_min_plecare, temp_ora_sosire, temp_min_sosire);
        A.add_zbor(z);
    }
    std::cin >> test;
    switch(test){
        case 1:{
            int k;
            std::cin >> k;
            A.check_go(k);
            break;
        }
        case 2:{
            std::cin >> temp_ora_plecare >> temp_min_plecare;
            std::cin >> temp_ora_sosire >> temp_min_sosire;
            A.check_zbor_timp(temp_ora_plecare, temp_min_plecare, temp_ora_sosire, temp_min_sosire);
            break;
        }
        case 3:{
            int viteza;
            float v[n];
            for(int i = 0 ; i < n ; ++i){
                std::cin >> viteza;
                v[i] = A.check_viteza(viteza,i);
            }
            for(int i = 0 ; i < n ; ++i){
                A.afisare(i);
                std::cout << std::fixed << std::setprecision(2) << v[i] << std::endl;
            }
            break;
        }
        case 4:{
            int viteza;
            float v[n];
            for(int i = 0 ; i < n ; ++i){
                std::cin >> viteza;
                v[i] = A.check_profit(viteza,i);
            }
            for(int i = 0 ; i < n ; ++i){
                A.afisare2(i);
                std::cout << std::fixed << std::setprecision(2) << v[i] << std::endl;
            }
            break;
        }
    }
    return 0;
}




