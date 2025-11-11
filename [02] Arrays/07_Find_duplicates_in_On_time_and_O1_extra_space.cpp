#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// To keep space complexity in O(1) then refer GFG.
// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/


// Optimal Approach using hash table
// Time & Space Complexity: O(n)
int findDuplicates_unoMap(int *arr, int n, int *ans) {
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;
    
    int k = 0; 
    for(auto it: freq) {
        if(it.second > 1)
            ans[k++] = it.first;
    }

    return k;
}

// Time Complexity: O(n log (n))
int findDuplicates(int *arr, int n, int *ans) {
    sort(arr, arr + n);

    int k = 0;
    for(int i = 0; i < n - 1; i++) {
        if(k != 0 && arr[i] == ans[k - 1])
            continue;
        
        if(arr[i] == arr[i + 1]) {
            ans[k++] = arr[i];
            // i++;
        }
    }

    return k;
}

int main() {
    int arr[10] = {1, 2, 3, 6, 3, 3, 3, 1}, ans[10];
    int size = 8;

    int totalDuplicates = findDuplicates(arr, size, ans);

    if(totalDuplicates == 0) {
        cout << "No duplicate elements found :(" << endl;
        return 0;
    }

    cout << "Duplicate elements: ";
    for(int i = 0; i < totalDuplicates; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}