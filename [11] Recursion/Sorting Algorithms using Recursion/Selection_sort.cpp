#include <iostream>
using namespace std;

// Recursive
// Time: O(n^n)     Space: O(n)
void selectionSortUsingRecursion(int *arr, int size) {
    // base case
    if(size == 0 || size == 1)
        return ;
    
    // processing: solve 1 case only rest will handle by recursion
    int minElement = 0;
    for(int i = 1; i < size; i++) {
        if(arr[i] < arr[minElement])
            minElement = i;
    }
    swap(arr[minElement], arr[0]);

    selectionSortUsingRecursion(arr + 1, size - 1); // 1st element is sorted therefore arr + 1
}

// Iterative 
// Time: O(n^n)     Space: O(1)
void selectionSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j])
                minIndex = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {

    int arr[7] = {2, 1, 3, 0, 5, 8, 7};
    int size = 7;

    // selectionSort(arr, size);
    selectionSortUsingRecursion(arr, size);
    cout << "\nSelection Sort ------------\nSorted array: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}