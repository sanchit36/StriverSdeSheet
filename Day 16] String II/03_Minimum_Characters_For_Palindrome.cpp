#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);
    int j = 0;
    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            { // j == 0, ie cant go back, so lps[i] = 0 and inc i
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minCharsforPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    string ns = s + '$' + rev;
    vector<int> lps = buildLPS(ns);
    return s.size() - lps.back();
}
