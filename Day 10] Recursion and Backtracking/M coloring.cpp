#include <bits/stdc++.h>
using namespace std;

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
            color[node] = 0;
        }
    }
    return false;
}
