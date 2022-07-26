#include <bits/stdc++.h>
using namespace std;

string expand(int l, int r, string s)
{
    while (l >= 0 && r <= s.size())
    {
        if (s[l] != s[r])
        {
            break;
        }
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}
string longestPalinSubstring(string str)
{
    string longest;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        string odd = expand(i, i, str);
        if (odd.size() > longest.size())
        {
            longest = odd;
        }
    }
    for (int i = 0; i < n; i++)
    {
        string even = expand(i, i + 1, str);
        if (even.size() > longest.size())
        {
            longest = even;
        }
    }
    return longest;
}