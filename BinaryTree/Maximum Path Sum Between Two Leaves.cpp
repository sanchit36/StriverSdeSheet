
long long int solve(TreeNode<int> *root, long long int &maxi, int &lc)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        lc++;
    long long int l = solve(root->left, maxi, lc);
    long long int r = solve(root->right, maxi, lc);
    maxi = max(maxi, l + r + root->val);
    return root->val + max(l, r);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if (root == NULL)
        return -1;
    long long int maxi = 0;
    int lc = 0; // number of leaves
    solve(root, maxi, lc);
    // if # of leaves if less the 2 return -1
    if (lc == 0 || lc == 1)
        return -1;
    return maxi;
}