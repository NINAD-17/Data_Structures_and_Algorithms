#include <iostream>
using namespace std;

// Time: O(n);  Space: O(n)

bool isSorted(int *arr, int lastIndex) {
    // Base Case
    if(lastIndex == 0 || lastIndex == 1)
        return true;
    
    if(arr[lastIndex] < arr[lastIndex - 1])
        return false;
    
    // Recursive Relation
    return isSorted(arr, lastIndex - 1); // Look at readme.md file to know why we use return keyword here.
}

bool isSorted_2(int *arr, int size) {
    // Base Case
    if(size == 0 || size == 1)
        return true;
    
    if(arr[0] > arr[1])
        return false;
    
    // Recursive Relation
    return isSorted(arr + 1, size - 1); // Look at readme.md file to know why we use return keyword here.
}

int main() {
    int arr[10];
    int n;

    cout << "Enter lastIndex of array: "; cin >> n;
    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(isSorted(arr, n - 1))
        cout << "Given array is sorted." << endl;
    else    
        cout << "Given array is not sorted." << endl;

    return 0;
}