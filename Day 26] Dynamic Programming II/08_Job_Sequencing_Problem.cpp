#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int profit;
    int deadline;
};

bool cmp(Job &a, Job &b)
{
    return a.profit > b.profit;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    Job arr[n];
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        arr[i].id = i + 1;
        arr[i].deadline = jobs[i][0];
        arr[i].profit = jobs[i][1];
        maxi = max(maxi, arr[i].deadline);
    }
    sort(arr, arr + n, cmp);
    vector<int> slot(maxi + 1, -1);
    int countProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countProfit += arr[i].profit;
                break;
            }
        }
    }

    return countProfit;
}