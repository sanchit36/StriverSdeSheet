#include <bits/stdc++.h>
using namespace std;

// O(k*n*log(n))
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int mini = INT_MAX;
                int l = 1, h = j;
                while (l <= h)
                {
                    int mid = (l + (h - l) / 2);
                    int go_below = dp[i - 1][mid - 1]; // breaks at mid
                    int go_above = dp[i][j - mid];     // no breaks

                    int temp = 1 + max(go_above, go_below);
                    if (go_above > go_below)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        h = mid - 1;
                    }
                    mini = min(mini, temp);
                }
                dp[i][j] = mini;
            }
        }
    }
    return dp[k][n];
}
