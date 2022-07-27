#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // Node and Level
    queue<pair<TreeNode<int> *, int>> q;
    // level -> node->data
    map<int, int> m;
    q.push({root, 0});
    m[0] = root->data;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            TreeNode<int> *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (m.find(level) == m.end())
                m[level] = node->data;
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
    }

    for (auto x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}