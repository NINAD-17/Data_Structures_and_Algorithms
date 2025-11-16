#include <iostream>
using namespace std;

void update(int **ptr2) {
    // Uncomment each line below one by one and execute code to see output. Don't uncomment all lines and run all lines at once.
    // ptr2 = ptr2 + 1; // Change will be only in function. So no change in original values
    // *ptr2 = *ptr2 + 1; // Change in address pointed by ptr. Change in original value.
    // **ptr2 = **ptr2 + 1; // Change in value of ptr2 ==> 6. Change in original value.
}

int main() {
    int i = 5;
    int *ptr = &i;
    int **ptr2 = &ptr;

    // Addresses
    cout << "Printing Address of i ------------ " << endl;
    cout << "1. Using &i: " << &i << endl;
    cout << "2. Using ptr: " << ptr << endl;
    cout << "3. Using *ptr2: " << *ptr2 << endl << endl;

    cout << "Printing address of ptr ---------- " << endl;
    cout << "1. Using &ptr: " << &ptr << endl;
    cout << "2. Using ptr2: " << ptr2 << endl << endl;

    cout << "Printing address of ptr2 --------- " << endl;
    cout << "1. Using &ptr2: " << &ptr2 << endl << endl;

    // Values
    cout << "Printing value in the i ---------- " << endl;
    cout << "1. Using i: " << i << endl;
    cout << "2. Using *ptr: " << *ptr << endl;
    cout << "3. Using **ptr2: " << **ptr2 << endl << endl;

    cout << "Printing value in the ptr (i.e address of i) -------- " << endl;
    cout << "1. Using ptr: " << ptr << endl;
    cout << "2. Using *ptr2: " << *ptr2 << endl << endl;

    cout << "Printing value in the ptr2 (i.e address of ptr)-------- " << endl;
    cout << "1. Using ptr2: " << ptr2 << endl << endl; 

    // Double Pointers in Function -------------------------------------------------
    cout << "Before i: " << i << endl;
    cout << "Before ptr: " << ptr << endl;
    cout << "Before ptr2: " << ptr2 << endl;
    update(ptr2);
    cout << "After i: " << i << endl;
    cout << "After ptr: " << ptr << endl;
    cout << "After ptr2: " << ptr2 << endl;    

    return 0;
}