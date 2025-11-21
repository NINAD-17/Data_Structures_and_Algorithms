#include <iostream>
using namespace std;

// 1. Friend Function
class Box {
private:
    int width;

public:
    Box(int w) : width(w) {}

    // Declare friend function
    friend void printWidth(Box b);
};

// Friend function definition (outside class)
void printWidth(Box b) {
    // Can access private member 'width'
    cout << "Width of box: " << b.width << endl;
}
// --------------------------------

// 2. Friend Class
class A {
private:
    int secret = 42;

    // Declare class B as a friend
    friend class B;
};

class B {
public:
    void showSecret(A obj) {
        cout << "Secret from A: " << obj.secret << endl;
    }
};
// --------------------------------

int main() {
    Box b1(10);
    printWidth(b1);  // ✅ Allowed: friend function can access private data
    return 0;
}
