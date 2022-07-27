#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto it = q.front();
            q.pop();
            BinaryTreeNode<int> *node = it.first;
            int vertical = it.second;
            m[vertical] = node->data;
            if (node->left)
                q.push({node->left, vertical - 1});
            if (node->right)
                q.push({node->right, vertical + 1});
        }
    }

    for (auto x : m)
    {
        ans.push_back(x.second);
    }

    return ans;
}