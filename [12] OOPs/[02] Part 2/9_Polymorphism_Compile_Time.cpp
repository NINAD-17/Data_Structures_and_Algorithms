#include <iostream>
using namespace std;

// A) Compile time polymorphism
//      - Function overloading
//      - Operator overloading

class A {
    public:
        // -- Function Overloading
        void sayHello() {
            cout << "Hello unknown user!" << endl;
        }

        void sayHello(string name) {
            cout << "Hello " << name << "!" << endl;
        }

        // different number of arguments
        void sayHello(string name, string email) {
            cout << "Hello " << name << " \n" << email << " " << endl;
        }

        // different type of arguments
        void sayHello(int age) {
            cout << "Hello " << age << " years old!" << endl;
        }

        // default arguments
        void sayHello(string name, int age, char luckyChar = 'A', int password = 123) {
            cout << "\nHello " << name << " \n" << age << " " << luckyChar << " " << password << endl;
        }
};

class B {
    // -- Operator Overloading
    public: 
        int a;
        int b;

        int add() {
            return a + b;
        } 

        // Overloading `+` operator
        int operator+ (B &objB) { // Don't forget to 'pass by reference' otherwise it will get stuck in infinite loop.
            int value1 = this -> a;
            int value2 = objB.a;

            cout << "Answer of + operator is ";
            return value2 - value1;
        }

        // Overloading `()` parentheses
        void operator() () {
            cout << "I'm a bracket - " << this -> a << endl;
        }
};

// -- Method overloading
class Animal {
    public: 
        void speak() {
            cout << "Speaking..." << endl;
        }
};

class Dog: public Animal {
    public:
        void speak() {
            cout << "Barking..." << endl;
        }
};

int main() {

    A object;

    // -- Function overloading
    object.sayHello();
    object.sayHello("John");
    object.sayHello(55);
    object.sayHello("John", 1, 'A');
    object.sayHello("hoh", "email");

    // -- Operator Overloading
    B obj1, obj2;
    obj1.a = 10;
    obj2.a = 20;

    cout << obj1 + obj2 << endl; // In case of +, second operand is a input argument and the first operand is current object (access by this keyword)
    obj1(); // We're calling operator()
    obj2();

    // -- Method overloading
    Dog yeontan;
    yeontan.speak(); // It will give an output "barking" and not "speaking"

    return 0;
}