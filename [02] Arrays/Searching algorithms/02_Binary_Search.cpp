#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(log n)
int binarySearch(int *arr, int n, int key) {
    int st = 0, en = n - 1;

    while(st <= en) {
        int mid = st + (en - st)/2; // Read logic of this formula from readme.md
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            st = mid + 1;
        else    
            en = mid - 1;
    }

    return INT_MIN;
}

int main() {
    int arr[10], size, key;

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter an element to search: ";
    cin >> key;

    int isFound = binarySearch(arr, size, key);
    if(isFound == INT_MIN) 
        cout << "Element is not found :(" << endl;
    else    
        cout << "Element is found at array index: " << isFound << endl;
    
    return 0;
}