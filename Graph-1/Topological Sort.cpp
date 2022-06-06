#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        ans.push_back(f);

        for (int n : adj[f])
        {
            if (indegree[n] > 0)
            {
                indegree[n]--;
            }
            if (indegree[n] == 0)
            {
                q.push(n);
            }
        }
    }

    return ans;
}