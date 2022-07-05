#include <bits/stdc++.h>
using namespace std;

void f(int ind, string &s, vector<string> &ds)
{
    if (ind == s.size())
    {
        ds.push_back(s);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        swap(s[ind], s[i]);
        f(ind + 1, s, ds);
        swap(s[ind], s[i]);
    }
}

vector<string> findPermutations(string &s)
{
    vector<string> ds;
    f(0, s, ds);
    return ds;
}