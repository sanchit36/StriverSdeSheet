#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    int maxi = 0;
    unordered_set<int> s;
    for (int num : arr)
    {
        s.insert(num);
    }
    for (int num : arr)
    {
        if (s.find(num - 1) != s.end())
            continue;
        int cnt = 0;
        while (s.find(num) != s.end())
        {
            num++;
            cnt++;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}