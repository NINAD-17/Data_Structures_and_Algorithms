#include <iostream>
using namespace std;

int main() {
    char ch = 'c';
    cout << "Size of char: " << sizeof(ch) << endl;
    
    char *c = &ch;
    cout << "Size of pointer: " << sizeof(c) << endl;

    int n;
    cout << "Enter size of array: "; cin >> n;

    // Allocating n size in heap
    int *arr = new int[n];

    delete []arr; // Deallocate space
}