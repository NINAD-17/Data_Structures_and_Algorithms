#include <iostream>
using namespace std;

// Example for Insertion Sort
// Array: [12, 11, 13, 5, 6]
// Step by step:
//
// i=1 (element = 11):
//   Compare with 12 → shift 12 right
//   Place 11 at index 0
//   Result: [11, 12, 13, 5, 6]
//
// i=2 (element = 13):
//   Compare with 12 → 13 > 12 → no shift
//   Result: [11, 12, 13, 5, 6]
//
// i=3 (element = 5):
//   Compare with 13 → shift 13 right
//   Compare with 12 → shift 12 right
//   Compare with 11 → shift 11 right
//   Place 5 at index 0
//   Result: [5, 11, 12, 13, 6]
//
// i=4 (element = 6):
//   Compare with 13 → shift 13 right
//   Compare with 12 → shift 12 right
//   Compare with 11 → shift 11 right
//   Place 6 at index 1
//   Result: [5, 6, 11, 12, 13]
//
// Final Sorted Array: [5, 6, 11, 12, 13]

// Time Complexity: O(n^2)
int insertionSort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        for(; j >= 0; j--) {
            if(arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        /*
        while(j >- 0) {
            if(arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        */
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[10], size;

    cout << "Enter a size of an array: ";
    cin >> size;

    cout << "Enter " << size << " elements of an array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    insertionSort(arr, size);
    cout << "\nInsertion Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}