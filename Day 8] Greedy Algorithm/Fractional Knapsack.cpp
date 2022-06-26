#include <bits/stdc++.h>

bool cmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), cmp);

    double profit = 0;
    for (auto item : items)
    {
        if (w >= item.first)
        {
            w -= item.first;
            profit += item.second;
        }
        else
        {
            profit += (double)w * ((double)item.second / (double)item.first);
            break;
        }
    }

    return profit;
}