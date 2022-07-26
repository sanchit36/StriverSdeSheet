#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> stringToNumber(string &a, int asize)
{
    vector<ll> ans;
    ll num = 0;
    for (int i = 0; i <= asize; i++)
    {
        if (a[i] == '.' || i == asize)
        {
            ans.push_back(num);
            num = 0;
        }
        else
        {
            num = (num * 10) + (a[i] - '0');
        }
    }
    return ans;
}

int compareVersions(string a, string b)
{
    ll asize = a.size();
    ll bsize = b.size();
    vector<ll> a1 = stringToNumber(a, asize), b1 = stringToNumber(b, bsize);

    ll temp = max(b1.size(), a1.size());
    ll valueA = 0, valueB = 0;

    for (ll i = 0; i < temp; i++)
    {
        valueA = valueB = 0;
        if (i < a1.size())
            valueA = a1[i];
        if (i < b1.size())
            valueB = b1[i];

        if (valueA > valueB)
            return 1;
        if (valueB > valueA)
            return -1;
    }
    return 0;
}