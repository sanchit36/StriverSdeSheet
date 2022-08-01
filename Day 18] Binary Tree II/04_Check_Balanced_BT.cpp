// Balanced Binary means that abs(leftHeight - rightHeight) <= 1

int helper(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = helper(root->left);
    if (lh == -1)
        return -1;
    int rh = helper(root->right);
    if (rhs == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

bool isBalancedBT(TreeNode *root)
{
    return helper(root) != -1;
}
