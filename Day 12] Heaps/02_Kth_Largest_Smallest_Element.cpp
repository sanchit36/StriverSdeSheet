#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    vector<int> res;
    res.push_back(arr[k - 1]);
    res.push_back(arr[n - k]);
    return res;
}