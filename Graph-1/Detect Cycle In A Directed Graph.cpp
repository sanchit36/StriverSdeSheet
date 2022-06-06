bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &dfsVis)
{
    vis[node] = true;
    dfsVis[node] = true;

    for (auto n : adj[node])
    {
        if (!vis[n])
        {
            if (dfs(n, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[n])
        {
            return true;
        }
    }
    dfsVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<bool> dfsVis(n + 1, false);

    for (pair<int, int> p : edges)
    {
        adj[p.first].push_back(p.second);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(i, adj, vis, dfsVis))
            return 1;
    }

    return 0;
}