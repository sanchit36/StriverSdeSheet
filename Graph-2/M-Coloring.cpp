#include <bits/stdc++.h>

bool isSafe(int node, int col, vector<vector<int>> &adj, vector<int> &color)
{
    for (auto it : adj[node])
    {
        if (color[it] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>> &adj, vector<int> &color, int n, int m)
{
    if (node == n)
        return true;
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(node, col, adj, color))
        {
            color[node] = col;
            if (solve(node + 1, adj, color, n, m))
                return true;
            else
                color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<vector<int>> adj(n);
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
                adj[i].push_back(j);
        }
    }
    if (solve(0, adj, color, n, m))
        return "YES";
    return "NO";
}