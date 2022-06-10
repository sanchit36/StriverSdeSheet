#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root)
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
            auto it = q.front();
            q.pop();
            TreeNode<int> *node = it.first;
            int line = it.second;
            if (m.find(line) == m.end())
            {
                m[line] = node->val;
            }
            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }
    }

    for (auto vpair : m)
    {
        ans.push_back(vpair.second);
    }
    return ans;
}