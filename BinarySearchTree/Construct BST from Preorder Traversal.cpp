#include <bits/stdc++.h>
TreeNode<int> *buildTreeHelper(vector<int> &preorder, int& i, int bound)
{
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[i++]);
    root->left = buildTreeHelper(preorder, i, root->data);
    root->right = buildTreeHelper(preorder, i, bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preorder)
{
    int i = 0;
    return buildTreeHelper(preorder, i, INT_MAX);
}