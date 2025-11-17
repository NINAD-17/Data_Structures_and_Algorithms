#include <iostream>
using namespace std;

/************ BAD PRACTICE **************/

// Return Reference
int& update(int n) {
    int a = 10;
    int &ans = a; // Storing value of 'a' i.e 10 in ans variable.
    return ans; // returning ans variable as a reference.
}

// Return Pointer
int* retPointer(int n) {
    int *ptr = &n; // Here n is a local var, and we're giving storing its address in ptr pointer
    return ptr; // Returning a pointer which stores address of local variable. So it's dangerous
}

int main() {
    int n = 5;

    int a = update(n);
    cout << a << endl;

    return 0;
}