#include <bits/stdc++.h>
vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans;
    ans.push_back({1});
    if (n == 1)
        return ans;
    ans.push_back({1, 1});
    if (n == 2)
        return ans;
    for (int i = 2; i < n; i++)
    {
        vector<long long int> row;
        row.push_back(1);
        for (int j = 0; j < ans[i - 1].size() - 1; j++)
        {
            row.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
        }
        row.push_back(1);
        ans.push_back(row);
    }
    return ans;
}
