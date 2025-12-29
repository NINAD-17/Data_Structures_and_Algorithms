#include <iostream>
using namespace std;

// (IMP) learn: Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?
// link of artical: https://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/

// MERGE SORT
// known for its efficiency and stability.

// Time Complexity: O(n log n)
// Space Complexity: O(n)
void merge_2_sorted_arrays(int *arr, int st, int en) {
    int mid = st + (en - st) / 2;

    int len1 = mid - st + 1;
    int len2 = en - mid;

    // Create two arrays for left and right parts of array
    int *leftArr = new int[len1];
    int *rightArr = new int[len2];

    // Copy values in both arrays
    int mainArrayIndex = st;
    for(int i = 0; i < len1; i++)
        leftArr[i] = arr[mainArrayIndex++];

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++)
        rightArr[i] = arr[mainArrayIndex++];

    // Merge arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = st;

    // Put sorted values in main array
    while(index1 < len1 && index2 < len2) {
        if(leftArr[index1] < rightArr[index2])
            arr[mainArrayIndex++] = leftArr[index1++];
        else 
            arr[mainArrayIndex++] = rightArr[index2++];
    }

    // Remaining elements of leftArr
    while(index1 < len1) {
        arr[mainArrayIndex++] = leftArr[index1++];
    }

    // Remaining elements of rightArr
    while(index2 < len2) {
        arr[mainArrayIndex++] = rightArr[index2++];
    }

    // deallocate memory
    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int *arr, int st, int en) {
    // Base Case
    if(st >= en)
        return ;

    int mid = st + (en - st) / 2;

    // Sort left Part
    merge_sort(arr, st, mid);

    // Sort right Part
    merge_sort(arr, mid + 1, en);

    // Merge two sorted arrays
    return merge_2_sorted_arrays(arr, st, en);
}

int main() {

    int arr[10] = { 38, 27, 43, 3, 9, 82, 10 };
    int size = 7;

    merge_sort(arr, 0, size - 1);

    // Output
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}