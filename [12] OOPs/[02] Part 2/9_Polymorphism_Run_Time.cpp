#include <iostream>
using namespace std;

// B) Run time polymorphism
//      - Method Overriding

class Animal {
    public:
        virtual void sound() {   // virtual function → can be overridden
            cout << "Animal makes a sound" << endl;
        }
};

class Dog : public Animal {
    public:
        void sound() override {   // override base method → confirms overriding base function
            cout << "Dog barks" << endl;
        }
};

class Cat : public Animal {
    public:
        void sound() override {
            cout << "Cat meows" << endl;
        }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound();   // Dog barks (runtime decision)
    a2->sound();   // Cat meows (runtime decision)

    delete a1;
    delete a2;
}     