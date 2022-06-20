// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> p;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            p.first = i;
        }
        if (freq[i] == 2)
        {
            p.second = i;
        }
    }
    return p;
}
