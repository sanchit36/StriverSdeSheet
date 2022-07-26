#include <bits/stdc++.h>
using namespace std;

/**
 * Compute PI array to maintain size of suffix which is same as prefix
 * Time/space complexity is O(size of pattern)
 */
vector<int> buildPiArray(string &p)
{
    int n = p.size();
    vector<int> lps(n);
    lps[0] = 0;
    int j = 0;
    for (int i = 1; i < n;)
    {
        if (p[j] == p[i])
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
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

/**
 * KMP algorithm of pattern matching.
 * TC: O(M+N)
 */
bool findPattern(string p, string s)
{
    vector<int> lps = buildPiArray(p);
    int i = 0;
    int j = 0;
    while (i < s.size() && j < p.size())
    {
        if (s[i] == p[j])
        {
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
            {
                i++;
            }
        }
    }
    if (j == p.size())
    {
        return true;
    }
    return false;
}

int main()
{
    string str = "abcxabcdabcdabcy";
    string subString = "abcdabcy";
    cout << findPattern(subString, str) << endl;
    return 0;
}
