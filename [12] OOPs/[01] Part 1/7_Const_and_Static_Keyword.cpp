#include <iostream>
using namespace std;

class Hero {
    public: 
        int health;
        int power;
        static int timeToComplete;

        // Normal constructor
        Hero() {
            cout << "Normal constructor called!" << endl;
        }

        // Initialization list in constructor
        Hero(int health, int power) : health(health), power(power) {
            cout << "Constructor initialized health: " << health << ", power: " << power << endl;
        }

        void setHealth(int health) {
            this -> health = health;
        }

        static int random() {
            // cout << this -> health << endl; // Error: as it can't have access to non-static members.
            cout << timeToComplete << endl; // It can only access static members only.
        }

        int getHealth() {
            (this -> health)++;
            return this -> health;
        }

        void setPower(int power) {
            this -> power = power;
        }

        int getPower() const {
            // (this -> power)++; // Error: As you've defined a const member function
            return this -> power;
        }
};

// 1. Initialize the static data member
int Hero::timeToComplete = 5;
int main() {

    int num = 100;

    // --- Constant Keyword
    const int num1 = 10;  
    // num1++; // ❌ Error: num1 is constant, its value cannot be modified after initialization.
    // Rule: const variables must be initialized at the time of declaration and cannot be reassigned later.


    // -----------------------------
    // Case 1: const int* num2 = &num1;
    // -----------------------------
    // "Pointer to a constant int"
    // Meaning: You cannot change the value through this pointer, but the pointer itself can point to another int.
    const int* num2 = &num1;  
    // *num2 = 20; // ❌ Error: cannot modify the value (num1) via num2
    // num2 = &someOtherInt; // ✅ Allowed: pointer can be redirected to another int


    // -----------------------------
    // Case 2: int* const num3 = &num;
    // -----------------------------
    // "Constant pointer to int"
    // Meaning: The pointer itself cannot change (always points to the same address), 
    // but the value at that address can be modified.
    int num = 50;
    int* const num3 = &num;  
    // *num3 = 60; // ✅ Allowed: can modify the value at address
    // num3 = &anotherInt; // ❌ Error: pointer cannot be reassigned to another address


    // -----------------------------
    // Case 3: const int* const num4 = &num1;
    // -----------------------------
    // "Constant pointer to a constant int"
    // Meaning: Neither the pointer can change, nor the value it points to can be modified.
    const int* const num4 = &num1;  
    // *num4 = 30; // ❌ Error: cannot modify value
    // num4 = &anotherInt; // ❌ Error: cannot change pointer target


    Hero captain;
    captain.setHealth(100);
    cout << "Health of captain: " << captain.getHealth() << endl; 

    // --- Initialization list in constructors
    Hero spiderman(100, 90);

    // --- Constant object creation
    const Hero thor(10, 99); // Can only be defined at initialization of object
    // thor.setHealth(100); // Error: Modification not allowed


    // --- Static Keyword
    cout << "Time to complete of hero: " << Hero::timeToComplete << endl;
    cout << "Time to complete for thor: " << thor.timeToComplete << endl; // Not Recommende: as static members belongs to class and not object.
    thor.timeToComplete = 8;
    cout << "Time to complete for thor: " << thor.timeToComplete << endl; 
    cout << "Time to complete of hero: " << Hero::timeToComplete << endl; 

    // --- Static Functions
    Hero::random();

    return 0;
}