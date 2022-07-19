#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, string &target, set<string> &words)
{
    if (i == n)
        return 1;
    int ans = 0;
    string temp = "";
    for (int j = i; j < n; j++)
    {
        temp += target[j];
        if (words.find(temp) != words.end())
        {
            ans |= f(j + 1, n, target, words);
        }
    }
    return ans;
}

bool wordBreak(vector<string> &arr, int n, string &target)
{
    set<string> words;
    for (string s : arr)
    {
        words.insert(s);
    }
    int size = target.size();
    vector<bool> dp(size + 1, 0);
    dp[size] = true;

    for (int i = size - 1; i >= 0; i--)
    {
        int ans = false;
        string temp = "";
        for (int j = i; j < size; j++)
        {
            temp += target[j];
            if (words.find(temp) != words.end())
            {
                ans |= dp[j + 1];
            }
        }
        dp[i] = ans;
    }

    return dp[0];
}