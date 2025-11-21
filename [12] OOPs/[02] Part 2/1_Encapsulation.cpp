#include <iostream>
using namespace std; 

class Student {

    // By default private, so don't need to explicitly write 'private:'. These cannot be accessed directly outside the class.
    private:
        string name;
        int age;
        int height;
    
    // Public Access Modifier: These act as controlled "gateways" to access private data.
    public:
        // Getter for age (read-only access)
        int getAge() { 
            return this -> age; // 'this' is a pointer to the current object
        }

        // Setter for age (write access)
        void setAge(int a) {
            age = a;
        }

        // Getter for name
        string getName() {
            return name;
        }

        // Setter for name
        void setName(string n) {
            name = n;
        }

        // Getter for height
        int getHeight() {
            return height;
        }

        // Setter for height
        void setHeight(int h) {
            height = h;
        }

        // Utility function to print all details
        void printDetails() {
            cout << "Name: " << name << ", Age: " << age 
                 << ", Height: " << height << endl;
        }
};

int main() {

    // Static object creation
    Student s1;

    // s1.age; // Not accessible (private member)
    // Instead, use setters:
    s1.setName("Ninad");
    s1.setAge(21);
    s1.setHeight(175);

    // Access values using getters:
    cout << "Age of student: " << s1.getAge() << endl;
    cout << "Name of student: " << s1.getName() << endl;

    // Print all details
    s1.printDetails();

    return 0;
}