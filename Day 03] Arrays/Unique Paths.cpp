#include <bits/stdc++.h>
int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = solve(i, j + 1, m, n, dp) + solve(i + 1, j, m, n, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp);
}

// Optimized Solution
// Grid Unique Paths using Combination Mathematics

// Intuition: If we observe examples there is a similarity in paths from start to end.
// Each time we are taking an exactly m+n-2 number of steps to reach the end.
// Since we need an m+n-2 number of steps to reach the end among those steps if we
// choose n-1 rightward direction or m-1 downward direction and calculate the
// combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

int uniquePaths(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}