#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> m;
    int XOR = 0;
    int cnt = 0;
    for (int it : arr)
    {
        XOR = XOR ^ it;
        if (XOR == x)
            cnt++;
        if (m.find(XOR ^ x) != m.end())
            cnt += m[XOR ^ x];
        m[XOR]++;
    }
    return cnt;
}