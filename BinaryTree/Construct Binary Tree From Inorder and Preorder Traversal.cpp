#include <bits/stdc++.h>
TreeNode<int> *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                               vector<int> &inorder, int inStart, int inEnd, map<int, int> &m)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int inRoot = m[root->data];
    int numsLeft = inRoot - inStart;
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = preorder.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1, m);
}
