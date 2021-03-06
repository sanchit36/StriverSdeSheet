#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int notTake = f(ind + 1, prev_ind, arr, n, dp);
    int take = 0;
    if (prev_ind == -1 || arr[prev_ind] < arr[ind])
        take = 1 + f(ind + 1, ind, arr, n, dp);
    return dp[ind][prev_ind + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    if (n == 1)
        return 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
}

// Tabulation
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int p_i = i - 1; p_i >= -1; p_i--)
        {
            int len = dp[i + 1][p_i + 1];
            if (p_i == -1 || nums[p_i] < nums[i])
                len = max(len, 1 + dp[i + 1][i + 1]);
            dp[i][p_i + 1] = len;
        }
    }
    return dp[0][0];
}

// Tabulation with backtracking the LIS
// TC: O(N^2) SC: O(N)
int longestIncreasingSubsequence(int arr[], int n)
{

    int maxi = 1;
    vector<int> dp(n, 1), hash(n);
    int lastIndex = 0;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    for (int num : lis)
        cout << num << " ";
    cout << endl;
    return maxi;
}

// LIS USING Binary Search
// TC: Nlog(N)
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp.back() < arr[i])
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int prev = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[prev] = arr[i];
        }
    }
    return len;
}
