#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int plat = 1;
    int maxi = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        maxi = max(maxi, plat);
    }

    return maxi;
}