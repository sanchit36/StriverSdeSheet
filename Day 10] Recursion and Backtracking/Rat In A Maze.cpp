#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &vis, vector<vector<int>> &maze, vector<vector<int>> &ds)
{
    if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 || vis[i][j] == 1)
        return;
    vis[i][j] = 1;
    if (i == n - 1 && j == n - 1)
    {
        vector<int> row;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row.push_back(vis[i][j]);
            }
        }
        ds.push_back(row);
        vis[i][j] = 0;
        return;
    }
    solve(i - 1, j, n, vis, maze, ds);
    solve(i, j - 1, n, vis, maze, ds);
    solve(i + 1, j, n, vis, maze, ds);
    solve(i, j + 1, n, vis, maze, ds);
    vis[i][j] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<vector<int>> ds;
    solve(0, 0, n, vis, maze, ds);
    return ds;
}