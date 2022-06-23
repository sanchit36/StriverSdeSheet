#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    int l = 0, r = n - 1;
    long leftMax = 0, rightMax = 0, res = 0;
    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] >= leftMax)
                leftMax = arr[l];
            else
                res += leftMax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] >= rightMax)
                rightMax = arr[r];
            else
                res += rightMax - arr[r];
            r--;
        }
    }
    return res;
}