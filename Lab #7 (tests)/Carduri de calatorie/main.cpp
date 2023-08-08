#include <iostream>
#include "Card_calatorie.h"
#include <vector>
class Autobuz: public Card_calatorie{
    private:
        int sold;
    public:
        Autobuz(int id, char tip, int sold):Card_calatorie(id,tip), sold(sold){}
        void display(){
            std::cout << get_id() << " " << get_tip() << " " << sold << " " << get_moment() << std::endl;
        }
        void incarcare(int x){
            sold += x;
        }
        void validare_calatorie(int x, int y){
            if(x - get_moment() <= 90)
                return;
            
            else{    
            if(sold > 3)
                sold -= 3, set_moment(x);
            else
                std::cout << "Sold insuficient" << std::endl;
            }
        }
        void verificare_sold_calatorii(){
            
        }
        bool verificare(int x){
            return (sold > x);
        }
};

class Metrou: public Card_calatorie{
    private:
        int nr_calatorii;
    public:
        Metrou(int id, char tip, int nr_calatorii):Card_calatorie(id,tip), nr_calatorii(nr_calatorii){}
        void display(){
            std::cout << get_id() << " " << get_tip() << " " << nr_calatorii << " " << get_moment() << std::endl;
        }
        void incarcare(int x){
            nr_calatorii += x;
        }
        void validare_calatorie(int x, int y){
            if(x - get_moment() <= 90)
                return;
            else{
            if(nr_calatorii > 0)
                nr_calatorii -= 1, set_moment(x);
            else
                std::cout << "Numar calatorii insuficient" << std::endl;
            }
            
        }
        bool verificare(int x){
            return (nr_calatorii > x);
        }
};

int main(){
    int n, test;
    int temp_id, sold_calatorii, temp_moment;
    char temp_tip;
    std::vector <Card_calatorie*> vec;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        std::cin >> temp_tip >> temp_id >> sold_calatorii;
        if(temp_tip == 'a')
            vec.push_back(new Autobuz(temp_id, temp_tip, sold_calatorii));
        else
            vec.push_back(new Metrou(temp_id, temp_tip, sold_calatorii));
    }
    
    do{
        std::cin >> test;
        switch(test){
            case 1:{
                for(int i = 0 ; i < vec.size() ; ++i)
                    vec[i]->display();
                break;
            }
            case 2:{
                std::cin >> temp_id >> sold_calatorii;
                for(int i = 0 ; i < vec.size() ; ++i)
                    if(temp_id == vec[i]->get_id())
                        vec[i]->incarcare(sold_calatorii);
                break;
            }
            case 3:{
                std::cin >> temp_id >> temp_moment;
                for(int i = 0 ; i < vec.size() ; ++i)
                    if(temp_id == vec[i]->get_id()){
                        vec[i]->validare_calatorie(temp_moment,0);
                    }
                        
                break;
            }
            case 4:{
                int id1, id2, k1, k2;
                char tip1, tip2;
                std::cin >> id1 >> id2 >> sold_calatorii;
                for(int i = 0 ; i < vec.size() ; ++i){
                    if(id1 == vec[i]->get_id())
                        tip1 = vec[i]->get_tip(), k1 = i; 
                    else if(id2 == vec[i]->get_id())
                        tip2 = vec[i]->get_tip(), k2 = i;
                }                   
                if(tip1 != tip2 || vec[k1]->verificare(sold_calatorii) == 0)
                    std::cout << "Transfer nereusit" << std::endl;
                else
                    vec[k1]->incarcare(-1*sold_calatorii), vec[k2]->incarcare(sold_calatorii);
                break;
            }
        }
        
    }while(test != 5);
    
    return 0;
}