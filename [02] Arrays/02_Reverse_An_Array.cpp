#include <iostream>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
void reverseArray(int *arr, int size) {
    int st = 0, en = size - 1;

    while(st != en) {
        int temp = arr[st];
        arr[st] = arr[en];
        arr[en] = temp;
        st++, en--;
    }
}

void printArr(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {
    int arr[10];
    int size;

    cout << "Enter size of array (less than 100): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    reverseArray(arr, size);
    printArr(arr, size);

    return 0;
}