#include <iostream>
using namespace std;

// Time complexity (best case): O(n log n) 
// Space complexity (best case): O(log n)
// Read explaination of time and space complexity from README.md

int partition(int *arr, int st, int en) {

    // Decide pivot element
    int pivot = arr[st];

    // Count all the numbers which are less than pivot
    int count = 0;
    for(int i = st; i <= en; i++) {
        if(arr[i] < pivot)  
            count++;
    }

    // Put pivot at right position
    int pivotIndex = st + count;
    swap(arr[pivotIndex], arr[st]);

    // Satisfy condition < and > than pivot in left and right parts ( ... < pivot < ...)
    int i = st, j = en;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] < pivot) 
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quick_sort(int *arr, int st, int en) {
    // Base Case
    if(st >= en)
        return;

    // Partition
    int pivotIndex = partition(arr, st, en);

    // Sort left part
    quick_sort(arr, st, pivotIndex - 1);

    // Sort right part
    quick_sort(arr, pivotIndex + 1, en);
}

int main() {
    int arr[6] = { 3, 5, 1, 8, 2, 4 };
    int size = 6;

    quick_sort(arr, 0, size - 1);

    // Output
    for(int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}