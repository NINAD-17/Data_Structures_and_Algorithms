#include <iostream>
#include <climits>
using namespace std;

// binary search method relies on the guarantee that:
//  - The array strictly increases up to one peak.
//  - Then strictly decreases after that peak.
// Time complexity: O(log n)
int peakIndexInMountainArray(int *arr, int n) {
    int st = 0, en = n - 1;

    while(st < en) {
        int mid = st + (en - st) / 2;
        if(arr[mid] < arr[mid + 1]) 
            st = mid + 1;
        else    
            en = mid;
    }

    return st;
}

// Brute force approach - if array is not mountain array then it'll return INT_MIN
int peakIndexLinear(const int *arr, int n) {
    int peak = INT_MIN;
    for (int i = 1; i <= n - 2; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1] && arr[i] > peak) {
            peak = arr[i];
        }
    }
    
    return peak;
}

// If it's an mountain array (means only one mountain - increasing < peak > decreasing) then we can directly output greatest number from array as peak
int peakFromMountain(int *arr, int n) {
    int peak = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] > peak)
            peak = arr[i];
    }

    return peak;
}

int main() {
    int arr[10], size; // Example: 1, 3, 5, 7, 6, 4, 2

    cout << "Enter size of array(less than 10): ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    int peakInt = peakIndexInMountainArray(arr, size);
    cout << "Peak index in Mountain Array is " << peakInt << endl;

    return 0;
}