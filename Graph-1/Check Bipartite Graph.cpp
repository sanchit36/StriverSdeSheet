bool dfs(int node, int color, vector<vector<int>> &adj, vector<int> &col)
{
    col[node] = color;
    for (auto i : adj[node])
    {
        if (col[i] == -1)
        {
            if (dfs(i, 1 - color, adj, col) == false)
                return false;
        }
        else if (col[i] == color)
        {
            return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    int m = edges[0].size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color))
                return false;
        }
    }

    return true;
}