#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Printing address of 1st index of array: " << arr << endl;

    char ch[10] = "abcde";
    cout << "Printing entire char array: " << ch << endl;

    char *chPtr = &ch[0];
    cout << "Printing entire char array: " << chPtr << endl;
    cout << "Address using & operator: " << &ch << endl;
    cout << "Address of chPtr: " << &chPtr << endl;

    char ch2 = 'A';
    char *chPtr2 = &ch2;
    cout << "Address using & operator: " << &ch2 << endl;
    cout << "Printing content of ch2 using pointer: " << chPtr2 << endl;
    cout << "Printing address of chPtr2 variable: " << &chPtr2 << endl;

    cout << "Printing address of ch2 by type casting it to void*: " << (void*)chPtr2 << endl;

    return 0;
}