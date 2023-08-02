// Să se implementeze codul aferent claselor ale căror date membre urmăresc diagrama UML de mai jos. Nu se va folosi mecanismul funcțiilor/claselor friend.

// Clasele se vor completa cu funcționalitățile necesare astfel încât codul dat în funcția main să întoarcă următoarea secvență de mesaje:
// Ctor Entity
// Ctor Entity
// Ctor Person
// Ctor Entity
// Ctor Person
// Ctor Student

// Entity name: Entity 1
// Person name: Person 1
// Person age: 34
// Student name: Student 1
// Student age: 21
// Student serie: B

#include <iostream>
#include <string>

class Entity{
    protected:
        std::string name;
    public:
        Entity(std::string name):name(name){
            std::cout << "Ctor Entity" << std::endl;
        }
        virtual void display(){
            std::cout << "Entity name: " << name << std::endl;
        }
    std::string get_name(){
        return name;
    }
};

class Person:public Entity{
    protected:
        int age;
    public:
        Person(std::string name, int age):Entity(name), age(age){
            std::cout << "Ctor Person" << std::endl;
        }
        void display(){
            std::cout << "Person name: " << get_name() << std::endl;
            std::cout << "Person age: " << age << std::endl;
        }
        int get_age(){
            return age;
        }
};

class Student: public Person{
    private:
        char serie;
    public:
        Student(std::string name, int age, char serie):Person(name,age),serie(serie){
            std::cout << "Ctor Student" << std::endl;
        }
        void display(){
            std::cout << "Student name: " << get_name() << std::endl;
            std::cout << "Student age: " << get_age() << std::endl;
            std::cout << "Student serie: " << serie << std::endl;
        }
};

int main(){
    Entity e1("Entity 1");
    Person p1("Person 1", 34);
    Student s1("Student 1", 21, 'B');

    std::cout << std::endl;

    Entity *p_entity[3] = {&e1, &p1, &s1};
    for (int i=0; i<3; i++){
        p_entity[i]->display();
    }

    return 0;
}
