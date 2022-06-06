void dfs(int row, int col, int **grid, int n, int m, vector<vector<bool>> &vis)
{
    if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || vis[row][col] == true)
    {
        return;
    }
    vis[row][col] = true;
    dfs(row - 1, col, grid, n, m, vis);
    dfs(row + 1, col, grid, n, m, vis);
    dfs(row, col - 1, grid, n, m, vis);
    dfs(row, col + 1, grid, n, m, vis);
    dfs(row - 1, col - 1, grid, n, m, vis);
    dfs(row - 1, col + 1, grid, n, m, vis);
    dfs(row + 1, col - 1, grid, n, m, vis);
    dfs(row + 1, col + 1, grid, n, m, vis);
}

int getTotalIslands(int **arr, int n, int m)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && arr[i][j] == 1)
            {
                count++;
                dfs(i, j, arr, n, m, vis);
            }
        }
    }
    return count;
}
