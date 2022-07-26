#include <bits/stdc++.h>
using namespace std;

int findMinLen(vector<string> &arr)
{
    std::size_t minLen = arr[0].size();
    for (string str : arr)
    {
        minLen = min(minLen, str.size());
    }
    return minLen;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    int minLen = findMinLen(arr);
    string result;
    for (int i = 0; i < minLen; i++)
    {
        char current = arr[0][i];
        for (int j = 1; j < n; j++)
        {
            if (arr[j][i] != current)
                return result;
        }
        result.push_back(current);
    }
    return result;
}
