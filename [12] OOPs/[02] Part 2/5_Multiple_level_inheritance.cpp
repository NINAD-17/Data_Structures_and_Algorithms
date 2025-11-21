#include <iostream>
using namespace std;

// Multiple-level
// Animal -> Hybrid
// Human -> Hybrid

class Animal {

    public: 
        int age;
        int weight;

        void bark() {
            cout << "Barking 🐶" << endl;
        }
};

class Human {
    public: 
        void speak() {
            cout << "Speaking 🧑‍🦱";
        }
};

// Multiple Inheritance
class Hybrid: public Animal, public Human {

};

int main() {
    Hybrid obj1;

    obj1.bark();
    obj1.speak();
    
    return 0;
}