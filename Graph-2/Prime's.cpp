#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)

{

   vector<pair<int,int>> adj[n+1];

    for(auto it:g)
    {
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> parent(n+1,-1);
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[1]=0;
    parent[1]=-1;
    pq.push({0,1});
    for(int i=0;i<n-1;i++)
    {
        int u = pq.top().second;
        pq.pop();
         mst[u]=true;
         for(auto it:adj[u])
         {
              int first=it.first;
              int weight=it.second;
              if(mst[first]==false and weight<key[first])
              {

                   key[first]=weight;
                   parent[first]=u;
                   pq.push({key[first], first});
              }
         }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=1;i<=n;i++)
    {
         if(parent[i]!=-1)
             ans.push_back({{i,parent[i]},key[i]});
    }
    return ans;
}