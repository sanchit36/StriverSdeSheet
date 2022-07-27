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

int getMaxWidth(TreeNode<int> *root)
{
    int width = 0;
    if (root == NULL)
        return width;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        width = max(width, size);
        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return width;
}