#include <iostream>
using namespace std;

int main () {

    int arr[10] = {2, 5, 6, 7};

    /*
    cout << "1st loc addr: " << arr << endl;
    cout << arr[0] << endl;
    cout << "1sr loc addr: " << &arr[0] << endl;
    cout << *arr << endl;
    cout << *arr + 1 << endl;
    cout << (*arr) + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;
    cout << arr[2] << endl;
    int i = 3;
    cout << i[arr] << endl;
    */
    /*
    int temp[10];
    cout << sizeof (temp) << endl; // 4 * 10 = 40
    cout << sizeof (*temp) << endl;
    cout << sizeof (&temp) << endl;

    int *ptr =  &temp[0];
    cout << sizeof (ptr) << endl; // 8
    cout << sizeof (*ptr) << endl;
    cout << sizeof (&ptr) << endl;
    */
    /*
    int a[20] = {1,2,3,5};
    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;
    */

    /*
    int arr1[10];
    //ERROR:
    //arr = arr + 1;

    int *ptr = &arr1[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;
    */

    return 0;
}