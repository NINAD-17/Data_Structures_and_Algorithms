#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

// Explaination of 
// 1. Why we used unordered map
// 2. findDuplicates2() --> XOR operation
// is available in readme.md

// Using Unordered Map:
// Time Complexity: O(n)
// Space Complexity: O(n)
int findDuplicate_unMap(int *arr, int size) {
    unordered_map<int, int> freq;
    for(int i = 0; i < size; i++) {
        cout << freq.count(arr[i]) << endl;
        if(freq.count(arr[i]) > 0) // freq.count check existence (if exist it'll return 1 else 0), no insertion like freq[arr[i]]
            return arr[i];
        freq[arr[i]]++;
    }
    return INT_MIN;
}

// Optimized approach: 
// Note: But these approach only applicable when there is only one number is duplicate.
//      - The array has length n.
//      - Every value is in the range [1, n − 1].
//      - Exactly one number appears twice; all others appear once.
//      - No zeros, no missing values beyond the single duplicate.

// Time Complexity: O(n)
// Space Complexity: O(1)
// Remember that this algorithm only will work if there are [1, n - 1] elements are present. Ex [1, 5 - 1] then 1, 2, 3, 4 must be present.
int findDuplicate2(int *arr, int n) {
    int ans = 0; 
    
    for(int i = 0; i < n; i++) 
        ans ^= arr[i];
    
    for(int j = 1; j < n; j++)
        ans ^= j;
    
    return ans;
}

// Brute force Approach: 
// time complexity: O(n^2)
// Space Complexity: O(1) 
int findDuplicate(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) 
                return arr[i];
        }
    }
    return INT_MIN;
}

void takeInputFromUser(int *arr, int size) {
    for(int i = 0; i < size; i++) 
        cin >> arr[i];
}

int main() {

    int arr[10];
    int size;

    cout << "Enter size of array (less than 10): ";
    cin >> size;

    cout << "Enter " << size << " array elements: ";
    takeInputFromUser(arr, size);

    int duplicateElement = findDuplicate_unMap(arr, size);
    if(duplicateElement == 0 /* INT_MIN for findDuplicate() instead 0 */)
        cout << "No duplicate element is found" << endl;
    else    
        cout << "Duplicate element is " << duplicateElement << endl;
    return 0;
}