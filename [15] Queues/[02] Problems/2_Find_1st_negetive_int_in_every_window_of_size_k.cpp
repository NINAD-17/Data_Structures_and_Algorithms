#include <iostream>
#include <queue>
#include <vector>
#include "../lib/print.cpp"
using namespace std;

// FIND FIRST NEGETIVE INTEGER IN EVERY WINDOW OF SIZE K

// Example: [-8, 2, 3, -6, 10] and window size = 2
//      window [-8, 2]  = -8
//      window [2, 3]   = 0 (no negetive integer)
//      window [3, -6]  = -6
//      window [-6, 10] = -6
//      Answer: [-8, 0, -6, -6]


// --- Sliding Window Approach ---
// In each window, one number gets added and one gets removed
//                       _____________
// pop_front (remove) <- |  |  |  |  | <- push_back (add)
//                       ‾‾‾‾‾‾‾‾‾‾‾‾‾
// For this we're using deque

// time complexity: O(n)
// space complexity: O(n)
vector<long long int> firstNegegiveIntegerInEachWindow(long long int *arr, long long int n, long long int k) {
    // create a deque to store negetive number's indexes from that window of size k
    deque<int> dq;

    // create a vector (ans) to store all the first negetive elements from each window
    vector<long long int> ans;

    // for 1st window of size k that is 0 to k
    for(int i = 0; i < k; i++) {
        // push all the negetive number's indexes in dq (if present)
        if(arr[i] < 0) 
            dq.push_back(i);
    }

    // store ans of 1st k sized window
    if(!dq.empty()) // means -ve element is present in the block
        ans.push_back(arr[dq.front()]);
    else 
        ans.push_back(0); // no negetive element present in the block so push 0

    // process the remaining elements
    for(int i = k; i < n; i++) {
        // now remove any negetive element's index present in deque which is not in range.
        // means remove front element from dq if it's not in range because we've added new element.
        if(!dq.empty() && i - dq.front() >= k)
            dq.pop_front(); // remove

        // addition: if new element is -ve then add index of it in deque
        if(arr[i] < 0) 
            dq.push_back(i);

        // store ans of curr window
        if(!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

// Optimal
// time: O(n) // p advances monotonically; each element is checked at most once.
// space: O(1)
vector<long long> firstNegativeInWindow(long long *arr, int n, int k) {
    vector<long long> ans;
    int p = 0; // pointer to next negative candidate

    for (int i = 0; i <= n - k; i++) {
        int end = i + k - 1;

        // advance p to be within [i, end] and pointing to a negative
        if (p < i) p = i;
        while (p <= end && arr[p] >= 0) p++;

        if (p <= end) ans.push_back(arr[p]);
        else ans.push_back(0);
    }

    return ans;
}


// Brute Force
// Time complexity: O(n^2)
// Space complexity: O(1)
vector<long long int> firstNegetive_bruteForce(long long int *arr, int n, int k) {
    vector<long long int> ans;

    for(int i = 0; i <= (n - k); i++) {
        for(int j = i; j < (i + k); j++) {
            if(arr[j] < 0) {
                ans.push_back(arr[j]);
                break;
            }
        }
    }

    return ans;
}

int main() {

    long long int arr[5] = {-8, 2, 3, -6, 10};
    int k = 2; // size of each window

    vector<long long int> ans = firstNegegiveIntegerInEachWindow(arr, 5, k);


    // printing ans
    cout << "first negetive element in each window: [";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "]" << endl;

    return 0;
}