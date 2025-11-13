#include <iostream>
using namespace std;

// Example for Selection Sort
// Array: [5, 3, 4, 1, 2]
// Step by step:
//
// i=0:
//   Find smallest in [5,3,4,1,2] → 1
//   Swap with arr[0] (5)
//   Result: [1, 3, 4, 5, 2]
//
// i=1:
//   Find smallest in [3,4,5,2] → 2
//   Swap with arr[1] (3)
//   Result: [1, 2, 4, 5, 3]
//
// i=2:
//   Find smallest in [4,5,3] → 3
//   Swap with arr[2] (4)
//   Result: [1, 2, 3, 5, 4]
//
// i=3:
//   Find smallest in [5,4] → 4
//   Swap with arr[3] (5)
//   Result: [1, 2, 3, 4, 5]
//
// Final Sorted Array: [1, 2, 3, 4, 5]


// Time Complexity: O(n^2)
// Space Complexity: O(1)

int selectionSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[10], size;

    cout << "Enter a size of an array: ";
    cin >> size;

    cout << "Enter " << size << " elements of an array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    selectionSort(arr, size);
    cout << "\nSelection Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}