#include <bits/stdc++.h>

vector<int> BFS(int n, vector<pair<int, int>> edges)
{
    vector<set<int>> adj(n);
    for (pair<int, int> p : edges)
    {
        adj[p.second].insert(p.first);
        adj[p.first].insert(p.second);
    }
    vector<bool> vis(n, false);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty())
            {
                int f = q.front();
                q.pop();
                ans.push_back(f);
                for (auto x : adj[f])
                {
                    if (!vis[x])
                    {
                        q.push(x);
                        vis[x] = true;
                    }
                }
            }
        }
    }
    return ans;
}