#include <bits/stdc++.h>

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent), v = findParent(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    sort(graph.begin(), graph.end(), comp);
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int cost = 0;
    for (auto it : graph)
    {
        if (findParent(it[0], parent) != findParent(it[1], parent))
        {
            cost += it[2];
            union_set(it[0], it[1], parent, rank);
        }
    }
    return cost;
}