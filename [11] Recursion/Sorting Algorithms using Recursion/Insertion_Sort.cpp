#include <iostream>
using namespace std;

// Recursive
// Time: O(n^n)     Space: O(n)
void insertionSort_rec(int *arr, int size) {
    // base case 
    if(size == 0 || size == 1)
        return ;

    insertionSort_rec(arr, size - 1);

    // processing: solve 1 case only rest will handle by recursion
    int temp = arr[size - 1];
    int i = size - 2;
    while(i >= 0) {
        if(arr[i] > temp)
            arr[i + 1] = arr[i];
        else 
            break;
        i--;
    }
    arr[i + 1] = temp;
}

// Iterative
// Time: O(n^n)     Space: O(1)
void insertionSort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0) {
            if(temp < arr[j])
                arr[j + 1] = arr[j];
            else 
                break;
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {

    int arr[7] = {2, 1, 3, 0, 5, 8, 7};
    int size = 7;

    // insertionSort(arr, size);
    insertionSort_rec(arr, size);
    cout << "\nInsertion Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}