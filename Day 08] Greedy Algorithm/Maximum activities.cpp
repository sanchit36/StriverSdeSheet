#include <bits/stdc++.h>
struct Activity
{
    int s;
    int e;
    int p;
};

bool cmp(Activity a, Activity b)
{
    if (a.e < b.e)
        return true;
    else if (a.e > b.e)
        return false;
    else if (a.p > b.p)
        return true;
    else
        return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    Activity act[n];
    for (int i = 0; i < n; i++)
    {
        act[i].s = start[i], act[i].e = finish[i], act[i].p = i + 1;
    }
    sort(act, act + n, cmp);
    int maxi = 1;
    int ending = act[0].e;
    for (int i = 1; i < n; i++)
    {
        if (act[i].s >= ending)
        {
            ending = act[i].e;
            maxi++;
        }
    }
    return maxi;
}