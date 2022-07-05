#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
    int start;
    int end;
    int pos;
};

bool cmp(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    Meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;
    }
    sort(meet, meet + n, cmp);
    vector<int> ans;
    int ending = meet[0].end;
    ans.push_back(meet[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > ending)
        {
            ending = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}