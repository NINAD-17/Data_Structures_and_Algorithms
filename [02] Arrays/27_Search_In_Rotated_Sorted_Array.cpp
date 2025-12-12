#include <iostream>
#include <climits>
using namespace std;

// Here pivot is the smallest number in an array
int findPivotElement(int *arr, int n) {
    int st = 0, en = n - 1;

    while(st < en) {
        int mid = st + (en - st)/2;
        if(arr[mid] >= arr[0])
            st = mid + 1;
        else 
            en = mid;
    }

    return st;
}

int searchInRotatedSortedArr(int *arr, int st, int en, int key) {
    while(st <= en) {
        int mid = st + (en - st)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            st = mid + 1;
        else    
            en = mid - 1;
    }

    return INT_MIN;
}

int isFound(int *arr, int n, int key) {
    int pivot = findPivotElement(arr, n);
    int ans;

    if(key >= arr[0])
        ans = searchInRotatedSortedArr(arr, 0, pivot - 1, key);
    else
        ans = searchInRotatedSortedArr(arr, pivot, n - 1, key);
    
    return ans;
}

int main() {
    int arr[10], size, key;

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " number of elements: ";
    for(int i = 0; i < size; i++) 
        cin >> arr[i];

    cout << "Enter a number to search: ";
    cin >> key;

    int index = isFound(arr, size, key);
    if (index != INT_MIN)
        cout << "Element found at array index: " << index << endl;
    else
        cout << "Element not found :(" << endl;

    return 0;
}