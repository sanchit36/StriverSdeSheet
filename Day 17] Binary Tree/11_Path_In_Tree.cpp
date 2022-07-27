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

bool preOrder(TreeNode<int> *root, int x, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);
    if (root->data == x)
        return true;
    if (preOrder(root->left, x, path) || preOrder(root->right, x, path))
        return true;
    path.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;
    preOrder(root, x, path);
    return path;
}