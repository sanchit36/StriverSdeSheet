#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
long f(int ind, int val, int *d, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        if (val % d[0] == 0)
            return 1;
        return 0;
    }
    if (dp[ind][val] != -1)
        return dp[ind][val];
    long notTake = f(ind - 1, val, d, dp);
    long take = 0;
    if (d[ind] <= val)
        take = f(ind, val - d[ind], d, dp);
    return dp[ind][val] = notTake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}