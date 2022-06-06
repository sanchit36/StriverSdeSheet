#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int s)
{
    vector<vector<pair<int, int>>> adj(v);
    for (auto x : vec)
    {
        adj[x[0]].push_back({x[2], x[1]});
        adj[x[1]].push_back({x[2], x[0]});
    }
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>>
        q;
    vector<int> dis(v, INT_MAX);
    q.push({0, s});
    dis[s] = 0;

    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();

        for (auto i : adj[u])
        {
            int v = i.second;
            int wt = i.first;

            if (dis[v] > dis[u] + wt)
            {
                dis[v] = dis[u] + wt;
                q.push({dis[v], v});
            }
        }
    }
}
