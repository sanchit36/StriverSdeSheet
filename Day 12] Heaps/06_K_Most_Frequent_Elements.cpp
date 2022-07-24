#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (auto i : arr)
        mp[i]++;

    priority_queue<pii> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}