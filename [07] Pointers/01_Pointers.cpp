#include <iostream>
using namespace std;

int main() {
    int num = 5;

    // Address
    cout << "Address of num: " << &num << endl;

    // Pointer
    int *ptr = &num;
    cout << "Address of num stored in ptr: " << ptr << endl;

    // Size of pointer 
    cout << "Size of num(integer): " << sizeof(num) << endl;
    cout << "Size of *ptr(pointer which stores integer data type's address): " << sizeof(ptr) << endl;

    // Without using pointer and copying just number
    int a = num;
    a++;
    cout << "Value of num after updating a: " << num << endl;

    int *b = &num;
    int c = *b;
    c++;
    cout << "Value of num after updating c: " << num << endl;

    // By using pointer
    int *d = &num;
    (*d)++;
    cout << "Value of num after updating d: " << num << endl;

    // Copying pointer in another pointer
    int *e = &num;
    int *f = e;
    cout << "Comparing e and f ----- \n";
    cout << "Address: " << e << " <--> " << f << endl;
    cout << "Value: " << *e << " <--> " << *f << endl;

    return 0;
}