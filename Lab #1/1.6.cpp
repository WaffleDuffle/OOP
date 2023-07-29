// Se va crea o clasă Segment, care este definită în spațiu de o pereche de puncte în coordonate carteziene în plan tridimensional. Punctele sunt create ca instanțe ale clasei Punct. Să se definească un constructor cu 6 argumente pentru clasa Segment și o funcție care să calculeze lungimea segmentului. În programul principal se va instanția un obiect de tipul Segment, prin citirea de la tastatură a celor 6 atribute, în ordinea x1, y1, z1, x2, y2, z2 și se va afișa pe ecran lungimea segmentului, cu 2 zecimale.

#include <iostream>
#include <iomanip>
#include <cmath>// biblioteca necesara pentru std::setprecision

class Punct{
private:
    float x;
    float y;
    float z;
    
public:
    float get_x(){
        return this->x;
    }
    float get_y(){
        return this->y;
    }
    float get_z(){
        return this->z;
    }
    void set_x(float x){
        this -> x = x;
    }
    void set_y(float y){
        this -> y = y;
    }
    void set_z(float z){
        this -> z = z;
    }
    Punct(float x, float y, float z):x(x),y(y),z(z){}
};


class Segment{
    private:
        Punct a;
        Punct b;
    public:
         Segment(float x1, float y1, float z1, float x2, float y2, float z2):a(x1, y1, z1), b(x2, y2, z2){}
       /* Segment(float x1, float y1, float z1, float x2, float y2, float z2){
            a.set_x(x1);
            a.set_y(y1);
            a.set_z(z1);
            b.set_x(x2);
            b.set_y(y2);
            b.set_z(z2);
        }*/
        float lungime(){
            return sqrt((a.get_x()-b.get_x())*(a.get_x()-b.get_x()) + (a.get_y()-b.get_y())*(a.get_y()-b.get_y()) + (a.get_z()-b.get_z())*(a.get_z()-b.get_z()));
        }
 
};
int main()
{
    float x1,x2,y1,y2,z1,z2;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Segment s(x1,y1,z1,x2,y2,z2);
    std :: cout << std :: fixed << std :: setprecision(2) << s.lungime();
    return  0;    
}

