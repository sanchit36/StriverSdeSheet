#include <bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    if (grid.empty())
        return 0;
    int days = 0, tot = 0, cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
                tot++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if (!q.empty())
            days++;
    }
    return tot == cnt ? days : -1;
}