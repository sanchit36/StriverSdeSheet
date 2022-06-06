#include <bits/stdc++.h>

void dfs(int node, vector<set<int>> &adj, vector<bool> &vis, vector<int> &cur)
{
    vis[node] = true;
    cur.push_back(node);
    for (auto i : adj[node])
    {
        if (!vis[i])
            dfs(i, adj, vis, cur);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<set<int>> adj(V);
    vector<bool> vis(V, false);
    vector<vector<int>> ans;
    for (auto x : edges)
    {
        adj[x[0]].insert(x[1]);
        adj[x[1]].insert(x[0]);
    }
    int con = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> cur;
            con++;
            dfs(i, adj, vis, cur);
            ans.push_back(cur);
        }
    }
    return ans;
}