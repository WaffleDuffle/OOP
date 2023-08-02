// Se dă codul din funcția main. De asemenea, se dă și clasa abstractă Poligon. Să se implementeze toate clasele necesare, conform diagramei UML de mai jos.

// Rularea programului principal trebuie să afișeze următoarele rezultate:
// 2.90474 9
// 9 12
// 24 22

#include <iostream>
#include <cmath>

class Poligon{
public:
    virtual float aria()=0;
    virtual float perimetru()=0;
    virtual ~Poligon(){}
};

class Triunghi: public Poligon{
    private:
        float a ,b, c;
    public:
        Triunghi(int a, int b, int c):a(a),b(b),c(c){}
        float aria(){
            float sp = (a+b+c)/2;
            return sqrt(sp*(sp-a)*(sp-b)*(sp-c));
        }
        float perimetru(){
            return a+b+c;
        }
};

class Patrulater: public Poligon{
    protected:
        float l1, l2, l3, l4;
    public:
        Patrulater(float l1, float l2, float l3, float l4):l1(l1),l2(l2),l3(l3),l4(l4){}

};

class Dreptunghi: public Patrulater{
    
    public:
        Dreptunghi(float l, float L):Patrulater(l,L,l,L){}
        float aria(){
            return l1*l2;
        }
        float perimetru(){
            return 2*l1 + 2*l2;
        }
};

class Patrat: public Dreptunghi{
    
    public:
        Patrat(float l):Dreptunghi(l,l){}
        
};


int main(){
    Poligon *p[3] = {new Triunghi(2, 3, 4), new Patrat(3), new Dreptunghi(3, 8)};
    for (int i=0; i<3; i++){
        std::cout << p[i]->aria() << " " << p[i]->perimetru() << std::endl;
        delete p[i];
    }
    return 0;
}
