#include <iostream>
using namespace std;

// Abstract class
class Animal {
public:
    // Pure virtual function (no implementation here)
    virtual void sound() = 0;

    // Normal function (can have implementation)
    void sleep() {
        cout << "Animal is sleeping..." << endl;
    }
};

// Derived class Dog implements sound()
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks: Woof Woof!" << endl;
    }
};

// Derived class Cat implements sound()
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow Meow!" << endl;
    }
};

int main() {
    // Abstract class cannot be instantiated directly
    // Animal a; // ❌ Error

    // But we can use base class pointers
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->sound();   // Dog barks
    a2->sound();   // Cat meows

    a1->sleep();   // Common function from base class
    a2->sleep();

    delete a1;
    delete a2;

    return 0;
}
