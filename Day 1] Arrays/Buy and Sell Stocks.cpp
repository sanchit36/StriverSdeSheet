#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mini = prices[0], maxi = INT_MIN;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] >= mini)
        {
            maxi = max(maxi, prices[i] - mini);
        }
        else
        {
            mini = prices[i];
        }
    }
    return maxi == INT_MIN ? 0 : maxi;
}