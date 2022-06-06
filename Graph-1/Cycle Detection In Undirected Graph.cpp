#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (auto n : adj[node])
    {
        if (!vis[n])
        {
            if (dfs(n, node, adj, vis))
                return true;
        }
        else if (n != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);

    for (vector<int> edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis))
                return "Yes";
        }
    }
    return "No";
}
