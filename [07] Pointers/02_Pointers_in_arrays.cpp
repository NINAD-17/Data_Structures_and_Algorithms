#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Finding address of array elements
    cout << "Address ----------- " << endl;
    cout << "Address of first memory block is " << arr << endl;
    cout << "Address of first memory block is (using 'address of' operator): " << &arr[0] << endl;
    cout << "Address of first memory block is (using 'address of' operator): " << &arr << endl;

    cout << "Address of second memory block is " << arr + 1 << endl;
    cout << "Address of second memory block is (using 'address of' operator): " << &arr[1] << endl;
    cout << endl;

    // Finding Values from array element (de-referencing values from array elements)
    cout << "Values --------------- " << endl;
    cout << "Value at index 0: " << arr[0] << endl;
    cout << "Value at index 0 using pointer: " << *arr << endl;
    cout << "Incrementing value of index 0: " << *arr + 1 << endl;

    cout << "Value of index 1: " << arr[1] << endl;
    cout << "Value at index 1 using pointer: " << *(arr + 1) << endl;

    // Another way to access - i[arr] = *(arr + i)
    int i = 5;
    cout << "Accessing 5th index of arr: " << i[arr] << endl << endl;

    // Size of array and pointer
    cout << "--------------------" << endl;
    int arr2[10] = {0};
    cout << "Size of array: " << sizeof(arr) << endl; // 40 bytes

    int *ptr = &arr2[0];
    cout << "Size of pointer: " << sizeof(ptr) << endl; // 8 bytes as it only store address of memory location
    cout << "Size of *ptr: " << sizeof(*ptr) << endl; // it's an int value therefore 4

    // Iterating array with pointer
    ptr = arr; // arr contains address so you don't need to write it as &arr[0]
    cout << "Traversing array with pointer: ";
    for(int i = 0; i < 10; ) {
        cout << *ptr << " ";

        if(i == 9) // This condition is important because we don't want our pointer to point next location which isn't location of our array element.
            break;

        ptr = arr + (++i);
    }
    cout << "\nPointer position: at value " << *ptr << endl;
    cout << endl;

    cout << "------------------------\n"; 
    int arr3[10] = {0};
    int *ptr2 = arr3;
    cout << "Address of arr3's index 0 stored in ptr2: " << ptr2 << endl;
    cout << "Value inside the address which is stored in ptr2: " << *ptr2 << endl;
    cout << "Address of ptr2: " << &ptr2 << endl;

    // ERROR:
    // arr3 = arr3 + 1; // We're trying to change address of arr3[0] to arr3[1]

    // But below code is possible,
    ptr2 = ptr2 + 1; // Means in ptr2 we're storing address of index 1 of arr3


    // Char arrays
    
    
    return 0;
}