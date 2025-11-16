#include <iostream>
using namespace std;

void print(int *ptr) {
    cout << "Address stored in ptr pointer: " << ptr << endl;
    cout << "Value inside the address which is stored in ptr pointer: " << *ptr << endl;
}

void update(int *ptr) {
    ptr = ptr + 1;
}

void update2(int *ptr) {
    *ptr = *ptr + 1;
}

int get_sum (int arr[], int n) {

    cout << endl << "size: " << sizeof(arr) << endl; // 8 because arr[] passes as same as *arr[];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int value = 5;
    int *ptr = &value;

    print(ptr);

    cout << "\nChange in only function: ------------ \n";
    cout << "Before update: " << *ptr << endl;
    update(ptr);
    cout << "After update: " << *ptr << endl;

    cout << "\nValue changes after calling function: ---------- \n";
    cout << "Before update value: " << *ptr << endl;
    update2(ptr);
    cout << "After update value: " << *ptr << endl;

    int arr[5] = {1,2,3,4,5};
    cout << "sum: " << get_sum (arr, 5);
    cout << "sum: " << get_sum(arr+3, 2); //address arr[4] to end; //9 i.e (4 + 5)

    return 0;
}