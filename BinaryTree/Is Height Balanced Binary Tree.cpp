#include <bits/stdc++.h>

int height(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return 0;
    int l = height(node->left);
    if (l == -1)
        return -1;
    int r = height(node->right);
    if (r == -1)
        return -1;
    if (abs(r - l) > 1)
        return -1;
    return 1 + max(l, r);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return height(root) != -1;
}