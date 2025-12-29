#include <iostream>
using namespace std;

// Recursive
// Time: O(n^n)     Space: O(n)
void bubbleSort_rec(int *arr, int size) {
    // base case
    if(size == 0 || size == 1)
        return ;

    // processing: solve 1 case only rest will handle by recursion
    bool isSwapped = false;
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            isSwapped = true;
        }
    }

    if(!isSwapped) // optimization
        return;

    bubbleSort_rec(arr, size - 1); // as the last element is sorted, we need to check only for size - 1
}

// Iterative
// Time: O(n^n)     Space: O(1)
void bubbleSort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        bool isSwapped = false;
        for(int j = 0; j < size - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = true;
            }
        }
        if(!isSwapped) // optimization: elements aren't swapped in any round then it will break the loop so that it will not travel unncessarily
            break;
    }
}

int main() {

    int arr[7] = {1, 0, 4, 3, 2, 8, 7};
    int size = 7;

    // bubbleSort(arr, size);
    bubbleSort_rec(arr, size);
    cout << "\nBubble Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}