#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Using hash tables is a more optimized way to solve this problem after you learn the concept of hash tables
// Time: O(n^2)
// Space: O(n) for hashmap
void tripletSum_unordered_map(int *arr, int n, int reqSum, int *pairsArr) {
    bool found = false;
    int k = 0;

    for(int i = 0; i < n; i++) {
        unordered_map<int, bool> seen;
        int currSum = reqSum - arr[i];

        for(int j = i + 1; j < n; j++) {
            int target = currSum - arr[j];

            if(seen[target]) {
                // cout << "Triplet found: " << arr[i] << ", " << arr[j] << ", " << target << endl;
                pairsArr[k++] = arr[i];
                pairsArr[k++] = arr[j];
                pairsArr[k++] = target;

                found = true;
            }

            seen[arr[j]] = true;
        }
    }

    if(!found) {
        cout << "No triplet found :(" << endl;
    }
}


// We can optimize brute force approach by using two pointers approach
// Time Complexity: O(n^2 + n log(n))
// // Space (auxillary): O(log n)  // Sorts the array in-place (sort(arr, arr+n)), which in C++ STL uses O(log n) stack space for recursion.
void tripletSum_twoPt(int *arr, int n, int reqSum, int *pairsArr) {
    int k = 0;

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) { // you can also stop this loop at condition i < n - 3 as loop needs triplets only.
        int left = i + 1;
        int right = n - 1;
        while(left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == reqSum) {
                pairsArr[k] = arr[i];
                pairsArr[k + 1] = arr[left];
                pairsArr[k + 2] = arr[right];
                k += 3;
                left++;
                right--;
            } else if(sum < reqSum) {
                left++;
            } else {
                right--;
            }
        }
    }
} 

// Brute Force Approach
// Time Complexity: O(n^3)
// Space (auxillary): O(1)
void tripletSum(int *arr, int n, int sum, int *pairsArr) {
    int k = 0;

    // If you want to sort this array by 1st element in that pair
    sort(arr, arr + n); // If you use sort then time complexity: O(n^3 + n log(n))

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int l = j + 1; l < n; l++) {
                if(arr[i] + arr[j] + arr[l] == sum) {
                    pairsArr[k] = arr[i];
                    pairsArr[k + 1] = arr[j];
                    pairsArr[k + 2] = arr[l];
                    k += 3;
                }
            }
        }
    }
}

int main() {
    int arr[10] = {0, 3, 2, 4, 1}, pairsArr[10];
    int n = 5, reqSum = 5;

    for(int i = 0; i < 10; i++) 
        pairsArr[i] = INT_MIN;

    cout << "Using Brute Force: " << endl;
    tripletSum(arr, n, reqSum, pairsArr);
    if(pairsArr[0] == INT_MIN)
        cout << "No pair found :(" << endl;
    else {
        int k = 1;
        for(int i = 0; i < 10; i+=3) {
            if(pairsArr[i] == INT_MIN)
                break;
            cout << "Pair-" << k++ << " -> " << pairsArr[i] << ", " << pairsArr[i + 1] << ", " << pairsArr[i + 2] << endl;
        }
    }
    cout << endl;
    
    cout << "Using two pointer: " << endl;
    tripletSum_twoPt(arr, n, reqSum, pairsArr);
    if(pairsArr[0] == INT_MIN)
        cout << "No pair found :(" << endl;
    else {
        int k = 1;
        for(int i = 0; i < 10; i+=3) {
            if(pairsArr[i] == INT_MIN)
                break;
            cout << "Pair-" << k++ << " -> " << pairsArr[i] << ", " << pairsArr[i + 1] << ", " << pairsArr[i + 2] << endl;
        }
    }
    cout << endl;

    cout << "Using hashmap: " << endl;
    tripletSum_unordered_map(arr, n, reqSum, pairsArr);
    if(pairsArr[0] == INT_MIN)
        cout << "No pair found :(" << endl;
    else {
        int k = 1;
        for(int i = 0; i < 10; i+=3) {
            if(pairsArr[i] == INT_MIN)
                break;
            cout << "Pair-" << k++ << " -> " << pairsArr[i] << ", " << pairsArr[i + 1] << ", " << pairsArr[i + 2] << endl;
        }
    }
    cout << endl;

    cout << endl;
    return 0;
}