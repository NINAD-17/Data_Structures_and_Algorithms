#include <iostream>
using namespace std;

// Example for Bubble Sort
// Array: [12, 45, 23, 51, 19, 8]
// Step by step:
//
// Round 1:
//   Compare pairs → largest element (51) bubbles to the end
//   Result: [12, 23, 45, 19, 8 | 51]
//
// Round 2:
//   Compare pairs → next largest (45) bubbles before 51
//   Result: [12, 23, 19, 8 | 45, 51]
//
// Round 3:
//   Compare pairs → next largest (23) bubbles before 45
//   Result: [12, 19, 8 | 23, 45, 51]
//
// Round 4:
//   Compare pairs → next largest (19) bubbles before 23
//   Result: [12, 8 | 19, 23, 45, 51]
//
// Round 5:
//   Compare pairs → next largest (12) bubbles before 19
//   Result: [8 | 12, 19, 23, 45, 51]
//
// Final Sorted Array: [8, 12, 19, 23, 45, 51]


// Time Complexity: O(n^2)
void swapElements(int *element1, int *element2) { // instead of * pointer and & address you can simply use references (&) only in param.
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

int bubbleSort(int *arr, int size) {
    for(int i = 1; i < size; i++) { // Rounds (n - 1)
        bool swapped = false;
        for(int j = 0; j < size - i; j++) { // Sorting j & j + 1
            if(arr[j] > arr[j + 1]) {
                swapElements(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

int main() {
    int arr[10], size;

    cout << "Enter a size of an array: ";
    cin >> size;

    cout << "Enter " << size << " elements of an array: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    bubbleSort(arr, size);
    cout << "\nBubble Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}