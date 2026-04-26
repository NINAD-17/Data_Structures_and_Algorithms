#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int usingMemoization(long long nStairs, int i, vector<int> dp) {
    if(i == nStairs)
        return 1; // if your current stair is destination stair then number of ways to reach it is 1

    if(i > nStairs)
        return 0; // invalid case

    if(dp[i] != -1)
        return dp[i];

    dp[i] = usingMemoization(nStairs, i + 1, dp) + usingMemoization(nStairs, i + 2, dp);
    return dp[i];
}

int usingRecursion(long long nStairs, int i) {
    if(i == nStairs)
        return 1; // if your current stair is destination stair then number of ways to reach it is 1

    if(i > nStairs)
        return 0; // invalid case

    return (usingRecursion(nStairs, i + 1) + usingRecursion(nStairs, i + 2)) % MOD;
    // Ex - f(0) = f(n + 1) + f(n + 2); it means from 0th stairs to reach nth, number of ways will be f(1) from 1st stairs num of ways + f(2) from 2nd stairs num of ways 
}

int usingRecursion_fromNthStair(long long nStairs) {
    // Base cases
    if(nStairs == 0) return 1; // one way: do nothing
    if(nStairs == 1) return 1; // one way: single step

    // Recursive relation: ways to reach n = ways to reach (n-1) + ways to reach (n-2)
    return (usingRecursion_fromNthStair(nStairs - 1) + usingRecursion_fromNthStair(nStairs - 2)) % MOD;
}

int countDistinctWaysToClimbStairs(long long nStairs) {
    int ans = usingRecursion(nStairs, 0);
    cout << "Number of ways to climb stairs using 1 and 2 steps is: " << ans << endl;

    ans = usingRecursion_fromNthStair(nStairs);
    cout << "Number of ways to climb stairs using 1 and 2 steps is: " << ans << endl;

    vector<int> dp(nStairs + 1, -1);
    ans = usingMemoization(nStairs, 0, dp);
    cout << "Using Memoization: " << ans << endl;
}

int main() {
    int nStairs = 4;

    countDistinctWaysToClimbStairs(nStairs);
    return 0;
}