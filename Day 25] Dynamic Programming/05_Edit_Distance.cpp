#include <bits/stdc++.h>
using namespace std;

int editDistance(string w1, string w2)
{
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // word2 finish, so delete all in word1 or insert all in word2.
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    // word1 finish, so delete all in word2 or insert all in word1.
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w1[i - 1] == w2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}