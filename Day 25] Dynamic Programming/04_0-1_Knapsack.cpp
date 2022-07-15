#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
int f(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;
    if (ind == 0)
        return (wt[ind] <= w) ? val[0] : 0;
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notTake = f(ind - 1, w, val, wt, dp);
    int take = 0;
    if (wt[ind] <= w)
        take = val[ind] + f(ind - 1, w - wt[ind], val, wt, dp);
    return dp[ind][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, values, weights, dp);
}