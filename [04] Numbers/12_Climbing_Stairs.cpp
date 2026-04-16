#include <iostream>
#include <vector>
using namespace std;

// Problem: You are climbing a staircase with n steps.
//          - Each time, you can climb either 1 step or 2 steps.
//          - The question: How many distinct ways can you reach the top?
// Example: If n = 3 (3 stairs) -> 
//                  - 1 + 1 + 1
//                  - 1 + 2
//                  - 2 + 1
//          So total 3 ways.


// Fibonacci Logic (optimized - just count no printing of pattern)
// Time: O(n) and Space: O(1)
int climbStairsFib(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    int prev1 = 1; // f(1)
    int prev2 = 2; // f(2)
    int curr;

    for(int i = 3; i <= n; i++) {
        curr = prev1 + prev2; // f(i) = f(i - 1) + f(i - 2)
        prev1 = prev2;
        prev2 = curr;
    }

    return curr;
}


// Combination Code approach (I don't understand it)
// Time: O(n^2)
int combination(int n, int k) {
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - (k - i);
        result /= i;
    }
    return result;
}

int climbStairs(int n) {
    int result = 0;
    for (int i = 0; i <= n / 2; i++) {
        result += combination(n - i, i);
    }
    return result;
}


// Brute Force Method: (generate all sequences)
// Time: O(2^n) and Space: O(n)
void climb(int n, int current, vector<int> &path) {
    // base case
    if(current == n) {
        for(int i = 0; i < path.size(); i++) {
            if(i) cout << " + "; // skips for index 0 - avoiding pattern like (+ 1 + 1)
            cout << path[i];
        }
        cout << endl;
        return ;
    }

    if(current > n) {
        return ; // invalid path
    }

    // try 1 step
    path.push_back(1);
    climb(n, current + 1, path);
    path.pop_back();

    // try 2 step
    path.push_back(2);
    climb(n, current + 2, path);
    path.pop_back();
}

int main() {
    // Brute Force
    int numOfStairs_brute = 4;
    vector<int> path;
    climb(numOfStairs_brute, 0, path);
    cout << endl;
    // -----


    // Fibonacci (Optimized)
    int n = 4;
    cout << "Total ways: " << climbStairsFib(n) << endl;
    // ---

    // int numOfStairs;

    // cout << "Enter total number of stairs: ";
    // cin >> numOfStairs;

    // cout << "Total ways to climb to the top is " << climbStairs(numOfStairs) << endl;
    return 0;
}