#include <bits/stdc++.h>

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (m.find(level) == m.end())
                m[level] = node->data;
            if (node->right)
                q.push({node->right, level + 1});
            if (node->left)
                q.push({node->left, level + 1});
        }
    }
    for (auto p : m)
    {
        ans.push_back(p.second);
    }
    return ans;
}