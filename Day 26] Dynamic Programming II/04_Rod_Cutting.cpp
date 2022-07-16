#include <bits/stdc++.h>
using namespace std;

int f(int len, vector<int> &price, vector<int> &dp)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int maxi = 0;
    for (int i = 1; i <= len; i++)
    {
        maxi = max(maxi, price[i - 1] + f(len - i, price, dp));
    }
    return dp[len] = maxi;
}

int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int len = 1; len <= n; len++)
    {
        int maxi = 0;
        for (int i = 1; i <= len; i++)
        {
            maxi = max(maxi, price[i - 1] + dp[len - i]);
        }
        dp[len] = maxi;
    }
    return dp[n];
}
