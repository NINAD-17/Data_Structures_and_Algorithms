#include <iostream>
using namespace std;

// Example cases
// 1.   1, 2, 3, 4, 5  [1 count at (5 -> 1)]
// 2.   3, 4, 5, 1, 2  [1 count at (5 -> 1)]
// 3.   3, 5, 7, 1, 6  here numbers aren't sorted & count of (arr[i - 1] > arr[i]) is greater than 1. So it's false [2 count at (7 -> 1) & (6 -> 3)]

bool isRotatedAndSorted(int *arr, int n) {
    int count = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i])
            count++;
    }

    if(arr[n - 1] > arr[0])
        count++;

    return count == 1;
}

int main() {
    int arr[10] = {3,4,5,1,2};
    int size = 5;

    if(isRotatedAndSorted(arr, size))
        cout << "Given array is rotated and sorted." << endl;
    else
        cout << "Given array is not rotated and sorted." << endl;
    
    return 0;
}