#include <bits/stdc++.h>
using namespace std;

bool f(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (i == 0)
        return arr[0] == k;
    if (dp[i][k] != -1)
        return dp[i][k];
    bool notTake = f(i - 1, k, arr, dp);
    bool take = false;
    if (arr[i] <= k)
        take = f(i - 1, k - arr[i], arr, dp);
    return dp[i][k] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), cur(k + 1, false);
    prev[0] = cur[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            cur[j] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}