#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty())
        {
            ans.push_back(intervals[0]);
        }
        else
        {
            vector<int> &v = ans.back();
            int temp = v[1];
            if (intervals[i][0] <= temp)
            {
                v[1] = max(temp, intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
    }
    return ans;
}
