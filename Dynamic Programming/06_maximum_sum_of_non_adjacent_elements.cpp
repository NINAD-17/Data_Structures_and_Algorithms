#include <bits/stdc++.h>
using namespace std;

int usingOptimizedTabulation(vector<int> &nums, int n) {
    vector<int> dp(n, 0);
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i < n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

int usingTabulation(vector<int> &nums, int n) {
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i = 1; i < n; i++) {
        int incl = dp[i - 2] + nums[i]; 
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n];
}

int usingMemoization(vector<int> &nums, int n, vector<int> &dp) {
    // Base Case
    if(n < 0)
        return 0;

    if(n == 0)
        return nums[0];

    if(dp[n] != -1)
        return dp[n];

    int incl = usingMemoization(nums, n - 2, dp) + nums[n];
    int excl = usingMemoization(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int usingRecursion(vector<int> &nums, int n) {
    // Base Case
    if(n < 0)
        return 0;

    if(n == 0)
        return nums[0];

    int incl = usingRecursion(nums, n - 2) + nums[n];
    int excl = usingRecursion(nums, n - 1) + 0;

    return max(incl, excl);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    // Approach: Using Recursion
    int n = nums.size();
    int ans = usingRecursion(nums, n - 1); // Traversing from right to left
    cout << "Answer using recursion: " << ans << endl;

    // Approach: Recursion + Memoization (Top Down)
    vector<int> dp(n, -1);
    ans = usingMemoization(nums, n - 1, dp);
    cout << "Answer using memoization: " << ans << endl;

    // Approach: Tabulation
    ans = usingTabulation(nums, n - 1);
    cout << "Answer using tabulation: " << ans << endl;

    // Approach: Optimized Tabulation
    ans = usingOptimizedTabulation(nums, n - 1);
    cout << "Answer using optimized tabulation: " << ans << endl;
}

int main() {
    vector<int> nums = {9, 9, 8, 2};

    maximumNonAdjacentSum(nums);

    return 0;
}