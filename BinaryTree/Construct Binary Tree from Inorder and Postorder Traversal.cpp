#include <bits/stdc++.h>
TreeNode<int> *buildTreeHelper(vector<int> &postorder, int postStart, int postEnd,
                               vector<int> &inorder, int inStart, int inEnd, map<int, int> &m)
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);
    int inRoot = m[root->data];
    int numsRight = inEnd - inRoot;
    root->right = buildTreeHelper(postorder, postEnd - numsRight, postEnd - 1, inorder, inRoot + 1, inEnd, m);
    root->left = buildTreeHelper(postorder, postStart, postEnd - numsRight - 1, inorder, inStart, inRoot - 1, m);
    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
{
    int n = postorder.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
    return buildTreeHelper(postorder, 0, n - 1, inorder, 0, n - 1, m);
}
