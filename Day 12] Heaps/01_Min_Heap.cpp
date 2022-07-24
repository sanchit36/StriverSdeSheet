#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    void insert(int val)
    {
        pq.push_back(val);
        int CI = pq.size() - 1;
        while (CI > 0)
        {
            int PI = (CI - 1) / 2;
            if (pq[CI] < pq[PI])
                swap(pq[CI], pq[PI]);
            else
                break;
            CI = PI;
        }
    }
    int getMin()
    {
        if (pq.empty())
            return -1;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int PI = 0;
        int LCI = 2 * PI + 1;
        int RCI = 2 * PI + 2;

        while (LCI < pq.size())
        {
            int minIndex = PI;
            if (pq[LCI] < pq[minIndex])
            {
                minIndex = LCI;
            }
            if (pq[RCI] < pq[minIndex])
            {
                minIndex = RCI;
            }
            if (PI == minIndex)
                break;
            swap(pq[minIndex], pq[PI]);
            PI = minIndex;
            LCI = 2 * PI + 1;
            RCI = 2 * PI + 2;
        }

        return ans;
    }
};

vector<int> minHeap(int n, vector<vector<int>> &queries)
{
    vector<int> ans;
    PriorityQueue pq;
    for (auto q : queries)
    {
        switch (q[0])
        {
        case 0:
            pq.insert(q[1]);
            break;
        case 1:
            ans.push_back(pq.getMin());
            break;
        }
    }
    return ans;
}
