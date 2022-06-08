#include <bits/stdc++.h>
#define INF 1000000000

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (auto e : edges)
    {
        dist[e[0]][e[1]] = e[2];
    }
    int num = n + 1;
    while (num--)
    {
        dist[num][num] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[src][dest];
}