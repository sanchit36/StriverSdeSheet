#include <bits/stdc++.h>

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            BinaryTreeNode<int> *node = it.first;
            int line = it.second;
            m[line] = node->data;
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
