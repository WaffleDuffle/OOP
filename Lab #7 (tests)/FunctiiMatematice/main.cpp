#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
class MathFunction{
    protected:
        std::string function_name;
    public:
        MathFunction(std::string function_name):function_name(function_name){}
        virtual void afisare(){};
        std::string get_name(){
            return function_name;
        }
        virtual void radacini(){}
        virtual float get_value(int x){ 
            
            return 0;
        }
        
        virtual float get_max_value(int a, int b){
            float maxi = -9999;
            for(int i = a ; i <= b ; ++i){
                if(maxi < get_value(i))
                    maxi = get_value(i);
            }
            return maxi;
        }
        
        virtual float aprox(MathFunction* m){return 0;}
};

class Exponential: public MathFunction{
    private:
        const float e = 2.71;
        float constant;
        float exp_coeff;
    public:
        Exponential(std::string function_name, float constant, float exp_coeff):MathFunction(function_name), constant(constant), exp_coeff(exp_coeff){}
        void afisare(){
            std::cout << "f(x) = ";
            if(constant != 0)
                std::cout << constant;
            if(exp_coeff > 0){
                if(exp_coeff == 1)
                    std::cout << " + e^x";
                else
                    std::cout << " + " << exp_coeff << "e^x";
            }
            else if(exp_coeff < 0){
                if(exp_coeff == -1)
                    std::cout << " - e^x";
                else
                    std::cout << " - " << exp_coeff << "e^x";
            }
            std::cout << std::endl;
        }
        
        float get_value(int x){
    
            return (constant + exp_coeff*pow(e,x));
        }
};

class Polynomial: public MathFunction{
    protected:
        std::vector<float> coefficients;
    public:
        Polynomial(std::string function_name, std::vector<float> coefficients):MathFunction(function_name), coefficients(coefficients){
            
        }
        void afisare(){
            std::cout << "f(x) = " << coefficients[0];
            if(coefficients.size() > 1 && coefficients[1] > 0){
                if(coefficients[1] == 1)
                    std::cout << " + x";
                else
                    std::cout << " + " << coefficients[1] << "x";
            }
            else if(coefficients.size() > 1 && coefficients[1] < 0){
                if(coefficients[1] == -1)
                    std::cout << " - x";
                else
                    std::cout << " - " << coefficients[1]*-1 << "x";
            }
               
                for(int i = 2 ; i < coefficients.size() ; ++i){
                    if(coefficients[i] > 0){
                        if(coefficients[i] == 1)
                            std::cout << " +  x^" << i;
                        else
                            std::cout << " + " << coefficients[i] << "x^" << i;
                    }
                    else if(coefficients[i] < 0){
                        if(coefficients[i] == -1)
                            std::cout << " - x^" << i;
                        else
                            std::cout << " - " << coefficients[i]*-1 << "x^" << i;
                    }
            }
            
            std::cout << std::endl;
        }
        
        float get_value(int x){
            float s = 0;
            for(int i = 0 ; i < coefficients.size() ; ++i)
                s += coefficients[i]*pow(x,i);
            
            return s;
        }
};

class Quadratic: public Polynomial{
    public:
        Quadratic(std::string function_name, std::vector<float> poli):Polynomial(function_name, poli){}
        void radacini(){
            float x1, x2, delta;
            delta = coefficients[1]*coefficients[1] - 4*coefficients[0]*coefficients[2];
            if(delta > 0){
                std::cout << std::fixed << std::setprecision(2) << "X1 = " << (-coefficients[1]+sqrt(delta))/(2*coefficients[2]) << std::endl;
                std::cout << std::fixed << std::setprecision(2) << "X2 = " << pow((-coefficients[1]-sqrt(delta))/(2*coefficients[2]),-1) << std::endl;
            }
            else
                std::cout << std::fixed << std::setprecision(2) << "X1 = X2 = " << -coefficients[1]/(2*coefficients[2]) << std::endl;
        }
        
};

class DiscreteFunction: public MathFunction{
    private:
        std::vector<float> x_values;
        std::vector<float> y_values;
    public:
        
        DiscreteFunction(std::string name, std::vector<float> x_values , std::vector<float> y_values):MathFunction(name),x_values(x_values), y_values(y_values){}
        
        float aprox(MathFunction* f){
            float s = 0;
            for(int i = 0 ; i < x_values.size() ; ++i){
                s += abs(f->get_value(x_values[i]) - y_values[i]);
            }
            return s;
        }
};

int main(){
    int n;
    std::string nume;
    std::vector<MathFunction*> vec;
    std::cin >> n;
    for(int i = 0 ; i < n ; ++i){
        
        std::cin >> nume;
        if(nume == "Polynomial"){
            int nr_poli, poli;
            std::vector<float> polinoame;
            
            std::cin >> nr_poli;
            
            for(int j = 0 ; j < nr_poli ; ++j){
                std::cin >> poli;
                polinoame.push_back(poli);
                
            }
            vec.push_back(new Polynomial(nume, polinoame));
        }
        else if(nume == "Quadratic"){
            int poli;
            std::vector<float> polinoame;
            
            for(int i = 0 ; i < 3 ; ++i){
                std::cin >> poli;
                polinoame.push_back(poli);
            }
            vec.push_back(new Quadratic(nume, polinoame));
        }
        else if(nume == "Exponential"){
            int con, expo;
            std::cin >> con >> expo;
            vec.push_back(new Exponential(nume, con, expo));
            
        }
    }
    int test;
    std::cin >> test;
    switch(test){
        case 1:{
            for(int i = 0 ; i < vec.size() ; ++i){
                std::cout << vec[i]->get_name() << std::endl;
                vec[i]->afisare();
            }
            break;
        }
        case 2:{
            for(int i = 0 ; i < vec.size() ; ++i)
                if(vec[i]->get_name() == "Quadratic")
                    vec[i]->radacini();
            break;
        }
        case 3:{
            int val_inf, val_sup;
            std::cin >> val_inf >> val_sup;
            for(int i = 0 ; i < vec.size() ; ++i){
                    std::cout << std::fixed << std::setprecision(2) << vec[i]->get_max_value(val_inf, val_sup) << std::endl;
            }
            break;
        }
        case 4:{
            int x, y, k;
            std::vector<float> xv;
            std::vector<float> yv;
            float mini = 9999;
            for(int i  = 0 ; i < 3 ; ++i){
                std::cin >> x;
                xv.push_back(x);
            }
            for(int i  = 0 ; i < 3 ; ++i){
                std::cin >> y;
                yv.push_back(y);
            }
            MathFunction* m = new DiscreteFunction("a",xv, yv);
            for(int i = 0 ; i < vec.size() ; ++i){
                if(mini > m->aprox(vec[i]))
                    mini = m->aprox(vec[i]), k = i;
                    
            }
            vec[k]->afisare();
            std::cout << mini << std::endl;
            
            break;
        }
    }
        
    
    return 0;
}