#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s)
{
    if (i >= j)
        return true;
    if (s[i] != s[j])
        return false;
    return isPalindrome(i + 1, j - 1, s);
}

int f(int i, int n, string &s, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mini = 1e9;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            mini = min(mini, 1 + f(j + 1, n, s, dp));
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] == 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mini = 1e9;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                mini = min(mini, 1 + dp[j + 1]);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}
