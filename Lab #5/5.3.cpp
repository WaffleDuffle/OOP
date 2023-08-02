// Se dă codul din funcția main. Din linia ... lipsesc o parte dintre inițializări. Se cunoaște că fiecare clasă afișează un mesaj de tipul "Dtor <nume_clasa>", după care se trece pe o linie nouă.

// Să se implementeze toate clasele, împreună cu relațiile dintre ele, astfel încât programul să afișeze, în final, următoarele mesaje:
// Dtor A

// Dtor D
// Dtor C
// Dtor A

// Dtor A

// Dtor C
// Dtor A

// Dtor E
// Dtor D
// Dtor C
// Dtor A

// Dtor B
// Dtor A

#include <iostream>
class A{
    public:
    A(){}
    virtual ~A(){
        std::cout << "Dtor A" << std::endl;
    }
};

class C: public A{
    public:
    C(){}
    ~C(){
        std::cout << "Dtor C" << std::endl;
    }
};

class D: public C{
    public:
    D(){}
    ~D(){
        std::cout << "Dtor D" << std::endl;
    }
};

class E: public D{
    public:
    E(){}
    ~E(){
        std::cout << "Dtor E" << std::endl;
    }
};

class B: public A{
    public:
    B(){}
    ~B(){
        std::cout << "Dtor B" << std::endl;
    }
};




int main(){
    A *p_a[6] = {new A(), new D(), new A(), new C(), new E(), new B()/* TODO: completati cu restul initializarilor */};
    for (int i=0; i<6; ++i){
        delete p_a[i];
        std::cout << std::endl;
    }
    return 0;
}
