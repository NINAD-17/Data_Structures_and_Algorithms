#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Using Binary Search: Time Complexity: O(n * log(n))
// Explaination of following code (lower and upper bound) is in README.md
void countFreq_binSrch(int *arr, int n) {
    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        int firstIndex = lower_bound(arr, arr + n, arr[i]) - arr;
        cout << "Lower bound: " << lower_bound(arr, arr + n, arr[i]) << "\tFirst index: " << firstIndex << endl;

        int lastIndex = upper_bound(arr, arr + n, arr[i]) - arr - 1; // gives last position of x (here element arr[i]) + 1 position means next position. So we'll need to substract 1 from it.
        cout << "Upper bound: " << upper_bound(arr, arr + n, arr[i]) << "\tLast index: " << lastIndex << endl;

        i = lastIndex;

        int freq = (lastIndex - firstIndex) + 1;
        cout << arr[i] << " ---> " << freq << endl << endl;
    }
}

// Using Unordered-map: Time & Space Complexity: O(n)
void countFreq_uoMap(int *arr, int n) {
    unordered_map<int, int> ans;

    for(int i = 0; i < n; i++)
        ans[arr[i]]++;
    
    // for(auto value: ans) 
    //     cout << value.first << " ---> " << value.second << endl;

    // To print it in sorted order
    for(int i = 0; i < n; i++) {
        if(ans[arr[i]] != INT_MIN) {
            cout << arr[i] << " ---> " << ans[arr[i]] << endl;
            ans[arr[i]] = INT_MIN;
        }
    }
}

// Using Array: Time Complexity: O(n^2)
int countFreq(int *arr, int n, int ans[10][2]) {
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == INT_MIN)
            continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = INT_MIN;
            }
        }
        ans[k][0] = arr[i];
        ans[k++][1] = count;
    }

    return k;
}

int main() {

    int arr[10] = {10, 20, 20, 10, 10, 20, 5, 20};
    int size = 8;
    int ans[10][2];

    cout << "Using Array - \n";
    // int sizeOfAns = countFreq(arr, size, ans);
    // for(int i = 0; i < sizeOfAns; i++) {
    //     cout << ans[i][0] << " --> " << ans[i][1] << endl;
    // }

    // cout << "Using Unordered map - \n";
    // countFreq_uoMap(arr, size); 

    cout << "Using Binary Search - \n";
    countFreq_binSrch(arr, size);

    return 0;
}