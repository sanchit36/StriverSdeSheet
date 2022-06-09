#include <bits/stdc++.h>
int solve(TreeNode<int> *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left, maxi);
    int r = solve(root->right, maxi);
    maxi = max(maxi, l + r);
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = 0;
    solve(root, maxi);
    return maxi;
}
