#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007 // %(10 ^ 9 + 7) output could be very large so mod it

long long int usingTabulation(int n) {
    vector<long long int> dp();
}

long long int usingMemoization(int n, vector<long long int> &dp) {
    // base case
    if(n == 1) // only one element exists, so no derangement possible
        return 0;
    
    if(n == 2) // only 2 elements exists, so 1 derangement possible
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = ((n - 1) % MOD) * ((usingMemoization(n - 1, dp) % MOD) + (usingMemoization(n - 2, dp)) % MOD);

    return dp[n];
}

long long int usingRecursion(int n) {
    // base case
    if(n == 1) // only one element exists, so no derangement possible
        return 0;
    
    if(n == 2) // only 2 elements exists, so 1 derangement possible
        return 1;

    int ans = ((n - 1) % MOD) * ((usingRecursion(n - 1) % MOD) + (usingRecursion(n - 2)) % MOD);

    return ans;
}

long long int countDerangements(int n) {
    cout << "using recursion: " << usingRecursion(n) << endl;

    vector<long long int> dp(n + 1, -1);
    cout << "using memoization: " << usingMemoization(n, dp) << endl;

    cout << "using tabulation: " << usingTabulation(n) << endl;
}

int main() {
    int n = 4;

    countDerangements(n);
    return 0;
}